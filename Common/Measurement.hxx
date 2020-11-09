#ifndef __MEASUREMENT_H__
#define __MEASUREMENT_H__
#include <boost/chrono.hpp>
#include "Logger.hxx"

struct execution_time
{
    typedef boost::chrono::high_resolution_clock::time_point execution_time_t;
    typedef const std::string     execution_evt_t;
    execution_time_t t_start_;
    execution_evt_t ex_evt_;
        

    execution_time(const std::string execEvent) : 
    t_start_(boost::chrono::high_resolution_clock::now()),
    ex_evt_(execEvent)
    {

    }

    ~execution_time()
    {
        boost::chrono::milliseconds tDiff =
            (boost::chrono::duration_cast<boost::chrono::milliseconds>(
                boost::chrono::high_resolution_clock::now() - t_start_));

        NU_INFO << "Execution Time Event " << ex_evt_ << " : Time " << tDiff << " ms \n";
    }
};

#endif // __MEASUREMENT_H__