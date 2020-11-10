

Typical Clinet :

    
namespace nudfs
{
    // Node Operations 
    struct nops ops
    {
        int (*open)  ( char *file, int permissions );
        int (*read) ( char *file, int permissions );
    }

    // Node Descriptor Data
    struct ndesc
    {
        // Remote File Descriptor
        int rfd;
    };

    // Node information ( the FS )
    struct node
    {
        const char *ip;
        short       port;

        int open  ( char *file, int permissions );
        int read  ( buffer, size );
        int write ( buffer, size );
        int close ();

        node( ip, port ) :
            ip(ip), port(port)
        {
            nds = network_open();
            init_other_things();
        }

        private:
            ndesc nds;    
    };

    // Sample Open
    node::open( char *file, int perm )
    {
        try
        {
            struct req(OPEN, file, perm );
            nds.send(req, rsp);
            rsp = nds.get();
            return rsp.whatever();
        }
        catch ( error ) { }
    }
}  
    
int main(int ac, char **av )
{
    try
    {
        node n( ac, av );
        n.ops.open( file );
        n.ops.write( );
    }
    catch( .. )
    {

    }   
}
