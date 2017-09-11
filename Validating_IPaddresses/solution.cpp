#include <iostream>
using namespace std;
int parse(string test);
bool checkValid(string check);
int* numbers(string check);

int main()
{
    
  string test;
  getline(cin, test);
    
  int res = parse(test);
  if(res==1)
    cout<<"InValid";
  else if(res==2)
    cout<<"InRange";
  else
    cout<<"OutRange";
    
    
  return 0;
    
}


int parse(string test){
    
  string cmd;
  size_t l = test.length();
  int spaceCounter = 0;
  int i = 0;
  int lower = 0;
  string lowerBound, upperBound;

  while(spaceCounter!=3){
    if(test[i]==' ')
      spaceCounter++;
    if(spaceCounter==1){
      spaceCounter++;
      lower = i;}
    i++;
  }
  int k = 0;
  while(k<lower){
    lowerBound+=test[k];
    k++;
  }
  int m = i-1;
  int n = k+1;
    
  while(n<m){
    upperBound+=test[n];
    n++;
  }
    
  while(i<l){
    cmd+=test[i];
    i++;
  }
  int* first;
  int* second;
  int* third;
    
  first = numbers(lowerBound);
  int first_num[100];
  for(int i = 0; i < 4; i++){
    first_num[i] = *(first+i);
  }
    
  second = numbers(upperBound);
  int second_num[100];
  for(int i = 0; i < 4; i++){
    second_num[i] = *(second+i);
  }
  third = numbers(cmd);
    

  //Checking valididity
  int counter = 0;
  bool sumCheck = true;
  bool rangeCheck = true;
  for(int i = 0; i < l; i++){
    if(cmd[i]=='.')
      counter++;
  }

  for(int i = 0; i < 4; i++){
    if(*(third+i)<0 || *(third+i)>255)
      sumCheck = false;
  }
    
  //Checking range
    
  for(int i = 0; i < 4;i++){
    if(*(third+i)>=first_num[i] && *(third+i)<=second_num[i])
      rangeCheck &= true;
    else
      rangeCheck &= false;
  }
    
  if(counter!=3 || !sumCheck)
    return 1; //1 = InValid
  if(rangeCheck)
    return 2; //2 = InRange
  else
    return 3; //3 = OutRange
    
    
}


int* numbers(string check){
    
  size_t l = check.length();
  int num[100];
  int indi = 0;
  int m = 0;
    
  while(m<l){
        
    string delimiter = ".";
        
    if(check.find(delimiter)==-1)
      break;
        
    string token;
    token = check.substr(m,check.find(delimiter));
    num[indi] = stoi(token);
    indi++;
    check.erase(0, check.find(delimiter) + delimiter.length());
        
  }
    
  int j = 0;
  string lastNum;
  while(j<check.length()){
    lastNum+=check[j];
    j++;
  }
  num[indi] = stoi(lastNum);
    
  return num;
}
