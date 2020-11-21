#include <iostream>
#include <boost/asio/io_service.hpp>

int main(int argc, char const *argv[]) {
    // io_service is like the heart of 
    // this whole asio library
    boost::asio::io_service ios;
    ios.run();
    std::cout << "will it run ? Ans no\n";
    return 0;
}
