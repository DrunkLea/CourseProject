// ECS 50 HW1.1
// Shuyao Li 915277384
#include<cmath>
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
  int inNum [argc-1];
  char word [argc-1];
  for (int i = 0; i < argc-1; i++) {
    inNum[i] = stoi(argv[i+1]);
    if ( inNum[i]&0x04000000) { //if Upper
      inNum[i] &= 0xfbffffff; //get rid off the most significant 1
      word[i] = 65 + log2(inNum[i]);
    }
    else{
      word[i] = 97 +log2(inNum[i]);
    }
  }
  cout << "You entered the word: ";
  for (int i = 0; i < argc-1; i++) {
    cout << word[i];
  }
  cout << "\n";

  return 0;
}
