Typical Server side 


namespace nudfs
{
    namespace net
    {
        void fall_through( op, iBuf, oBuf )
        {
            // a functor of corresponding op handle
            fs::stepi.get()[op]( iBuf, oBuf );
        }

        void async_do_op()
        {
            auto op   = resp.op();
            auto iBuf = std::optional( resp.inBuf() );
            auto oBuf = std::optional( resp.inBuf() );
    
            // This will eventually call the corresponding fs-calls
            fall_through( op, iBuf, oBuf );
        }

        void net()
        {
            
            // some Async List and accept handlers
            // somewhere along the lines of

            auto respond = [] () {
                tcp_acceptor.respond(resp);
            } ;

            tcp_acceptor.async_accept(tcp_socket, [respond]() {
                // Accept handler
                // series of read and parse request()
        
                async_do_op( req,  respond );
            });
        }
    }
    
}



