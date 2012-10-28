/*
 * =====================================================================================
 *
 *       Filename:  IxI.hpp
 *
 *    Description:  IxI header file
 *
 *        Version:  1.0
 *        Created:  28/10/12 16:44:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Raj Panesar (), raj.panesar@xiltec.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef IXI_HPP
#define IXI_HPP

#include <boost/thread.hpp>

namespace ix
{


class CIxI
{

public:
    void startThreads();

private:
    void socketThreadFunc();

private:
    boost::thread m_socketThread;


};


} // namespace ix

#endif
