#include<iostream>
using namespace std;


struct node{
int value;
node *next;

};

class SRL{
private:
	node *head,*temp,*temp2;
public:
	SRL(){
		head=NULL;
		temp=NULL;
		temp2=NULL;
	}

	void add(){
	
		if(head==NULL){
		
			head=new node;
			cin>>head->value;
			head->next=head;
			temp=head;
			return;
		}
		
		if(temp->next!=head){
			while(temp->next!=head){
			temp=temp->next;
			}
		}
		
		temp2=new node;
		cin>>temp2->value;
		temp2->next=temp->next;
		temp->next=temp2;
		temp=temp2;
	}

	void add_AV(int val){
	
		temp=head;
		
		if(head==NULL){
		cout<<"\nList is empty"<<endl;
		return;
		}
		
		do{
			if((temp->value)==val){
			temp2=new node;
			cin>>temp2->value;
			temp2->next=temp->next;
			temp->next=temp2;
			break;
			}
			
		temp=temp->next;
		}while(temp!=head);

		
	}

	void del_1st(int val){
	temp=temp2=head;
		
	if(head==NULL){

	cout<<"List is Empty"<<endl;
	return;
	}
	

	if(temp->value==val &&  temp==head){
		
				if(head->next==head){
				delete head;
				head=temp=temp2=NULL;
				return;
				}
			
				
				while(temp2->next!=head){			//akhr wala ko wapis head k sath connect krna ha
				temp2=temp2->next;
				}
			
				temp2->next=head->next;
				head=head->next;
				delete temp;
				return;
				

	}
			
	
	do{
		if(temp->next!=head){
		if(temp->next->value==val){	
		temp2=temp->next;	
		temp->next=temp2->next;
		delete temp2;
		return;
		}
		}

		temp=temp->next;
	}while(temp!=head);
	
	cout<<"Value doesn't exists"<<endl;
	}//function end

	void print(){
		temp=head;
		

		do{
		
		cout<<temp->value<<" ";
		temp=temp->next;
		if(temp->next==head){
		cout<<temp->value<<endl;
		}
		}while(temp->next!=head);
	}
};




void main(){

SRL obj;

obj.add();//1
obj.add();//2
obj.add();//3
obj.add();//4
obj.add();//3
obj.print();
cout<<"After Value.."<<endl;

obj.add_AV(1);//3

cout<<"\n\n\n\n\n";
obj.print();


cout<<"\nDelete"<<endl;

obj.del_1st(1);

obj.print();

obj.del_1st(4);

obj.print();

obj.del_1st(6);

obj.print();

system("pause");
}