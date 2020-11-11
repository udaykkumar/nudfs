#include <iostream>
#include <boost/asio.hpp>

int main(int argc, const char** argv) {
    boost::asio::io_service io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(10));
    std::cout << "Created" << std::endl;

    
    t.async_wait([](const boost::system::error_code &e){
        std::cout << "Expired" << std::endl;
    });

    std::cout << "started" << std::endl;
    io.run();
    return 0;
}