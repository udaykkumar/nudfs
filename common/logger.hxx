#ifndef __logger_H__
#define __logger_H__

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <iostream>
namespace logging = boost::log;

#define NU_TRCE BOOST_LOG_TRIVIAL(trace)
#define NU_DBUG BOOST_LOG_TRIVIAL(debug)
#define NU_INFO BOOST_LOG_TRIVIAL(info)
#define NU_WARN BOOST_LOG_TRIVIAL(warning)
#define NU_ERRO BOOST_LOG_TRIVIAL(error)
#define NU_FATL BOOST_LOG_TRIVIAL(fatal)

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * This Snippet of code below shold help in tracing the function calls
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

struct CallTrace
{
    const char *func_;

    CallTrace(const char *function) : func_(function)
    {
        BOOST_LOG_TRIVIAL(trace) << "ENTRY : " << func_;
    }

    ~CallTrace()
    {
        BOOST_LOG_TRIVIAL(trace) << "EXIT  : " << func_;
    }
};

#define EnableTracing            \
    do                           \
    {                            \
        CallTrace(__func__); \
    } while (0);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Function Call trace Ends here
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Try Catch Utilities 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define TRY try
#define CATCH_ALL                                       \
    catch (const std::exception &ex)                    \
    {                                                   \
        std::cout << "Exception " << ex.what() << "\n"; \
    }



#define CATCH_ALL_RET                                   \
    catch (const std::exception &ex)                    \
    {                                                   \
        std::cout << "Exception " << ex.what() << "\n"; \
        return -1;                                      \
    }

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Try Catch Utilities 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#endif // __logger_H__