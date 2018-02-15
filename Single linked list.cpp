#include<iostream>
using namespace std;


struct node{
int value;
node *next;
};

class LinkedList{
private:
	node *head,*temp,*temp2;
public:
	LinkedList(){
		head=NULL;
		temp=NULL;
		temp2=NULL;
	}

	void add(){
	
		if(head==NULL){
		
			head=new node;
			cin>>head->value;
			head->next=NULL;
			temp=head;
			return;
		}
		
		if(temp->next!=NULL){
			while(temp->next!=NULL){
			temp=temp->next;
			}
		}
		
		temp2=new node;
		cin>>temp2->value;
		temp2->next=NULL;
		temp->next=temp2;
		temp=temp2;
	}

	void add_AV(int val){
	
		temp=head;
		
			
		while(temp!=NULL){
			if((temp->value)==val){
				temp2=new node;
				cin>>temp2->value;
				temp2->next=temp->next;
				temp->next=temp2;

			break;
			}
			
		temp=temp->next;
		}
		
			
	}

	void del_1st(int val){
	temp=head;

	if (head==NULL){
	cout<<"List is empty"<<endl;
	return;
	}	

	if(temp->value==val){

	head=head->next;
	delete temp;
	return;
	}

	
	while(temp!=NULL){
	
		if(temp->next!=NULL){
		if(temp->next->value==val){
			
		temp2=temp->next;	
		temp->next=temp2->next;
		delete temp2;
		return;
		}
		}
		temp=temp->next;
	}
	
	cout<<"Value doesn't exists"<<endl;
	}//function end

	void print(){
		temp=head;
		while(temp->next!=NULL){
		
		cout<<temp->value<<" ";
		temp=temp->next;
		if(temp->next==NULL){
		cout<<temp->value<<endl;
		}
		}
	}
};




void main(){

LinkedList obj;

obj.add();//1

obj.add();//2
obj.add();//3
obj.add();//4
obj.add();//3
obj.print();
cout<<"After Value.."<<endl;

obj.add_AV(5);//3
cout<<"\n\n\n\n\n";
obj.print();

cout<<"\nDelete"<<endl;

obj.del_1st(1);

obj.print();

obj.del_1st(3);

obj.print();

obj.del_1st(6);

obj.print();

system("pause");
}