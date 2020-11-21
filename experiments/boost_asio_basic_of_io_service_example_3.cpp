#include <iostream>
#include <boost/asio/io_service.hpp>

int main(int argc, char const *argv[])
{
    // io_service is like the heart of
    // this whole asio library
    boost::asio::io_service io_service;
    for (size_t i = 0; i < 60; ++i)
    {
        io_service.poll();
        std::cout << "Polling " << i << " \n";
    }
    std::cout << "This one should run after polling\n";
    return 0;
}
