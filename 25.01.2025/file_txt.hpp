#pragma once 
 
#include <ios> 
#include "types.hpp" 
 
namespace txt{ 
    using namespace tps; 
 
    bool open_to_read(FileStream& fs, Path const& path); 
    bool open_to_write(FileStream& fs, Path const& path); 
 
    void close(FileStream& fs); 
 
    void read(FileStream& fs, Index& value); 
    void read(FileStream& fs, Coord& value); 
    void read(FileStream& fs, Size& value); 
 
    void read(FileStream& fs, Index**& matrix, Size& nRows, Size& nCols); 
    void read(FileStream& fs, Coord **& matrix, Size& nRows, Size& nCols); 
 
    void write(FileStream& fs, Index value); 
    void write(FileStream& fs, Coord value); 
    void write(FileStream& fs, Size value); 

    void write(FileStream& fs, Index** matrix, Size nRows, Size nCols); 
    void write(FileStream& fs, Coord** matrix, Size nRows, Size nCols); 
} 
 
bool txt::open_to_read(FileStream& fs, Path const& path){ 
    fs.open(path, std::ios::in); 
    return fs.is_open(); 
} 
bool txt::open_to_write(FileStream& fs, Path const& path){ 
    fs.open(path, std::ios::out); 
    return fs.is_open(); 
} 
 
void txt::close(FileStream& fs){ 
    fs.close(); 
} 
 
void txt::read(FileStream& fs, Index& value){ 
    fs >> value; 
} 
void txt::read(FileStream& fs, Coord& value){ 
    fs >> value; 
} 
void txt::read(FileStream& fs, Size& value){ 
    fs >> value; 
} 

void txt::read(FileStream& fs, Index**& matrix, Size& nRows, Size& nCols){ 
    read(fs, nRows); 
    read(fs, nCols); 
 
    matrix = new Index*[nRows]; 
    for (Size i = 0; i < nRows; i++)
    {
        matrix[i] = new Index[nCols];
    }
    
    for (Size i = 0; i < nRows; i++){ 
        for (Size j = 0; j < nCols; j++){ 
            read(fs, matrix[i][j]); 
        } 
    } 
} 

 
void txt::read(FileStream& fs, Coord **& matrix, Size& nRows, Size& nCols){ 
    read(fs, nRows); 
    read(fs, nCols); 
 
    matrix = new Coord*[nRows]; 
    for (Size i = 0; i < nRows; i++)
    {
        matrix[i] = new Coord[nCols];
    }
    
    for (Size i = 0; i < nRows; i++){ 
        for (Size j = 0; j < nCols; j++){ 
            read(fs, matrix[i][j]); 
        } 
    } 
} 
 
void txt::write(FileStream& fs, Index value){ 
    fs << value << ' '; 
} 
void txt::write(FileStream& fs, Coord value){ 
    fs << value << ' '; 
} 

void txt::write(FileStream& fs, Size value){ 
    fs << value << ' '; 
} 

void txt::write(FileStream& fs, Index** matrix, Size nRows, Size nCols){ 
    write(fs, nRows);
    write(fs, nCols);

    for (Size i = 0; i < nRows; i++){ 
        for (Size j = 0; j < nCols; j++){ 
            write(fs, matrix[i][j]); 
        } 
    } 
} 
 
void txt::write(FileStream& fs, Coord** matrix, Size nRows, Size nCols){ 
    write(fs, nRows);
    write(fs, nCols);

    for (Size i = 0; i < nRows; i++){ 
        for (Size j = 0; j < nCols; j++){ 
            write(fs, matrix[i][j]); 
        } 
    } 
}