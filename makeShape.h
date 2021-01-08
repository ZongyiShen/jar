#ifndef MAKESHAPE
#define MAKESHAPE

#include "./shape.h"
#include "./circle.h"
#include "./convexPolygon.h"
#include <sstream>
#include <vector>

using namespace std;
vector<Shape *> objectsFromFile(string fileName) {
    vector<Shape *> result;
    int num=0,index=0;
    vector<char> tag;
    ifstream ifs(fileName);  
    string line;  
    char c;
    stringstream ss,ss1;
    while(getline(ifs,line))
    {   
        if(index==0){
          num = atoi(line.c_str());
        }else{
          if(line[0]=='C'){
            tag.push_back('C');
          }else if(line[0]=='P'){
            tag.push_back('P');
          }
          ss << line;
        }
        index++;
    }
    for(int i=0;i<num;i++){
      if(tag[i]=='C'){
        Shape *shape = new Circle();
        shape->fromString(ss);
        result.push_back(shape);
      }else if(tag[i]=='P'){
        Shape *shape = new Polygon();
        shape->fromString(ss);
        result.push_back(shape);
      }
    }
    return result;
  }

  #endif