#include<iostream>

using namespace std;

struct node{
int value;
node *beneath;

};



class stack{
private:
node *top,*temp;
public:
	stack(){
	top=temp=NULL;
	
	}



	void push(){
	
		if(top==NULL){
		top=new node;
		cin>>top->value;
		top->beneath=NULL;
		return;
		}

		temp=new node;
		cin>>temp->value;
		temp->beneath=top;
		top=temp;

	}//Push ENd

	void pop(){
	
		if(top==NULL){
		cout<<"Stack Underflow"<<endl;
		return;
		}

		top=top->beneath;
		delete temp;
		temp=top;
	}//Push End

	void print(){
	
		if(top==NULL){
		cout<<"Stack is Empty"<<endl;
		return;
		}
		cout<<top->value;

	}



};


void main(){

	stack obj;

	obj.push();
	obj.print();
	obj.pop();

	obj.print();
	obj.pop();
	system("pause");
}
