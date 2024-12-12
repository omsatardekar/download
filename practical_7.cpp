#include <iostream> 
#include<map> 
using namespace std; 
int main() 
{ 
  map<string,int> state; 
  state.insert(pair<string,int>("Maharashtra",1000)); 
  state.insert(pair<string,int>("Goa",179)); 
  state.insert(pair<string,int>("Gujrat",986)); 
  state.insert(pair<string,int>("Panjab",905)); 
  state.insert(pair<string,int>("Delhi",953)); 
   
   
  string search; 
  cout<<"Enter the state to be searched:"; 
  cin>>search; 
  map<string,int>::iterator i; 
  int f=0; 
  for(i=state.begin();i!=state.end();i++) 
  { 
    if(search==i->first) 
    { 
      f++; 
      cout<<"The population of "<<i->first<<"="<<i->second; 
    } 
  } 
  if(f==0) 
 
    cout<<"State not found"; 
    return 0;} 