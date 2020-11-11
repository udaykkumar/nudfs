#include <iostream>
#include <boost/asio.hpp>

void print(const boost::system::error_code& /*e*/)
{
  std::cout << "expired - Hello, world!" << std::endl;
}
int main(int argc, const char** argv) {

    boost::asio::io_context io;
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(10));
    std::cout << "Timer Created !!" << std::endl;
    t.async_wait(&print);
    std::cout << "Timer started !!" << std::endl;
    io.run();
    std::cout << "Timer ended !!" << std::endl;
    return 0;
}