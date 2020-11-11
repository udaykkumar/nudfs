#include <iostream>
#include <boost/asio.hpp>

int main(int argc, const char** argv) {
    boost::asio::io_service io;
    boost::asio::steady_timer t( io, boost::asio::chrono::seconds(1));
    std::cout << " timer created" << "\n";
    
    int counter = 0;
    t.async_wait([&counter] (const boost::system::error_code &e ) -> void {
        ++counter;
    });
    std::cout << " timer started counter" << counter << "\n";
    
    io.run();
    std::cout << " timer ended counter " << counter << "\n";
    return 0;
}