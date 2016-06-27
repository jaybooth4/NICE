/*
  The contents of this file are dedicated by all of its authors, including

    Michael S. Gashler,
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

#include "GHtml.h"
#include "GHashTable.h"

using namespace GClasses;

GHtml::GHtml(const char* pDoc, size_t nSize)
{
	m_pDoc = pDoc;
	m_nSize = nSize;
	m_nPos = 0;
}

GHtml::~GHtml()
{
}

void GHtml::parseTag()
{
	// Parse the tag name
	m_nPos++;
	while(m_pDoc[m_nPos] <= ' ' && m_nPos < m_nSize)
		m_nPos++;
	size_t nTagStart = m_nPos;
	while(m_pDoc[m_nPos] > ' ' && m_pDoc[m_nPos] != '>' && m_nPos < m_nSize)
		m_nPos++;
	size_t nTagNameLen = m_nPos - nTagStart;

	// Handle comment tags
	if(nTagNameLen >= 3 && strncmp(m_pDoc + nTagStart, "!--", 3) == 0)
	{
		// Find the end of the comment--todo: this isn't quite right
		while(m_nPos < m_nSize && m_pDoc[m_nPos] != '>')
			m_nPos++;

		// Handle the comment
		onComment(&m_pDoc[nTagStart + 3], m_nPos - nTagStart - 5);

		// Advance past the '>'
		if(m_nPos < m_nSize)
			m_nPos++;

		// Eat whitespace
		while(m_nPos < m_nSize && m_pDoc[m_nPos] <= ' ')
			m_nPos++;
		return;
	}

	// Handle the tag
	onTag(&m_pDoc[nTagStart], nTagNameLen);

	// Eat whitespace
	while(m_nPos < m_nSize && m_pDoc[m_nPos] <= ' ')
		m_nPos++;

	// Handle the params
	size_t nParamStart, nParamLen, nValueStart, nValueLen;
	while(m_pDoc[m_nPos] != '>' && m_nPos < m_nSize)
	{
		// Find the equals
		nParamStart = m_nPos;
		while(m_pDoc[m_nPos] != '=' && m_pDoc[m_nPos] != '>' && m_nPos < m_nSize)
			m_nPos++;
		nParamLen = m_nPos - nParamStart;
		m_nPos++;

		// Eat whitespace
		while(m_nPos < m_nSize && m_pDoc[m_nPos] <= ' ')
			m_nPos++;

		if(m_pDoc[m_nPos] == '"')
		{
			// Move past the '"'
			m_nPos++;
			nValueStart = m_nPos;

			// Find the close quote
			while(m_nPos < m_nSize && m_pDoc[m_nPos] != '"')
				m_nPos++;
			if(m_nPos >= m_nSize)
				break;
			nValueLen = m_nPos - nValueStart;
			m_nPos++;
		}
		else
		{
			// Move until we hit whitespace again
			nValueStart = m_nPos;
			while(m_nPos < m_nSize && m_pDoc[m_nPos] > ' ' && m_pDoc[m_nPos] != '>')
				m_nPos++;
			nValueLen = m_nPos - nValueStart;
		}

		// Handle the parameter
		onTagParam(&m_pDoc[nTagStart], nTagNameLen, &m_pDoc[nParamStart], nParamLen, &m_pDoc[nValueStart], nValueLen);

		// Eat whitespace
		while(m_nPos < m_nSize && m_pDoc[m_nPos] <= ' ')
			m_nPos++;
	}

	// Advance past the '>'
	if(m_nPos < m_nSize)
	{
		GAssert(m_pDoc[m_nPos] == '>');
		m_nPos++;
	}

	// Eat whitespace
	while(m_nPos < m_nSize && m_pDoc[m_nPos] <= ' ')
		m_nPos++;
}

bool GHtml::parseSomeMore()
{
	if(m_nPos >= m_nSize)
		return false;
	if(m_pDoc[m_nPos] == '<')
		parseTag();
	else
	{
		size_t nChunkStart = m_nPos;
		m_nPos++;
		while(m_nPos < m_nSize && m_pDoc[m_nPos] != '<')
			m_nPos++;
		onTextChunk(&m_pDoc[nChunkStart], m_nPos - nChunkStart);
	}
	return true;
}
