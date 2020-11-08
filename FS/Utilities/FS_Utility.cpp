#include <iostream>
#include <boost/process.hpp>
#include <boost/program_options.hpp>
#include "MetaRegion.hxx"
#include "Logger.hxx"

using namespace Nudfs::FS;
using namespace Nudfs::FS::Constants;
using namespace boost::program_options;

static int ADD_DfsId = 0;
static int Del_DfsId = 0;
static bool Show = false;
static bool InitMaster = false;

const std::string DD(const int dfsid = 0)
{
    EnableTracing;
    std::string c;
    c += "dd if=/dev/zero of=" + Disk(dfsid);
    c += " bs=" + std::to_string(BlockSize);
    c += " count=" + BlockCountString(dfsid);
    return c;
}

void Exec(const std::string cmd)
{
    EnableTracing;
    std::cout << cmd << "\n";
    namespace bp = boost::process;
    std::vector<std::string> args{"-c", cmd};
    bp::ipstream out;
    bp::child c(bp::search_path("bash"), args, bp::std_out > out);
    c.wait();
    return;
}

void SetupMaster()
{
    EnableTracing;
    try
    {
        Exec(DD(0));
        Disks d;
        d.Sync_Master();
    }
    catch (const std::exception &e)
    {
        NU_ERRO << "error setting up Master " << e.what() << "\n";
    }
}

void Add_NuDFS(const int x)
{
    EnableTracing;
    try
    {
        Exec(DD(x));
        Disks d;
        d.Sync(x);
    }
    catch (const std::exception &e)
    {
        NU_ERRO << "error setting up Node " << e.what() << "\n";
    }
}

void Del_NuDFS(const int x)
{
    EnableTracing;
    try
    {
        Disks d;
        d.Unlink(x);
    }
    catch (const std::exception &e)
    {
        NU_ERRO << "error Unlinking Node " << e.what() << "\n";
    }
}

void Show_NuDFS()
{
    EnableTracing;
    try
    {
        Disks d;
        d.Show();
    }
    catch (const std::exception &e)
    {
        NU_ERRO << "error Showing Devices " << e.what() << "\n";
    }
}

int main(int argc, const char **argv)
{
    EnableTracing;
    try
    {
        options_description desc("Allowed options");
        desc.add_options()
            ("help", "print this message")
            ("Init", "Initialize Master")
            ("Add", value<int>(), "New Block Device Index to be added [ 1 - 10 ]")
            ("Del", value<int>(), "Block Device Index to be added [ 1 - 10 ]")
            ("Show", "Show existing Devices in use");
        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        if (vm.count("help"))
        {
            std::cout << desc << "\n";
            return 0;
        }

        ADD_DfsId = (vm.count("Add")) ? vm["Add"].as<int>() : 0;
        Del_DfsId = (vm.count("Del")) ? vm["Del"].as<int>() : 0;
        Show = (vm.count("Show")) ? true : false;
        InitMaster = (vm.count("Init")) ? true : false;

        NU_INFO << " ADD " << ADD_DfsId ;
        NU_INFO << " DEL " << Del_DfsId;
        NU_INFO << " SHOW " << Show;
        NU_INFO << " INIT " << InitMaster;

        if (vm.count("Init"))
        {
            SetupMaster();
            return 0;
        }
            
        if (vm.count("Add"))
        {
            Add_NuDFS(ADD_DfsId);
            return 0;
        }
            
        if (vm.count("Del"))
        {
            Del_NuDFS(Del_DfsId);
            return 0;
        }

        if (vm.count("Show"))
        {
            Show_NuDFS();
            return 0;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}