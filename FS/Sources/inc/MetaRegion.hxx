#ifndef __METAREGION_H__
#define __METAREGION_H__

#include <iostream>
#include "Logger.hxx"
#include "Constants.hxx"

namespace Nudfs
{
    namespace FS
    {
        static const std::string BlockCountString(const int id = 0)
        {
            return std::to_string(id ? Constants::BlockCount : Constants::BlockCount_DFS0);
        }

        struct type_guard
        {
            size_t Checksum_;
            type_guard(const size_t x) : Checksum_(x) {}
        };

        struct disk
        {
            type_guard  head_;
            char        name_[Constants::Max_Name_Len];
            type_guard  foot_;

            disk(std::string n) : 
                head_(0),
                foot_(0)
            {
                EnableTracing;
                std::memcpy(name_, n.c_str(), Constants::Max_Name_Len);
            }

            disk() : 
                head_(0),
                foot_(0)
            {
                EnableTracing;
                std::memset(name_, 0x00, Constants::Max_Name_Len);
            }

            static const std::string name(const int id = 0)
            {
                return Constants::MasterDisk + std::to_string(id);
            }
        };

        struct disks
        {
            disk disk_[Constants::Max_Supported_Disks];

            disks();
            ~disks();

        public:
            void add(const int id = 0);
            void sync_master();
            void remove(const int id);
            void show();

            
        };

    } // namespace FS
} // namespace Nudfs

#endif // __METAREGION_H__