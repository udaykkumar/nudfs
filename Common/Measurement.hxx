#ifndef __MEASUREMENT_H__
#define __MEASUREMENT_H__
#include <boost/chrono.hpp>
#include "Logger.hxx"

struct ExecutionTime
{
    typedef boost::chrono::high_resolution_clock::time_point ExecutionTime_t;
    typedef const std::string     ExecitionEvent_t;
    ExecutionTime_t TStart_;
    ExecitionEvent_t ExecEvent_;
        

    ExecutionTime(const std::string execEvent) : 
    TStart_(boost::chrono::high_resolution_clock::now()),
    ExecEvent_(execEvent)
    {

    }

    ~ExecutionTime()
    {
        boost::chrono::milliseconds tDiff =
            (boost::chrono::duration_cast<boost::chrono::milliseconds>(
                boost::chrono::high_resolution_clock::now() - TStart_));

        NU_INFO << "Execution Time Event " << ExecEvent_ << " : Time " << tDiff << " ms \n";
    }
};

#endif // __MEASUREMENT_H__