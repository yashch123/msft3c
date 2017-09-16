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
#include <algorithm>
using namespace std;

bool isPointValid(char arr[][6], int i, int j);

vector<char> ele;
int n,m;

int main() {
    
  n = 4; m =6;
  char arr[4][6];
  string word;
  getline(cin,word);
    
  for(int i = 0; i < word.length();i++){
    ele.push_back(word[i]);
  }
    
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 4;j++){
      cin>>arr[i][j];
    }
  }
    
  if(isPointValid(arr, 0, 0)){
        
    for(int i = 0; i < 4; i++){
      for(int j = 0; j < 6;j++){
	cout<<arr[i][j];
      }
      cout<<endl;
    }
        
  }
    
    
  return 0;
}

bool isPointValid(char arr[][6], int i, int j){
    
  //Every pointbefore this is valid
    
  if(i>n-1 || j>m-1 || i<0 || j<0)
    return false;
    
  if(i==n-1 && j==m-1){
        
    if(ele.size()==1){
      if(ele.front()==arr[n-1][m-1]){
	auto it = find(ele.begin(),ele.end(),arr[i][j]);

	if (it != ele.end()) {
	  ele.erase(it);
	}
	return true;}
    }
        
    return false;
                
  }
    

  if(ele.find(arr[i][j])!=ele.end()){

    ele.erase(arr[i][j]);
        
    if(isPointValid(arr, i+1,j)){
      arr[i][j] = 'X';
      return true;
    }
        
    else if(isPointValid(arr, i,j-1)){
      arr[i][j] = 'X';
      return true;
    }
        
    else if(isPointValid(arr, i-1,j)){
      arr[i][j] = 'X';
      return true;
    }
        

    else if(isPointValid(arr, i,j+1)){
      arr[i][j] = 'X';
      return true;
    }
        
    else{
      ele.insert(pair<char, int>(arr[i][j],1));
      return false;
    }
        
  }

  return false;

}


