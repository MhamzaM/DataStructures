#include<iostream>

using namespace std;


void mergeSort(int *arr,int left,int right){

	
	if(left < right){

	
		int half=left+right/2;
		mergeSort(arr,left,half);
		mergeSort(arr,half+1,right);
		merge(arr,left,half,right);
	}
	
return;


}//-----------


void merge (int *arr,int left,int mid,int right){

	int len1=mid-left +1;
	int len2=right-mid;

	int *a1,*a2;

	a1=new int[len1];
	a2=new int[len2];

	int i=0,j=0,k=left;


	for(i;i<len1;i++){
	
		a1[i]=arr[k+i];
	}

	for(j;j<len2;j++){
	
		a2[j]=arr[k+j];

	}


	i=j=0;

	while(i < len1 && j < len2){
	
		if(a1[i]<a2[j]){
		
			arr[k]=a1[i];
			i++;
		}

		else{
		arr[k]=a1[j];
		j++;
		}
		
		k++;
	}

	while(i<len1){
	
		arr[k]=a1[i];
		i++;
		k++;
	}

	while(j<len2){
	
		arr[k]=a2[j];
		j++;
		k++;
	}

}


void main(){

	int *arr=new int[10];

	
	arr[0]=9;
	arr[1]=8;
	arr[2]=7;
	arr[3]=6;
	arr[4]=5;
	arr[5]=3;
	arr[6]=2;
	arr[7]=1;
	arr[8]=4;
	arr[9]=0;	
	
	mergeSort(arr,0,9);

	for(int i=0;i<10;i++){
	
	
		cout<<arr[i]<<" ";

	}

	system("pause");
}

