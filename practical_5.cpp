#include <iostream> 
using namespace std; 
template<typename t> 
void selection(t.array[],int n) 
{ 
  int min; 
  for(int i=0;i<n;i++) 
  { 
    min=i; 
    for(int j=i+1;j<n;j++) 
    { 
      if(array[j]<array[min]) 
      { 
        min=j; 
      } 
    } 
    t temp=array[i]; 
    array[i]=array[min]; 
    array[min]=temp; 
     
  } 
  cout<<"Array after sorting"; 
  for(int i=0;i<n;i++) 
  { 
    cout<<array[i]<<","; 
  } 
  cout<<endl; 
} 
int main() 
{ 
  int n; 
  cout<<"Enter the array length:"; 
  cin>>n; 
  int array[n]; 
  float arr[n]; 
  cout<<"Enter the integer array:"; 
  for(i=0;i<n;i++) 
  { 
    cin>>array[i]; 
  } 
  cout<<"Enter the float array:" 
  for(i=0;i<n;i++) 
  { 
    cin>>array[i]; 
  } 
   
  selection(array,n); 
  selection(arr,n); 
}