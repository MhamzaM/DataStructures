#include<iostream>

using namespace std;


class queue{
	int max,*que, *front,*rear,*temp;
	
public:
	queue(){
		max=6;
		que=new int[max];
		front=rear=temp=NULL;

	}

	void enqueue(){
	
		if(rear==NULL){
		rear=que;
		cin>>*rear;
		front=rear;
		return;
		}

		if(((rear+1)==front)||(front==que && rear==que+max-1)){
			
			cout<<"Queue Overflow"<<endl;
			return;
		
		}

		if(rear==que+max-1){
		rear=que;
		}
		else
		rear++;
		
		cin>>*rear;
		return;
	}


	void dequeue(){

		if(front==NULL){
		cout<<"Queue Underflow"<<endl;
		
		}

		else if(front==rear){
		front=rear=NULL;
		}

		else if(front==que+max-1){
		front=que;
		}

		else{
		front++;
		}
	
	}



	void print(){
		if(front==NULL){
		cout<<"Queue is empty"<<endl;
		return;
		}

		cout<<"\n"<<*front<<endl;
	
	}


	

};


void main(){

	queue obj;
	for(int i=0;i<6;i++){
	obj.enqueue();
	}
	
	obj.print();

	for(int i=0;i<4;i++){
	obj.dequeue();
	}
	
	obj.print();

	for(int i=0;i<3;i++){
	obj.enqueue();
	}
	obj.print();
	system("pause");
}