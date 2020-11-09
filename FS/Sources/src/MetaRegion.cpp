#include <boost/filesystem.hpp>

#include <logger.hxx>
#include <metaregion.hxx>
#include <exceptions.hxx>

using namespace nudfs::fs;

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
    auto d = disk::name(0);
    NU_DBUG << "syncing " << d;
}

void disks::add(const int id)
{
    EnableTracing;
    NU_ASSERT_FILE_EXISTS(id);
    auto d = disk::name(id);
    NU_DBUG << "adding " << d;
}

void disks::remove(const int id)
{
    EnableTracing;
    NU_ASSERT_FILE_EXISTS(id);
    auto d = disk::name(id);
    NU_DBUG << "removing " << d;
}

void disks::show()
{
    EnableTracing;
}