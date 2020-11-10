#ifndef __DEV_H__
#define __DEV_H__

#include <cstdint>

namespace nudfs
{
    namespace storage
    {
        struct device
        {
            explicit device(const uint8_t id = 0);
            ~device() { }

            uint8_t id_;
        };
    } // namespace storage
} // namespace nudfs

#endif // __DEV_H__