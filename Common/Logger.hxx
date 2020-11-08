#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <iostream>
namespace logging = boost::log;

#define NU_TRCE BOOST_LOG_TRIVIAL(trace)
#define NU_DEBG BOOST_LOG_TRIVIAL(debug)
#define NU_INFO BOOST_LOG_TRIVIAL(info)
#define NU_WARN BOOST_LOG_TRIVIAL(warning)
#define NU_ERRO BOOST_LOG_TRIVIAL(error)
#define NU_FATL BOOST_LOG_TRIVIAL(fatal)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * This Snippet of code below shold help in tracing the function calls
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

struct CallTrace
{
    const char *function_;

    CallTrace(const char *function) : function_(function)
    {
        BOOST_LOG_TRIVIAL(trace) << "ENTRY : " << function_;
    }

    ~CallTrace()
    {
        BOOST_LOG_TRIVIAL(trace) << "EXIT  : " << function_;
    }
};

#define EnableTracing                \
    do                           \
    {                            \
        CallTrace(__FUNCTION__); \
    } while (0);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Function Call trace Ends here
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define TRY try
#define CATCH_ALL                                       \
    catch (const std::exception &ex)                    \
    {                                                   \
        std::cout << "Exception " << ex.what() << "\n"; \
    }

#endif // __LOGGER_H__