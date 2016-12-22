#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hdf5Reader {
    std::vector< char * >           strNames_     ;
    std::vector< double >           numbers_      ;
    std::string           const &   hdf5FileName_ ;
public:
    Hdf5Reader( std::string const & hdf5FileName )
        : hdf5FileName_ ( hdf5FileName ) {}
    void
        h5Read( std::string const & dsetStringsName , std::string const & dsetDoublesName ) ;
} ;
