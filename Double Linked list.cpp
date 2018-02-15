#include<iostream>
using namespace std;

struct node{
int value;
node *next,*previous;
};

class DLL{
private:
	node *head,*temp,*temp2;
public:
	DLL(){
	head=temp=temp2=NULL;
	}

	void add(){

		
		if(head==NULL){
		head=new node;
		cin>>head->value;
		head->next=head->previous=NULL;
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
		temp->next=temp2;
		temp2->next=NULL;
		temp2->previous=temp;
		temp=temp2;
		

	}


	void addAV(int num){
		
		if(head==NULL){
		cout<<"List is Empty..."<<endl;
		return;
		}

	temp=head;
	
		
	while(temp!=NULL){
	
		
	if(temp->value==num){
		temp2=new node;
		cin>>temp2->value;
		temp2->next=temp->next;
		temp->next=temp2;
		temp2->previous=temp;

		if(temp2->next!=NULL)
		temp2->next->previous=temp2;
		
		break;
	}
	

	temp=temp->next;
	}
	


	}


	void deletFirst(int num){
	
		if(head==NULL){
		cout<<"List is Empty"<<endl;
		return;
		}

		temp=head;

		

		while(temp!=NULL){
			if (temp->value==num){
				
				if(temp==head){
					if(head->next!=NULL){
					temp->next->previous=temp->previous;
					}
					head=head->next;
					delete temp;
					
					break;
				}

				if(temp->next==NULL){
				temp->previous->next=temp->next;
				delete temp;
				break;

				}


				temp->previous->next=temp->next;
				temp->next->previous=temp->previous;
				delete temp;
				break;
			
			}

		temp=temp->next;
		}

	
	}




	void print(){
	temp=head;

	cout<<"\nIn Print";
	if(temp!=NULL){
	cout<<temp->value<<endl;
		
	while(temp->next!=NULL){
	
	temp=temp->next;
	cout<<temp->value<<endl;
	if(temp->next==NULL){ 
	cout<<temp->value<<endl;
	}

	}
	}
	else cout<<"List is empty"<<endl;

	}

};

void main(){

	DLL obj;

	obj.add();//1
	obj.add();
		obj.print();
	obj.deletFirst(1);
	obj.print();
	/*obj.add();//2
	obj.addAV(1);
	obj.addAV(3);
	obj.print();
	obj.add();//3
	obj.add();//4
	obj.addAV(4);//5
	

	obj.add();
	cout<<endl;
	obj.print();
	
	
	obj.print();

	obj.deletFirst(1);
	obj.print();

	obj.deletFirst(5);

	obj.print();

	obj.deletFirst(6);	
	obj.print();


	obj.add();
	obj.print();

	obj.addAV(4);//5
	obj.print();
	*/

system("pause");
}