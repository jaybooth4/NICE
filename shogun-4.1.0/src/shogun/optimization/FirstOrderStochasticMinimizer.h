/*
 * Copyright (c) The Shogun Machine Learning Toolbox
 * Written (w) 2015 Wu Lin
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are those
 * of the authors and should not be interpreted as representing official policies,
 * either expressed or implied, of the Shogun Development Team.
 *
 */
#ifndef FIRSTORDERSTOCHASTICMINIMIZER_H
#define FIRSTORDERSTOCHASTICMINIMIZER_H
#include <shogun/optimization/FirstOrderMinimizer.h>
#include <shogun/optimization/FirstOrderStochasticCostFunction.h>
#include <shogun/optimization/DescendUpdater.h>
#include <shogun/optimization/LearningRate.h>
#include <shogun/optimization/SparsePenalty.h>
#include <shogun/optimization/ProximalPenalty.h>
namespace shogun
{

/** @brief The base class for stochastic first-order gradient-based minimizers.
 *
 * This class gives the interface of these stochastic minimizers.
 *
 * A stochastic minimizer is used to minimize
 * a cost function \f$f(w)\f$ which can be written as a (finite) sum of differentiable functions, \f$f_i(w)\f$.
 * (eg, FirstOrderStochasticCostFunction)
 * For example,
 * \f[
 * f(w)=\sum_i{ f_i(w) }
 * \f]
 * Note that we call these differentiable functions \f$f_i(w)\f$ as sample functions.
 *
 * This kind of minimizers will find optimal target variables based on gradient information wrt target variables.
 * FirstOrderStochasticMinimizer uses a sample gradient (eg, FirstOrderStochasticCostFunction::get_gradient() )
 * \f$\frac{\partial f_i(w) }{\partial w}\f$ to find optimal target variables,
 * where the index \f$i\f$ is generated by some distribution (eg, FirstOrderStochasticCostFunction::next_sample() ).
 *
 * Note that FirstOrderMinimizer uses the exact gradient, (eg, FirstOrderCostFunction::get_gradient() ),
 * \f$\frac{\partial f(w) }{\partial w}\f$. 
 *
 * For example,  least sqaures cost function
 * \f[
 * f(w)=\sum_i{ (y_i-w^T x_i)^2 }
 * \f]
 * If we let \f$f_i(w)=(y_i-w^T x_i)^2 \f$, \f$f(w)\f$ can be written as \f$f(w)=\sum_i{ f_i(w) }\f$.
 * Note that \f$f_i(w)\f$ is a sample function for the i-th sample, \f$(x_i,y_i)\f$.
 *
 */
class FirstOrderStochasticMinimizer: public FirstOrderMinimizer
{
public:
	/** Default constructor */
	FirstOrderStochasticMinimizer()
		:FirstOrderMinimizer()
	{
		init();
	}

	/** Constructor
	 * @param fun stochastic cost function
	 */
	FirstOrderStochasticMinimizer(FirstOrderStochasticCostFunction *fun)
		:FirstOrderMinimizer(fun)
	{
		init();
	}

	/** Destructor
	 */
	virtual ~FirstOrderStochasticMinimizer(){}

	/** Does minimizer support batch update
	 * 
	 * @return whether minimizer supports batch update
	 */
	virtual bool supports_batch_update() const {return false;}

	/** Set a gradient updater
	 *
	 * @param gradient_updater the gradient_updater
	 */
	virtual void set_gradient_updater(DescendUpdater* gradient_updater)
	{
		REQUIRE(gradient_updater, "Gradient updater must set\n");
		m_gradient_updater=gradient_updater;
	}

	/** Do minimization and get the optimal value 
	 * 
	 * @return optimal value
	 */
	virtual float64_t minimize()=0;

	/** Set the number of times to go through all data points (samples)
	 * For example, num_passes=1 means go through all data points once.
	 *
	 * Recall that
	 * a stochastic cost function \f$f(w)\f$ can be written as \f$\sum_i{ f_i(w) }\f$,
	 * where \f$f_i(w)\f$ is the differentiable function for the i-th sample.
	 *
	 * @param num_passes the number of times 
	 */
	virtual void set_number_passes(int32_t num_passes)
	{
		REQUIRE(num_passes>0, "The number (%d) to go through data must be positive\n", num_passes);
		m_num_passes=num_passes;
	}

	/** Load the given context object to restores mutable variables
	 * Usually it is used in deserialization.
	 *
	 * @param context a context object
	 */
	virtual void load_from_context(CMinimizerContext* context)
	{
		REQUIRE(context,"Context must set\n");
		REQUIRE(m_gradient_updater,"Descend updater must set\n");
		FirstOrderMinimizer::load_from_context(context);
		m_gradient_updater->load_from_context(context);
		if(m_learning_rate)
			m_learning_rate->load_from_context(context);
		std::string key="FirstOrderStochasticMinimizer::m_iter_counter";
		m_iter_counter=context->get_data_int32(key);
	}

	/** Set the learning rate of a minimizer
	 * @param learning_rate learn rate or step size
	 */
	virtual void set_learning_rate(LearningRate *learning_rate)
	{
		m_learning_rate=learning_rate;
	}

	/** How many samples/mini-batch does the minimizer use?
	 *
	 * @return the number of samples/mini-batches used in optimization
	 */
	virtual int32_t get_iteration_counter() {return m_iter_counter;}
protected:
	/** Do proximal update in place 
	 *
	 * @param variable_reference variable_reference to be updated
	 *
	 */
	virtual void do_proximal_operation(SGVector<float64_t>variable_reference)
	{
		ProximalPenalty* proximal_penalty=dynamic_cast<ProximalPenalty*>(m_penalty_type);
		if(proximal_penalty)
		{
			float64_t proximal_weight=m_penalty_weight;
			SparsePenalty* sparse_penalty=dynamic_cast<SparsePenalty*>(m_penalty_type);
			if(sparse_penalty)
			{
				REQUIRE(m_learning_rate, "Learning rate must set when Sparse Penalty (eg, L1) is used\n");
				proximal_weight*=m_learning_rate->get_learning_rate(m_iter_counter);
			}
			proximal_penalty->update_variable_for_proximity(variable_reference,proximal_weight);
		}
	}

	/** Update a context object to store mutable variables
	 *
	 * @param context a context object
	 */
	virtual void update_context(CMinimizerContext* context)
	{
		REQUIRE(context,"Context must set\n");
		REQUIRE(m_gradient_updater,"Descend updater must set\n");
		FirstOrderMinimizer::update_context(context);
		m_gradient_updater->update_context(context);
		if(m_learning_rate)
			m_learning_rate->update_context(context);
		std::string key="FirstOrderStochasticMinimizer::m_iter_counter";
		context->save_data(key, m_iter_counter);
	}

	/** the gradient update step */
	DescendUpdater* m_gradient_updater;

	/** init the minimization process*/
	virtual void init_minimization()
	{
		REQUIRE(m_fun,"Cost function must set\n");
		REQUIRE(m_gradient_updater,"Descend updater must set\n");
		REQUIRE(m_num_passes>0, "The number to go through data must set\n");
		m_cur_passes=0;
	}

	/**  iteration to go through data */
	int32_t m_num_passes;

	/**  current iteration to go through data */
	int32_t m_cur_passes;

	/**  number of used samples/mini-batches */
	int32_t m_iter_counter;

	/** learning_rate object */
	LearningRate* m_learning_rate;
	
private:
	/** Init */
	void init()
	{
		m_gradient_updater=NULL;
		m_learning_rate=NULL;
		m_num_passes=0;
		m_cur_passes=0;
		m_iter_counter=0;
	}
};

}
#endif /* FIRSTORDERSTOCHASTICMINIMIZER_H */
