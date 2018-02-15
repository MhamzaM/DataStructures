#include<iostream>

using namespace std;



class min_heap{
	int *arr,size,len,cur;

public:
//	void maintain_heap();
//	void print();
	min_heap(){
	
		size=20;
		len=0;
		cur=1;
		arr=new int[size];
	
	}

	void insertion(int num){
	
		if(len == size-1){
		cout<<"Heap is full"<<endl;
		return;
		}

		else{
		
			arr[cur]=num;
			len++;
			
			int parent=cur/2,child=cur;
		
			if(len != 1){
			

				while(arr[child] < arr [parent]){
				
					swap(child,parent);
					child=parent;
					parent/=2;
				}
			
			}
			cur++;
		}

	}


	void del_min(){
	

		

		if(len==0){
		
			cout<<"Heap is empty"<<endl;
			return;

		
		}

		else{
			cout<<arr[1]<<endl;
			arr[1]=arr[len];
			
			arr[len]=-1;
			len--;
			cur--;
			if(len!=0){

			maintain_heap();
			
			}
			
		
	
	}
	}
	void maintain_heap(){
	
		for(int i=len/2;i>0/2;i--){
		
			if(arr[i] > arr[i*2] && arr[i*2] != -1){
			
			swap(i,i*2);
			}
			
			if(arr[i] > arr[i*2+1] && arr[i*2+1] != -1){
			
			swap(i,i*2+1);
			}
		}
	}

	void swap(int child,int parent){
	
		int temp=arr[child];
		arr[child]=arr[parent];
		arr[parent]=temp;

	}



	void print(){
	
		for(int i=1;i<=len;i++){
		
			cout<<arr[i]<<" ";
		
		}
	cout<<endl;
	}
};

void main(){

	int i;
	min_heap obj;

	for(int j=0;j<5;j++){
	
		cin>>i;
		obj.insertion(i);
		
	}

	//obj.print();
	obj.del_min();



//	obj.print();

	obj.insertion(45);
//	obj.print();


		for(int j=0;j<5;j++){
	
		obj.del_min();
	//	obj.print();
	}

	/*

	obj.del_min();
	obj.print();

	obj.del_min();
	obj.print();

	obj.insertion(46);
	obj.print();

	obj.del_min();
	obj.print();

	obj.del_min();
	obj.print();

	obj.del_min();
	obj.print();
	
	obj.del_min();
	obj.print();
	
	*/
	
	system("pause");

}