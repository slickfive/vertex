/*
 * =====================================================================================
 *
 *       Filename:  client_server.cpp
 *
 *    Description:  test another client server program
 *
 *        Version:  1.0
 *        Created:  28/10/12 16:09:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Raj Panesar (), raj.panesar@xiltec.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include "IxI.hpp"
#include "Log.hpp"


int main()
{
    TRACE( "Program started" );
 
    ix::CIxI *ixi = new ix::CIxI();




    ixi->startThreads();


    
    while (1)
    {   
        TRACE( "processing" );        

        sleep(1);
    }



    delete ixi;

    return 0;
}
