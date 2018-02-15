#include<iostream>
using namespace std;
int main(){
int n=5;
int j = 0;
int prev = 0;

int arr[n]={5,3,2,4,1};
for(int i=0; i<n-1; i++) 
{
j++;
if( j < n)
{ 
i = prev;
}
else
{
j = i + 1;
}
if(arr[i] > arr[j]) 
{ 
int temp = arr[i]; 
arr[i] = arr[j]; 
arr[j] = temp;
} 
prev = i;
}
for(int i=0; i<5; i++){
cout<< arr[i] << " ";
}
}