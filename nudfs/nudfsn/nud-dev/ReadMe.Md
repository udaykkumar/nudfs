#### 


Lowest level of storage is identified as disk, a disk is a combination of meta and data segments

meta is a collection is entries, entry is a representation of file.
data is a collection of pages, page is a representation of a block of memeory


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
// 
//      Meta 
//  
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 

struct entry {
    const char *filenmae;
    int         permissions;
    time_t      creation_time;
    time_t      modification_time;
};

struct meta {
    entry   entries[MAX_ENTRIED_PER_DISK];

    get_free_entry();
    put_free_entry();

};


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 
//                                                                                  
//      Data 
//  
// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // 

struct cksum {
    size_t value;
};

struct page {
    cksum   head;
    // so if PAGE_SIZE is 1024 Bytes
    //  and cksum occupies 4 bytes
    // actual size reserved for data is 1024 - 8 ( head 4, foot 4 ) == 996 bytes

    char [PAGE_SIZE - ( 2 * sizeof(cksum) )];
    cksum   foot;
};

struct data {
    page   pages[MAX_PAGES_PER_DISK];

    get_free_page();
    put_free_page();

};







