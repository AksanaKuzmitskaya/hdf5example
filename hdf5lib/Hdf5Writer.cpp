#include "Hdf5Writer.h"

void
	HDF5Writer::
	h5Write ( 
	    std::string const & dsetStringsName ,
        std::string const & dsetDoublesName
) { 		
/*****************************************************************
	Open the named file, truncating the existing one if any.
*****************************************************************/
	H5::H5File
		hdf5File( hdf5FileName_ , H5F_ACC_TRUNC  ) ;

/******************************
	Commit the data
******************************/
// putting strings into vector of chars for HDF5 
    std::vector< const char * > buffer_char_ptr_names ;
    buffer_char_ptr_names.reserve( serializedNames_.size() ) ;
    for ( size_t i = 0 ; i != serializedNames_.size() ; ++i ) 
        buffer_char_ptr_names.push_back( serializedNames_[i].c_str() ) ;
// resizing hdf5 string type for the variable size 
    H5::StrType stype( 0, H5T_VARIABLE ) ; 
	writeDataset( hdf5File , dsetStringsName   , stype ,	     	             buffer_char_ptr_names ,  serializedNames_.size() ) ;
	writeDataset( hdf5File , dsetDoublesName , H5::PredType::NATIVE_DOUBLE , serializedNumbers_ ) ;
	hdf5File.close() ;
}

