#include <iostream>
#include <boost/asio/io_service.hpp>

int main(int argc, char const *argv[])
{
    // io_service is like the heart of
    // this whole asio library
    boost::asio::io_service io_service;
    boost::asio::io_service::work work(io_service);
    io_service.run();

    std::cout << "will it run ? well no .. \n";
    return 0;
}
