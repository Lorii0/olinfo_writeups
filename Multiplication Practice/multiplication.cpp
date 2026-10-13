#include <bits/stdc++.h>

using namespace std;

bool isCharFound(const string& str, char ch) {
  return str.find(ch) != string::npos;
}

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t;fin>>t;

  for(int i = 0;i<t;i++){
    
    int n;
    fin >> n;

    int m = n;
    string str = to_string(n);

    bool one=false,two=false,three=false,four=false,five=false,six=false,seven=false,eight=false,nine = false;
    bool zero = false;

    int count = 0;
    int mul = 0;

      while(count != 10)
      {
        mul++;


        if(isCharFound(str,'0'))
        {
          if(zero==false){
            zero = true;
            count++;
          }
            
        }
        if(isCharFound(str,'1'))
        {
          if(one==false){
            one = true;
            count++;
          }
            
        }
        if(isCharFound(str,'2'))
        {
          if(two==false){
            count++;
            two = true;
          }
            
          
        }

        if(isCharFound(str,'3'))
        {
          if(three==false){
            count++;
            three = true;
          }
        }
        if(isCharFound(str,'4'))
        {
          if(four==false){
            count++;
            four = true;
          }
            
        }
        if(isCharFound(str,'5'))
        {
          if(five==false){
            count++;
            five = true;
          }
            
        }
        if(isCharFound(str,'6'))
        {
          if(six ==false){
            six = true;
            count++;
          }
            
        }

        if(isCharFound(str,'7'))
        {
          if(seven==false){
            seven = true;
            count++;
          }
            
        }
        if(isCharFound(str,'8'))
        {
          if(eight ==false){
            eight = true;
            count++;
          }
            
        }

        if(isCharFound(str,'9'))
        {
          if(nine==false){
             nine= true;
            count++;
          }
           
        }

        n+= m;

        str = to_string(n);
      }

    fout << mul<<endl;
  }
  
}
