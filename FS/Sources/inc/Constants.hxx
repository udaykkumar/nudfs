#ifndef __CONSTANTS_H__
#define __CONSTANTS_H__

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

    } // namespace FS
} // namespace Nudfs
#endif // __CONSTANTS_H__