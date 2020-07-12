// ECS 50 HW1.3
// Shuyao Li 915277384

#include<iostream>
#include<string>
using namespace std;

int main()
{
  float f_num;
  cout << "Please enter a float: ";
  cin >> f_num;

  unsigned int i_num = *((unsigned int*)&f_num);

if(i_num == 0){
  cout <<  "0E0" << endl;
}else{
  // read sign
  bool isNeg = i_num&0x80000000; //true if the sign bit is 1

  int exponent = i_num & 0x7fffffff; //set sign bet to 0
  exponent = exponent >> 23;
  exponent -= 127;

    //read Mantissa
    i_num &= 0x007fffff; //keep only the Mantissa part

    int shift_count = 0;
    while (!(i_num&0x00000001)) { //true if the least significant bit is 0
      i_num = i_num >> 1;
      shift_count++;
    }
    string rev_Mantissa;
    for (int i = 0; i < 23-shift_count; i++) {
      if (i_num&0x00000001){
        rev_Mantissa += '1';
      }else
        rev_Mantissa += '0';
      i_num = i_num >> 1;
    }
    string Mantissa;
    for (int i = rev_Mantissa.length()-1; i >= 0 ; i--) {
      Mantissa += rev_Mantissa[i];
    }

    string answer;
    if(isNeg){
      answer += "-";
    }
    answer += "1." + Mantissa + "E";
    cout <<  answer << exponent << endl;
}

  return 0;
}
