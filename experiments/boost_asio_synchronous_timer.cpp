#include <iostream>
#include <boost/asio.hpp>

int main(int argc, const char **argv)
{
    boost::asio::io_service io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(10));
    std::cout << "Timer Started !!\n";
    t.wait();
    std::cout << "Timer Expired !!\n";
    return 0;
}
