#include <cstdlib>   // std::system
#include <fstream>   // std::ifstream
#include <iomanip>   // std::{fixed, setprecision}
#include <iostream>  // std::{cout, endl}

int readTxt(char const path[],
            int dim, int& nPoints, double**& points,
            int nTrianglePoints, int& nTriangles, int**& triangles);
void outPoints(double** points, int nPoints, int dim);
void outTriangles(int** triangles, int nTriangles, int nTrianglePoints);

int writeRaw(char const path[],
             int dim, int nPoints, double** points,
             int nTrianglePoints, int nTriangles, int** triangles);
int readRaw(char const path[],
            int dim, int& nPoints, double**& points,
            int nTrianglePoints, int& nTriangles, int**& triangles);

int main() {
  int const dim = 2;  // dimension - размерность пространства
  int nPoints;
  double** points;

  int const nTrianglePoints = 3;
  int nTriangles;
  int** triangles;

  char const pathTxt[] = "triangles.txt";
  readTxt(pathTxt, dim, nPoints, points, nTrianglePoints, nTriangles, triangles);
  outPoints(points, nPoints, dim);
  outTriangles(triangles, nTriangles, nTrianglePoints);

  std::cout << "\n---\n\n";

  char const pathRaw[] = "triangles.raw";
  writeRaw(pathRaw, dim, nPoints, points, nTrianglePoints, nTriangles, triangles);
  readRaw(pathRaw, dim, nPoints, points, nTrianglePoints, nTriangles, triangles);
  outPoints(points, nPoints, dim);
  outTriangles(triangles, nTriangles, nTrianglePoints);


  std::system("pause");
  return 0;
}

int readTxt(char const path[],
            int dim, int& nPoints, double**& points,
            int nTrianglePoints, int& nTriangles, int**& triangles) {
  std::ifstream ifs(path);

  if (!ifs.is_open()) {
    std::cout << "Unable to open file path: " << path << std::endl;
    std::system("pause");
    return -1;
  }

  ifs >> nPoints;
  points = new double*[nPoints];
  for (int i = 0; i < nPoints; ++i) {
    points[i] = new double[dim];
  }

  for (int ptNum = 0; ptNum < nPoints; ++ptNum) {
    for (int crdNum = 0; crdNum < dim; ++crdNum) {
      ifs >> points[ptNum][crdNum];
    }
  }

  ifs >> nTriangles;
  triangles = new int*[nTriangles];
  for (int i = 0; i < nTriangles; ++i) {
    triangles[i] = new int[nTrianglePoints];
  }

  for (int trNum = 0; trNum < nTriangles; ++trNum) {
    for (int ptNum = 0; ptNum < nTrianglePoints; ++ptNum) {
      ifs >> triangles[trNum][ptNum];
      --triangles[trNum][ptNum];  // нумерация должна быть с нуля!
    }
  }

  ifs.close();

  return 0;
}


void outPoints(double** points, int nPoints, int dim) {
  std::cout << nPoints << std::endl;
  for (int ptNum = 0; ptNum < nPoints; ++ptNum) {
    for (int crdNum = 0; crdNum < dim; ++crdNum) {
      // std::fixed - выводить нули после точки
      // std::setprecision - количество цифр после точки
      // std::setw - ширина столбца
      std::cout <<  points[ptNum][crdNum] << ' ';
    }
    std::cout << std::endl;
  }
}


int writeRaw(char const path[],
             int dim, int nPoints, double** points,
             int nTrianglePoints, int nTriangles, int** triangles){
  std::ofstream ofs(path, std::ios::binary);

  if (!ofs.is_open()) {
    std::cout << "Unable to open file path: " << path << std::endl;
    std::system("pause");
    return -1;
  }

  ofs.write((char*)&nPoints, sizeof(int));

  for (int ptNum = 0; ptNum < nPoints; ptNum++){
    ofs.write((char*)points[ptNum], sizeof(double)*dim);
  }
  
  ofs.write((char*)&nTriangles, sizeof(int));

  for (int trNum = 0; trNum < nTriangles; trNum++){
    ofs.write((char*)triangles[trNum], sizeof(int)*nTrianglePoints);
  }

  ofs.close();

  return 0;
}


int readRaw(char const path[],
            int dim, int& nPoints, double**& points,
            int nTrianglePoints, int& nTriangles, int**& triangles){
  std::ifstream ifs(path, std::ios::binary);

  if (!ifs.is_open()) {
    std::cout << "Unable to open file path: " << path << std::endl;
    std::system("pause");
    return -1;
  }

  ifs.read((char*)&nPoints, sizeof(int));

  points = new double*[nPoints];
  for (int i = 0; i < nPoints; ++i) {
    points[i] = new double[dim];
  }
  
  for (int i = 0; i < nPoints; i++){
    for (int j = 0; j < dim; j++){
        ifs.read((char*)&points[i][j], sizeof(double));
    }
    
  }

  ifs.read((char*)&nTriangles, sizeof(int));

  triangles = new int*[nTriangles];
  for (int i = 0; i < nTriangles; ++i) {
    triangles[i] = new int[nTrianglePoints];
  }
  
  for (int i = 0; i < nTriangles; i++){    
    for (int j = 0; j < nTrianglePoints; j++){
      ifs.read((char*)&triangles[i][j], sizeof(int));
    }
  }
  
  ifs.close();

  return 0;
}


void outTriangles(int** triangles, int nTriangles, int nTrianglePoints) {
  std::cout << nTriangles << std::endl;
  for (int trNum = 0; trNum < nTriangles; ++trNum) {
    for (int ptNum = 0; ptNum < nTrianglePoints; ++ptNum) {
      std::cout << triangles[trNum][ptNum] << ' ';
    }
    std::cout << std::endl;
  }
}