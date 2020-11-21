#include <iostream>
#include <thread>

#include <boost/asio/io_service.hpp>

// we have a service handler
boost::asio::io_service io_service;


void worker_thread()
{
    std::cout << "start worker_thread\n";
    std::cout << "stop  worker_thread\n";
}


int main(int argc, char const *argv[]) {

    // Lets get a work object and 
    // get the service do the work for us
    // we can get this done by doing something like this
    std::shared_ptr<boost::asio::io_service::work> work(
        std::make_shared<boost::asio::io_service::work>(
            io_service)
    );

    std::cout << "Lets get started .. Press [ return ] to exit. \n";

    std::thread_group worker_threads;
    for (size_t i = 0; i < 4; i++)
    {
        worker_threads.create_thread( worker_thread );
    }
    
    // Guard the Enter the Quit or whatever yousay
    std::cin.get();

    return 0;
}
