#include<iostream>

using namespace std;



class stack{
private:
	int *stk;
	int maxlen;
	int len;
	int* top;
public:
	stack(){
	
	top=NULL;
	maxlen=5;
	len=0;
	stk=new int[maxlen];
	}



	void push(){
	
		if(top==(stk+(maxlen-1))){
		cout<<"\nStack Overflow"<<endl;
		return;
		}
		if(top==NULL){
		top=stk;
		cin>>*top;
		len++;
		return;
		}

		top++;
		cin>>*top;
		len++;

	}//Push ENd

	void pop(){
	
		if(top==NULL){
		cout<<"Stack Underflow"<<endl;
		return;
		}

		if(top==stk){
		top=NULL;
		return;
		}
	top--;
	len--;

	}//Push End

	void print(){ 
	
		if(top==NULL){
		cout<<"Stack is Empty"<<endl;
		return;
		}
		cout<<*top;

	}

	
	
};


void main(){

	stack obj;
	
	
	obj.push();
	obj.push();
	obj.push();
	obj.push();
	obj.push();
	obj.print();

	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.print();

	obj.pop();
  

	

	system("pause");
}
