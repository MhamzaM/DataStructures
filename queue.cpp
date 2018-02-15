#include<iostream>

using namespace std;

struct node{
int value;
node *next;

};

class queue{
	node *front,*rear,*temp;
public:
	queue(){
	
	front=rear=NULL;

	}

	void enqueue(){
	
		if(rear==NULL){
		rear=new node;
		cin>>rear->value;
		rear->next=NULL;
		front=rear;
		return;
		}
		rear->next=new node;
		rear=rear->next;
		cin>>rear->value;
		rear->next=NULL;

	
	}


	void dequeue(){
	
		if(front==NULL){
		
		cout<<"Queue Underflow"<<endl;
		return;
		}

		temp=front;
		front=front->next;
		if(temp==rear){
		rear=front;
		}
		delete temp;
	
	}



	void print(){
	
		if (rear==NULL){
		cout<<"QUeue is Empty"<<endl;
		return;
		}

		cout<<rear->value<<endl;
	}


	

};


void main(){

	queue obj;

	obj.enqueue();

	obj.print();

	obj.dequeue();

	obj.print();

	
	obj.enqueue();

	obj.print();
	system("pause");
}