#include <boost/filesystem.hpp>

#include "Logger.hxx"
#include "MetaRegion.hxx"
#include "Exceptions.hxx"

using namespace Nudfs::FS;

#define NU_ASSERT_FILE_EXISTS(x)                                                  \
    do                                                                            \
    {                                                                             \
        if (!boost::filesystem::exists(disk::name(x)))                            \
        {                                                                         \
            NU_ERRO << "disk {" + disk::name(x) + "} not initialized";            \
            throw basic_exception("disk {" + disk::name(x) + "} not initialized"); \
        }                                                                         \
    } while (0);

disks::disks()
{
    EnableTracing;
    NU_ASSERT_FILE_EXISTS(0);
}

disks::~disks()
{
    EnableTracing;
}

void disks::sync_master()
{
    EnableTracing;
}

void disks::add(const int id)
{
    EnableTracing;
    NU_ASSERT_FILE_EXISTS(id);
}

void disks::remove(const int id)
{
    EnableTracing;
}

void disks::show()
{
    EnableTracing;
}