/// Example program
#include <iostream>
#include <string>
#include <ctype.h>
#include<vector>
using namespace std;

int func(string f, string sec, int n, int m);
int parsed(string s);
int checkPalin(int start, int t, string s);

int main()
{
    
  string s;
  getline(cin,s);
    
  parsed(s);
    
  return 0;
}

int func(string s, int n){
    
  int start = 0;
  int counter = 1;
  vector<pair<int, int>> vec;
  string temp;
    
  while(start < n){
        
    if(start!=0 && isalnum(s[start-1])){
      start++;
      continue;
    }
        
    if(!isalnum(s[start])){
      start++;
      continue;
    }
        
    int end[100];
    int m = 0;
        
    for(int i = start+1; i < n; i++){
      if(s[start]==s[i]){
	if(!isalnum(s[i+1])){
	  end[m] = i;
	  m++;}
      }
    }
    if(m==0){
      start++;
      continue;
    }
    m--;
    /*for(int i = 0; i < n; i++){
            
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            temp+=s[i];
            
	    }*/
        
    while(m>=0){
            
      int t = end[m];
      if(checkPalin(start, t,s))
	vec.push_back(make_pair(start, t));
      m--;
    }
        
    if(vec.capacity()==0){
      cout<<"Na bro";
      return 0;
    }
        

    start++;
  }
    
  int max = 0;
  int check, mate;
  for(int i = 0; i < vec.capacity(); i++){
        
    if(vec[i].first + vec[i].second > max){
      max = vec[i].first + vec[i].second;
      check = vec[i].first;
      mate = vec[i].second;
    }
        
  }
    
  for(int i = check; i < mate+1; i++){
    char ch = (char)s[i];
    cout<<ch;
  }
    
  return 1;
}

int checkPalin(int start, int t, string s){
    
  int counter = 1;
  while(start < t){
        
    if(!isalnum(s[start])){
      start++;
      continue;
    }
        
    if(!isalnum(s[t])){
      t--;
      continue;
    }
        
        
    if(s[start]==s[t]){
      start++;
      t--;
      continue;
    }
    else{
      counter = 0;
      break;
    }
        
  }
  return (counter==1);
    
}

int parsed(string s){
  int l = s.length();
  int i = 0;
    
  while(i<l){
    if(!isalnum(s[i])){
      i++;
      continue;}
    else
      s[i]=(char)tolower(s[i]);
        
    i++;}
    
  int res = func(s,l);
  return res;
}
