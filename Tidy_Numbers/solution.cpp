//
//  main.cpp
//  CTCI
//
//  Created by Yash Choudhary on 9/14/17.
//  Copyright © 2017 Yash Choudhary. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


int checkTidy(int test);

int main() {
    
  int t;
  cin>>t;
  vector<int> testCases;
  while(t){
    int temp;
    cin>>temp;
    testCases.push_back(temp);
    t--;
  }
    
  for(int i = 0; i < testCases.size(); i++){
        
    cout<< checkTidy(testCases[i])<<endl;
  }
    
  return 0;
}



int checkTidy(int test){
    
  vector<int> numbers;
  int temp = test;
    
  while(temp){
        
    numbers.push_back(temp%10);
    temp = temp/10;
  }
    
  int indi = numbers.size();
  //If its single digit int or all digits are same then return number itself
    
  if(indi==1)
    return test;
    
  bool same = true;
    
  for(int i = 0; i < indi; i++){
    if(numbers[i]!=numbers[0])
      same = false;
  }
    
  if(same)
    return test;
    
  if(numbers[indi-1]>=numbers[indi-2]){
        
    int t = numbers[indi-1];
    int exp = pow(10, indi-1);
    int ans = t*exp -1;
    return ans;
  }
    
  else{
        
    bool correct = true;
        
    for(int i = indi-1; i > 0; i--){
            
      if(numbers[i]>numbers[i-1]){
                
	correct = false;
	int b = 10*(indi-(i+1));
	int a = test/b;
                
	return a*10-1;
      }
            
    }
        
  }
    
    
    
    
    
  return test;
}


