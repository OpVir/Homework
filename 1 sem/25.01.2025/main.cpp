//std 
#include <cstdlib>   // system 
#include <iostream>  // cout, endl 
 
#include "types.hpp" 
#include "file_txt.hpp" 
#include "file_raw.hpp" 
#include "console.hpp" 
 
using namespace tps; 
using namespace con; 
 
int main() { 
  Coord** points; 
  Size nPoints, nCoords; 
 
  Index** triangles; 
  Size nTriangles, nTrianglesPoints; 
 
  FileStream fs_input_txt, fs_output_raw, fs_input_raw; 
  Path const path_txt = "grid.txt", path_raw = "grid.raw"; 
 
  txt::open_to_read(fs_input_txt, path_txt); 
  txt::read(fs_input_txt, points, nPoints, nCoords); 
  txt::read(fs_input_txt, triangles, nTriangles, nTrianglesPoints); 
  txt::close(fs_input_txt); 
 
  output(points, nPoints, nCoords); 
  output(triangles, nTriangles, nTrianglesPoints); 
 
  raw::open_to_write(fs_output_raw, path_raw); 
  raw::write(fs_output_raw, points, nPoints, nCoords); 
  raw::write(fs_output_raw, triangles, nTriangles, nTrianglesPoints); 
  raw::close(fs_output_raw); 
 
  Coord** points_new; 
  Size nPoints_new, nCoords_new; 
 
  Index** triangles_new; 
  Size nTriangles_new, nTrianglesPoints_new; 
 
  raw::open_to_read(fs_output_raw, path_raw); 
  raw::read(fs_output_raw, points_new, nPoints_new, nCoords_new); 
  raw::read(fs_output_raw, triangles_new, nTriangles_new, nTrianglesPoints_new); 
  raw::close(fs_output_raw); 

  output(points_new, nPoints_new, nCoords_new); 
  output(triangles_new, nTriangles_new, nTrianglesPoints_new); 
 
  std::system("pause"); 
  return 0; 
}