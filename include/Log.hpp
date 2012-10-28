/*
 * =====================================================================================
 *
 *       Filename:  IxI.cpp
 *
 *    Description:  IxI
 *
 *        Version:  1.0
 *        Created:  28/10/12 16:42:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Raj Panesar (), raj.panesar@xiltec.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef __IX_LOG_H__
#define __IX_LOG_H__

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdarg>
#include <sstream>

#ifdef NO_TRACE
#define TRACE( fmt, ... )
#else
#define TRACE( fmt, ... ) ix::ixLog( "TRC", __FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__ )
#endif

#ifdef NO_WARN
#define WARN( fmt, ... )
#else
#define WARN( fmt, ... ) ix::ixLog( "WRN", __FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__ )
#endif

#define INFO( fmt, ... ) ix::ixLog( "INF", __FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__ )
#define ERROR( fmt, ... ) ix::ixLog( "ERR", __FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__ )
#define FATAL( fmt, ... ) ix::ixLog( "FTL", __FILE__, __LINE__, __FUNCTION__, fmt, ##__VA_ARGS__ )
//#define LOG_TO_STDERR

namespace ix
{

static const char *monthList[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
static pthread_mutex_t logMutex =  PTHREAD_MUTEX_INITIALIZER;

inline void ixLog( const char* mode, const char* file, int line, const char* func, const char* fmt, ... )
{
	pthread_mutex_lock( &logMutex );
	const int bufLen = 1024;
	static char tbuf[32];	// time
	time_t t = time(NULL);
	struct tm now;
	localtime_r( &t, &now );
	snprintf( tbuf, 32, "%s %02d %02d:%02d:%02d %s:",
		monthList[now.tm_mon], now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec, mode );
	va_list argList;
	static char cbuffer[bufLen];
	va_start( argList, fmt );
	vsnprintf( cbuffer, bufLen, fmt, argList );
	va_end( argList );
#ifdef LOG_TO_STDERR
	std::cerr << tbuf << " " << file << " [" << line << "] " << func << "(): " << cbuffer << std::endl;
#else
	std::cout << tbuf << " " << file << " [" << line << "] " << func << "(): " << cbuffer << std::endl;
#endif
	pthread_mutex_unlock( &logMutex );
}

};	// namespace ix

#endif	// __IX_LOG_H__
