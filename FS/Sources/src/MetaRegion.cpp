#include <boost/filesystem.hpp>

#include "Logger.hxx"
#include "MetaRegion.hxx"
#include "Exceptions.hxx"

using namespace Nudfs::FS;

#define ASSERT_EXISTS(x)                                  \
    do                                                    \
    {                                                     \
        if (not boost::filesystem::exists(Disk(0)))       \
        {                                                 \
            NU_ERRO << "Master Disk Not initialized";     \
            throw BasicException("Disk Not initialized"); \
        }                                                 \
    } while (0);

Disks::Disks()
{
    EnableTracing;
    ASSERT_EXISTS(id);
}

Disks::~Disks()
{
    EnableTracing;
}

void Disks::Sync_Master()
{
    EnableTracing;
    
}

void Disks::Sync(const int id)
{
    EnableTracing;
    ASSERT_EXISTS(id);
}

void Disks::Unlink(const int id)
{
    EnableTracing;
}

void Disks::Show()
{
    EnableTracing;
}