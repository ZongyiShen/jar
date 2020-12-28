#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
double getSolution(double a,double b,double c){
  double x1=((-1)*b+sqrt(b*b-4*a*c))/2*a;
  double x2=((-1)*b-sqrt(b*b-4*a*c))/2*a;
  if(abs(x1) < abs(x2)){
    return x2;
  }
  return x1;
}
class matrix{
  private:
    string name;
    double element[2][2];
  public:
    matrix(){
      name=string("unknown");
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          element[i][j] = 0;
        }
      }
    }
    matrix(double input[][2],string s){
      name=s;
      for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
          element[i][j] = input[i][j];
        }
      }
    }
    double findEigenvalue(){
      return getSolution(1,(-1)*(element[0][0]+element[1][1]),(element[0][0]*element[1][1])-(element[0][1]*element[1][0]));
    }
    vector <double> findEigenVector(){
      vector<double> result;
      matrix a = matrix(element,name);
      double u=this->findEigenvalue();
      a.element[1][1]-=u;
      a.element[0][0]-=u;
      if(a.element[0][0] == 0 && a.element[1][1]){
        std :: swap(a.element[0][0],a.element[1][0]);
        std :: swap(a.element[0][1],a.element[1][1]);
      }
      if(a.element[0][0] != 0){
        a.element[0][1]/=a.element[0][0];
        a.element[0][0]=1;
      }
      else if(a.element[0][1] != 0){
        a.element[0][1]=1;
      }
      if(a.element[1][0] != 0){
        a.element[1][1]/=a.element[1][0];
        a.element[1][0]=1;
        a.element[1][0]=a.element[1][0]-a.element[0][0];
        a.element[1][1]=a.element[1][1]-a.element[0][1];
      }
      else if(a.element[1][1] != 0){
        a.element[1][1]=1;
        a.element[1][0]=a.element[1][0]-a.element[0][0];
        a.element[1][1]=a.element[1][1]-a.element[0][1];
      }
      a.element[0][0]=a.element[0][0]-a.element[1][0];
      a.element[0][1]=a.element[0][1]-a.element[1][1];
      if(!a.element[0][0] && a.element[0][1]){
        result.push_back(1);
        result.push_back(0);
      }
      else{
      result.push_back((-1)*a.element[0][1]);
      result.push_back(a.element[0][0]);
      }
      return result;
    }
    void printEigenVector(){
      cout << name << " EigenVector is " << endl;
      vector <double> r=this->findEigenVector();
      for(int i=0;i<r.size();i++){
        if(r[i] == -0){
          r[i] = 0;
        }
        cout << r[i]<<endl;
      }
    }
};


int main(){
  double s[2][2]={
    {2,0},
    {0,-5}
  };
  double t[2][2]={
    {2,-12},
    {1,-5}
  };
  double u[2][2]={
    {5,2},
    {2,3}
  };
  double v[2][2]={
    {1,1},
    {1,1}
  };
  double w[2][2]={
    {2,1},
    {0,2}
  };
  double x[2][2]={
    {3,1},
    {-1,1}
  };
  matrix S=matrix(s,string("Matrix S"));
  matrix T=matrix(t,string("Matrix T"));
  matrix U=matrix(u,string("Matrix U"));
  matrix V=matrix(v,string("Matrix V"));
  matrix W=matrix(w,string("Matrix W"));
  matrix X=matrix(x,string("Matrix X"));
  S.printEigenVector();
  T.printEigenVector();
  U.printEigenVector();
  V.printEigenVector();
  W.printEigenVector();
  X.printEigenVector();
  

  return 0;
}
