/*
* cross compile code c++ 1.0
* mrseakg@gmail.com 2012 september 
*
*/

#ifndef _CCCSTRING_
#define _CCCSTRING_

#include "cccVar.h"
#include "cccString_Container.h"

class cccString : public cccVar
{
	public:
		cccString() { m_t = String_Init(m_t); };
		cccString(const CCCSTRING& t) { m_t = String_Init(m_t, t); };
		cccString(CCCSTRING& t) { m_t = String_Init(m_t, t); };
		cccInt Length() { return String_Length(m_t); };
		// virtual void PushToStream(cccStream &strm) { String_PushToStream(strm, m_t); };
		
		virtual void operator + (cccVar& var) {};
		virtual void operator ++ () {};
		virtual void operator - () {};

	private:
		CCCSTRING m_t;
};

#endif
