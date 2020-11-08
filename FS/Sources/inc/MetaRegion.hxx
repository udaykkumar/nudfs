#ifndef __METAREGION_H__
#define __METAREGION_H__

#include <iostream>
#include "Logger.hxx"

namespace Nudfs
{
    namespace FS
    {
        namespace Constants
        {
            const std::string MasterDisk{"dfs"};
            constexpr size_t Max_Supported_Disks{10};
            constexpr size_t Max_Name_Len{126};
            constexpr size_t BlockSize{4096};
            constexpr size_t BlockCount{(1024 * 1024 * 1024) / BlockSize};
            constexpr size_t BlockCount_DFS0{(1024 * 1024) / BlockSize};
        } // namespace Constants

        static const std::string Disk(const int id = 0)
        {
            return Constants::MasterDisk + std::to_string(id);
        }

        static const std::string BlockCountString(const int id = 0)
        {
            return std::to_string(id ? Constants::BlockCount : Constants::BlockCount_DFS0);
        }

        struct GuardType
        {
            size_t Checksum_;
            GuardType(const size_t x) : Checksum_(x) {}
        };

        
        typedef GuardType  DiskFoot;
        typedef GuardType  DiskHead;

        struct DiskEntry
        {
            GuardType    Head_;
            char         Name_[Constants::Max_Name_Len];
            GuardType    Foot_;
 
            DiskEntry(std::string n) :
                Head_(0),
                Foot_(0) 
            {
                EnableTracing;
                std::memcpy(Name_, n.c_str(), Constants::Max_Name_Len);
            }

        };

        
        struct Disks
        {
            DiskEntry disks_[Constants::Max_Supported_Disks];

            Disks();
            ~Disks();

        public:
            void Sync(const int id = 0);
            void Sync_Master();
            void Unlink(const int id);
            void Show();
        };

    } // namespace FS
} // namespace Nudfs

#endif // __METAREGION_H__