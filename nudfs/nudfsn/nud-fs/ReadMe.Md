namespace nudfs
{
    namespace fs
    {
        auto stepi = 
            std::make_shared< std::map<int, std::function<void( iBuf, oBuf)>>  >( 
                {1, fs_open},
                {2, fs_read},
                {3, fs_write},
                {4, fs_close}
            );

        void    fs_open( Ibuf ib, Obuf ob )
        {
            return;
        }

        void    fs_read( Ibuf ib, Obuf ob )
        {
            return;
        }

        void    fs_write( Ibuf ib, Obuf ob )
        {
            return;
        }

        void    fs_close( Ibuf ib, Obuf ob )
        {
            return;
        }
    }
}