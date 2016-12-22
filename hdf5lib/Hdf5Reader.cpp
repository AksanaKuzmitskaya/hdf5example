#include "Hdf5Reader.h"
// HDF5
#include <H5Cpp.h>

void
    Hdf5Reader::
    h5Read (
        std::string const & dsetStringsName ,
        std::string const & dsetDoublesName
) { 
    H5::H5File  hdf5File( hdf5FileName_ , H5F_ACC_RDONLY ) ;
/****************************
    Reading the Names :
****************************/
    // ..open dsetNames :
    H5::DataSet   dsetNames   = hdf5File.openDataSet( dsetStringsName ) ;
    H5::DataSpace dspaceNames = dsetNames.getSpace() ;
    // .. get and store the number of factors :
    hsize_t shape[1] ;
    int ndims    = dspaceNames.getSimpleExtentDims( shape, NULL ) ;
    int nbrNames = ( int )( shape[0] ) ;
    // ..finally :
    strNames_.resize( nbrNames ) ;
    std::cout << "--->  Getting names from " << hdf5FileName_ << "." << std::endl ;
// resizing hdf5 string type for the variable size 
    H5::StrType stype( 0, H5T_VARIABLE ) ; 
    dsetNames  .read( strNames_.data() , stype ) ;
    dspaceNames.close() ;
    dsetNames  .close() ;
    for ( int i = 0 ; i != strNames_.size() ; ++i )
       std::cout << "Name " << i << ": " << strNames_[i] << std::endl ;
/*************************
    Reading the Numbers :
**************************/
    H5::DataSet   dsetNumbers   = hdf5File.openDataSet( dsetDoublesName ) ;
    H5::DataSpace dspaceNumbers = dsetNumbers.getSpace() ;
    ndims    = dspaceNumbers.getSimpleExtentDims( shape, NULL ) ;
    nbrNames = ( std::size_t )( shape[0] ) ;
    numbers_.resize( nbrNames ) ;
    std::cout << "--->  Getting  numbers from " << hdf5FileName_ << "." << std::endl ;
    dsetNumbers  .read( numbers_.data() , H5::PredType::NATIVE_DOUBLE ) ;
    dspaceNumbers.close() ;
    dsetNumbers  .close() ;
    for ( int i = 0 ; i != numbers_.size() ; ++i )
        std::cout << "Number " << i << ": " << numbers_[i] << std::endl ;
}
