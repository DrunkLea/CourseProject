// ECS 50 HW1.4
// Shuyao Li 915277384

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getLinearIndex(int& row, int& col, int& n){
  int linearIndex;

  linearIndex = (row-1)*n;
  if (row > 2){
    int minus_Num = row-2;
    int minus_Sum = 0;
    while (minus_Num != 0){
      minus_Sum += minus_Num;
      minus_Num--;
    }
    linearIndex -= minus_Sum; //this row start with this index
  }
  linearIndex += (col-row);

  return linearIndex;
}
int ArxBc(int& Ar, int& Bc, int arr1[], int arr2[], int& n){ //Ar = A's row; Bc = B's column;
  int c_sum = 0;
  for (int i = 1; i <=Bc ; i++) {
    if((Ar>i) | (i>Bc))
      continue;
    c_sum += arr1[getLinearIndex(Ar,i,n)]*arr2[getLinearIndex(i,Bc,n)];
  }
  return c_sum;
}

int main(int argc, char* argv[])
{
  ifstream mat1 (argv[1]);
  ifstream mat2 (argv[2]);
  int n;
  int sum = 0;
  mat1 >> n;
  while (n != 0){
    sum += n;
    n--;
  }
  int mat1_ar[sum],mat2_ar[sum];

  int tmp;
  int iter = 0; // save mat1
  while (mat1 >> tmp)
  {
    mat1_ar[iter] = tmp;
    iter++;
  }
  iter = 0; //save mat2
  mat2 >> n; //eat the extra n in mat2 & restore n;
  while (mat2 >> tmp)
  {
    mat2_ar[iter] = tmp;
    iter++;
  }
  mat1.close();
  mat2.close();

  //calculate mat3
  for (int Ar = 1; Ar <= n ; Ar++) {
    for (int Bc = Ar; Bc <= n; Bc++) {
      cout << ArxBc(Ar, Bc, mat1_ar, mat2_ar,n) << " ";
    }
  }
  cout << endl;

}
