# Install script for directory: /home/jason.b/Desktop/Github/NICE/shogun-4.1.0/examples/undocumented/libshogun

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libshogun-examples")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/shogun/examples/libshogun" TYPE PROGRAM FILES
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/basic_minimal"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_multiclass_ecoc_discriminant"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_parameter_combination_test"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_neighborhoodpreservingembedding"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/neuralnets_convolutional"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/features_copy_subset_sparse_features"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_jade_bss"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/features_dense_real_modular"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/evaluation_cross_validation_multiclass_mkl"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_combined_kernel_sub_parameters"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_model_selection_parameters_test"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_featureblocklogisticregression"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_diffusionmaps"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_parameter_tree"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/evaluation_cross_validation_multiclass"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_multidimensionalscaling"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/kernel_machine_train_locked"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_svmlight_string_features_precomputed_kernel"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_localitypreservingprojections"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_libsvm_probabilities"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/evaluation_cross_validation_classification"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_kernellocallylinearembedding"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_gaussian_process_fitc"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_dyn_int"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/splitting_stratified_crossvalidation"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_multiclass_ecoc"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_circularbuffer"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/features_subset_labels"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/features_subset_simple_features"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/kernel_custom_index"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_factoranalysis"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/serialization_basic_tests"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_knn"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/streaming_from_dense"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_isomap"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/evaluation_cross_validation_locked_comparison"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_linearlocaltangentspacealignment"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/evaluation_cross_validation_regression"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_multiclass_prob_heuristics"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/kernel_gaussian"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_gaussiannaivebayes"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_gaussian_process_binary_classification"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_multiclasslibsvm"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_indirect_object"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_serialization"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_mldatahdf5"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/transfer_multitaskleastsquaresregression"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/transfer_multitasklogisticregression"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/neuralnets_deep_belief_network"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/parameter_iterate_sgobject"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/kernel_custom"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_locallylinearembedding"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_grid_search_multiclass_svm"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_qda"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/features_subset_stack"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_libsvm"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/so_factorgraph"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/statistics_linear_time_mmd"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_hdf5"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/io_linereader"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/splitting_standard_crossvalidation"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/parameter_modsel_parameters"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_grid_search_mkl"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/balanced_conditional_probability_tree"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_laplacianeigenmaps"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/neuralnets_deep_autoencoder"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/statistics"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/parameter_set_from_parameters"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_localtangentspacealignment"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_gaussian_process_product"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_gaussian_process_simple_exact"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/serialization_multiclass_labels"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_hessianlocallylinearembedding"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/mathematics_lapack"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/io_libsvm_multilabel"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_gc_array"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_apply_parameter_tree"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/evaluation_cross_validation_mkl_weight_storage"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/clustering_kmeans"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/features_copy_subset_simple_features"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_gaussian_process_sum"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_grid_search_linear"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/streaming_onlineliblinear_dense"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/statistics_mmd_kernel_selection"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_lda"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_hash"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_grid_search_kernel"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_mkl_svmlight_modelselection_bug"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_map"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/modelselection_grid_search_string_kernel"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/statistics_hsic"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_gaussian_process_ard"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/converter_stochasticproximityembedding"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_libsvr"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/variational_approx_example"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/mathematics_confidence_intervals"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/statistics_quadratic_time_mmd"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_multiclasslinearmachine"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/streaming_onlineliblinear_sparse"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_gaussian_process_laplace"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_minimal_svm"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/labels_binary_fit_sigmoid"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/so_multiclass_BMRM"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/regression_gaussian_process_gaussian"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/so_fg_multilabel"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/neuralnets_basic"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_multiclass_ecoc_random"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/library_set"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/kernel_revlin"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/classifier_mklmulticlass"
    "/home/jason.b/Desktop/Github/NICE/shogun-4.1.0/cmake/examples/undocumented/libshogun/parameter_iterate_float64"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libshogun-examples")

