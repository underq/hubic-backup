/*************************************************************************/
/* hubic-backup - an fast and easy to use hubic backup CLI tool          */
/* Copyright (c) 2015 Franck Chopin.                                     */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#pragma once

#include "common.h"

//- /////////////////////////////////////////////////////////////////////////////////////////////////////////

class CCurlLibrary
{
public:
	CCurlLibrary();
	virtual ~CCurlLibrary();
};

//- /////////////////////////////////////////////////////////////////////////////////////////////////////////

class CCurl
{
public:
	CCurl();
	virtual ~CCurl();
	operator CURL *() const { return _p; }
	void reset( ) const { assert( _p); curl_easy_reset(_p); }


public:
	template<typename T> CURLcode setopt(CURLoption option, T v) const { assert(_p); return curl_easy_setopt(_p, option, v); }
	CURLcode perform() const { assert(_p); return curl_easy_perform(_p); }
	CURLcode perform(std::string & response) const;

public:
	std::string escapeString( const std::string & src) const;
	bf::path escapePath(const bf::path & path) const;

public:
	static size_t wfString(void *ptr, size_t size, size_t nmemb, std::string * s);
	
private:
	CURL * _p;
};


