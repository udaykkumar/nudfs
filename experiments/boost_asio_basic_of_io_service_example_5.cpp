#include <iostream>
#include <memory>
#include <boost/asio/io_service.hpp>

int main(int argc, char const *argv[])
{
    // io_service is like the heart of
    // this whole asio library
    boost::asio::io_service io_service;
    std::shared_ptr< boost::asio::io_service::work >  work( 
        new boost::asio::io_service::work(io_service) 
        );
    work.reset();
    io_service.run();
    std::cout << "Now, even this one should run after polling\n";
    return 0;
}
