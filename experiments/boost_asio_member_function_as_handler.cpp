#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>


struct printer
{
    printer(boost::asio::io_service& ios) 
        : timer_(ios, boost::asio::chrono::seconds(10)) ,
            count_(0)
        {
            timer_.async_wait(boost::bind(&printer::print, this));
        }

    void print()
    {
        std::cout << "inside print " << ++count_ << "\n";
    }

    private:
        boost::asio::steady_timer timer_;
        int count_;
};


int main(int argc, const char** argv) {

    boost::asio::io_service ios;
    std::cout << "initiate printer object \n";
    printer p(ios);
    std::cout << "run timer for object \n";
    ios.run();   
    return 0;
}