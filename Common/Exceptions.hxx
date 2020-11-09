#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include <iostream>
#include <exception>
#include "Logger.hxx"

namespace Nudfs
{
    namespace FS
    {
        struct BasicException : public std::exception
        {
            std::string Error_;

            BasicException(const std::string reason = "Unknown") : Error_(reason)
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
    } // namespace FS
} // namespace Nudfs

#endif // __EXCEPTIONS_H__