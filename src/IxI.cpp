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

#include "IxI.hpp"
#include "Log.hpp"

namespace ix
{

void CIxI::startThreads()
{
    m_socketThread = boost::thread(&CIxI::socketThreadFunc, this);

}


void CIxI::socketThreadFunc()
{
    TRACE( "Thread running" );

    boost::posix_time::milliseconds workTime(3000);

    while ( true )
    {
        TRACE( "within thread" );
        boost::this_thread::sleep(workTime);        
    }

}






}; // namespace ix
