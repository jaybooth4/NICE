/*
  The contents of this file are dedicated by all of its authors, including

    Michael S. Gashler,
    Eric Moyer,
    anonymous contributors,

  to the public domain (http://creativecommons.org/publicdomain/zero/1.0/).

  Note that some moral obligations still exist in the absence of legal ones.
  For example, it would still be dishonest to deliberately misrepresent the
  origin of a work. Although we impose no legal requirements to obtain a
  license, it is beseeming for those who build on the works of others to
  give back useful improvements, or find a way to pay it forward. If
  you would like to cite us, a published paper about Waffles can be found
  at http://jmlr.org/papers/volume12/gashler11a/gashler11a.pdf. If you find
  our code to be useful, the Waffles team would love to hear how you use it.
*/

#include "GBitTable.h"
#include "GError.h"
#include <string.h> // (for memset)
#include "GRand.h"

using namespace GClasses;

#define BLOCK_BITS (sizeof(size_t) * 8)


GBitTable::GBitTable(size_t bitCount)
  :m_size((bitCount + BLOCK_BITS - 1) / BLOCK_BITS),
   m_pBits(new size_t[m_size])
{
	memset(m_pBits, '\0', sizeof(size_t) * m_size);
}

GBitTable::GBitTable(const GBitTable&o)
  :m_size(o.m_size), m_pBits(new size_t[m_size])
{
	memcpy(m_pBits, o.m_pBits, sizeof(size_t) * m_size);
}

GBitTable& GBitTable::operator=(const GBitTable& o)
{
	delete[] m_pBits;
	m_size = o.m_size;
	m_pBits = new size_t[m_size];
	memcpy(m_pBits, o.m_pBits, sizeof(size_t) * m_size);
	return *this;
}


GBitTable::~GBitTable()
{
	delete[] m_pBits;
}

void GBitTable::clearAll()
{
	memset(m_pBits, '\0', sizeof(size_t) * m_size);
}

void GBitTable::setAll()
{
	memset(m_pBits, 255, sizeof(size_t) * m_size);
}

bool GBitTable::bit(size_t index)
{
	GAssert(index < m_size * BLOCK_BITS); // out of range
	size_t n = m_pBits[index / BLOCK_BITS];
	size_t m = index & (BLOCK_BITS - 1);
	return ((n & ((size_t)1 << m)) ? true : false);
}

void GBitTable::set(size_t index)
{
	GAssert(index < m_size * BLOCK_BITS); // out of range
	size_t m = index & (BLOCK_BITS - 1);
	m_pBits[index / BLOCK_BITS] |= ((size_t)1 << m);
}

void GBitTable::unset(size_t index)
{
	GAssert(index < m_size * BLOCK_BITS); // out of range
	size_t m = index & (BLOCK_BITS - 1);
	m_pBits[index / BLOCK_BITS] &= (~((size_t)1 << m));
}

void GBitTable::toggle(size_t index)
{
	GAssert(index < m_size * BLOCK_BITS); // out of range
	size_t m = index & (BLOCK_BITS - 1);
	m_pBits[index / BLOCK_BITS] ^= ((size_t)1 << m);
}

bool GBitTable::equals(GBitTable* that)
{
	if(this->m_size != that->m_size)
		return false;
	for(size_t i = 0; i < m_size; i++)
	{
		if(this->m_pBits[i] != that->m_pBits[i])
			return false;
	}
	return true;
}

bool GBitTable::areAllSet(size_t count)
{
	size_t head = count / BLOCK_BITS;
	size_t tail = count % BLOCK_BITS;
	size_t* pBits = m_pBits;
	for(size_t i = 0; i < head; i++)
	{
		if(*(pBits++) != ~((size_t)0))
			return false;
	}
	if(tail > 0)
	{
		if((*pBits | ~((((size_t)1) << tail) - 1)) != ~((size_t)0))
			return false;
	}
	return true;
}

bool GBitTable::areAllClear(size_t count)
{
	size_t head = count / BLOCK_BITS;
	size_t tail = count % BLOCK_BITS;
	size_t* pBits = m_pBits;
	for(size_t i = 0; i < head; i++)
	{
		if(*(pBits++) != (size_t)0)
			return false;
	}
	if(tail > 0)
	{
		if((*pBits & ((((size_t)1) << tail) - 1)) != (size_t)0)
			return false;
	}
	return true;
}

#ifndef MIN_PREDICT
#define TEST_SIZE 2080
// static
void GBitTable::test()
{
	GRand prng(0);
	bool arr[TEST_SIZE];
	for(size_t i = 0; i < TEST_SIZE; i++)
		arr[i] = false;
	GBitTable bt(TEST_SIZE);
	for(size_t i = 0; i < TEST_SIZE; i++)
	{
		size_t n = (size_t)prng.next(TEST_SIZE);
		bt.toggle(n);
		arr[n] = !arr[n];
		n = (size_t)prng.next(TEST_SIZE);
		bool b = (prng.next(2) == 0 ? false : true);
		arr[n] = b;
		if(b)
			bt.set(n);
		else
			bt.unset(n);
	}
	for(size_t i = 0; i < TEST_SIZE; i++)
	{
		if(bt.bit(i) != arr[i])
			throw Ex("failed");
	}

	GBitTable bt2(81);
	if(!bt2.areAllClear(81))
		throw Ex("failed");
	bt2.set(80);
	if(bt2.areAllClear(81))
		throw Ex("failed");
	if(!bt2.areAllClear(80))
		throw Ex("failed");
	for(size_t i = 0; i < 79; i++)
		bt2.set(i);
	if(bt2.areAllSet(81))
		throw Ex("failed");
	bt2.set(79);
	if(!bt2.areAllSet(81))
		throw Ex("failed");
}
#endif  // MIN_PREDICT
