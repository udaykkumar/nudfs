#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <iostream>
#include <exception>
#include <logger.hxx>

namespace nudfs
{
    namespace fs
    {
        struct basic_exception : public std::exception
        {
            std::string Error_;

            basic_exception(const std::string reason = "Unknown") : Error_(reason)
            {
                EnableTracing;
            }

            virtual const char *what() const throw()
            {
                EnableTracing;
                const char *e = Error_.c_str();
                return e;
            }
        };
    } // namespace fs
} // namespace nudfs

#endif // __EXCEPTIONS_H__