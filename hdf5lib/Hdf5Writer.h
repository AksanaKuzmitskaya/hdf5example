#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
// HDF5
#include <H5Cpp.h>

class HDF5Writer {
    std::vector< std::string >  const serializedNames_;
    std::vector< double >       const serializedNumbers_;
    std::string                 const & hdf5FileName_;
        template< typename T >
    void writeDataset(H5::H5File & file, std::string const & name, H5::DataType const & h5PredType,
                      std::vector< T > const & buffer, hsize_t dimsf = 0){
        if (dimsf == 0)
            dimsf = buffer.size();
        std::cout << "--->  Writing " << name << " into hdf5 file." << std::endl;
        const hsize_t hdf5_rank = 1;
        H5::DataSpace dataspace( hdf5_rank, &dimsf );
        H5::DataSet dataset =
            file.createDataSet(name, h5PredType, dataspace);
        dataset.write(buffer.data(), h5PredType);
        dataspace.close();
        dataset.close();
    }
public:
    HDF5Writer(std::vector< std::string > const & namesToBeSerialized, std::vector< double > const & doublesToBeSerialized, 
               std::string const & hdf5FileName) : serializedNames_(namesToBeSerialized), serializedNumbers_(doublesToBeSerialized), hdf5FileName_(hdf5FileName){}
    void h5Write(std::string const & dsetStringsName, std::string const & dsetDoublesName);
};
