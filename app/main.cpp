#include "../hdf5lib/Hdf5Writer.h"
#include "../hdf5lib/Hdf5Reader.h"

int main() {
    const char *strings[] = {"Testing HDF5 Library", "Testing HDF5 Library2"};
    std::vector<std::string> names (strings, strings + 2);
    std::string dsetStringsName = "SerializedNames";
    
    const double doubles[] = {3.45, 4.007, 5};
    std::vector<double> numbers (doubles, doubles + 3);
    std::string dsetDoublesName = "SerializedNumbers";
    
    std::string h5FileName = "testHdf5.hdf5"; 
    
    HDF5Writer writer(names, numbers, h5FileName);
    writer.h5Write(dsetStringsName, dsetDoublesName);
    
    Hdf5Reader reader(h5FileName);
    reader.h5Read(dsetStringsName, dsetDoublesName);
}
