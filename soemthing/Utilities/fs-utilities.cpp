#include <iostream>
#include <boost/process.hpp>
#include <boost/program_options.hpp>
#include <metaregion.hxx>
#include <logger.hxx>


void init(const std::string f = "sample.log")
{
    //boost::log::add_file_log(f);

    boost::log::core::get()->set_filter(
        logging::trivial::severity >= logging::trivial::debug);
}

using namespace nudfs::fs;
using namespace nudfs::fs::constants;
using namespace boost::program_options;

const std::string create_device(const int dfsid = 0)
{
    EnableTracing;
    std::string c;
    c += "dd if=/dev/zero of=" + disk::name(dfsid);
    c += " bs=" + std::to_string(BlockSize);
    c += " count=" + BlockCountString(dfsid);
    return c;
}

const std::string delete_device(const int dfsid = 0)
{
    EnableTracing;
    std::string c;
    c += "rm -rf " + disk::name(dfsid);
    return c;
}

void run_cmd(const std::string cmd)
{
    EnableTracing;
    namespace bp = boost::process;
    std::vector<std::string> args{"-c", cmd};
    bp::ipstream out;
    bp::child c(bp::search_path("bash"), args, bp::std_out > out);
    c.wait();
    return;
}

int init_master()
{
    EnableTracing;
    try
    {
        run_cmd(create_device(0));
        disks d;
        d.sync_master();
    }
    CATCH_ALL_RET;
    return 0;
}

int add_device(const int x)
{
    EnableTracing;
    try
    {
        disks d;
        run_cmd(create_device(x));
        d.add(x);
    }
    CATCH_ALL_RET;
    return 0;
}

int del_device(const int x)
{
    EnableTracing;
    try
    {
        disks d;
        d.remove(x);
        run_cmd(delete_device(x));
    }
    CATCH_ALL_RET;
    return 0;
}

int show_devices()
{
    EnableTracing;
    try
    {
        disks d;
        d.show();
    }
    CATCH_ALL_RET;
    return 0;
}

int main(int argc, const char **argv)
{
    init();
    EnableTracing;
    try
    {
        options_description desc("Allowed options");
        desc.add_options()
            ("help", "print this message")
            ("init-master", "Initialize Master")
            ("add-dev", value<int>(), "New Block Device Index to be added [ 1 - 10 ]")
            ("del-dev", value<int>(), "Block Device Index to be added [ 1 - 10 ]")
            ("show-dev", "show existing Devices in use");
        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        
        if (vm.count("init-master"))
            return init_master();
            
        if (vm.count("add-dev"))
            return add_device(vm["add-dev"].as<int>());

        if (vm.count("del-dev"))
            return del_device(vm["del-dev"].as<int>());
        
        if (vm.count("show-dev"))
            return show_devices();

        std::cout << desc << "\n";
    }
    CATCH_ALL_RET;
    return 0;
}