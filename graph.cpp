#include<iostream>

using namespace std;


struct edge{
int value;
edge *next;
};

//===============================================ROW LIST================================================
class Row_List{
public:
	edge *head,*temp,*temp2;

	Row_List(){
		head=NULL;
		temp=NULL;
		temp2=NULL;
	}

	void add(int vertex){
	
		if(head==NULL){
		
			head=new edge;
			head->value=vertex;
			head->next=NULL;
			temp=head;
			return;
		}
		
		if(temp->next!=NULL){
			while(temp->next!=NULL){
			temp=temp->next;
			}
		}
		
		temp2=new edge;
		cin>>temp2->value;
		temp2->next=NULL;
		temp->next=temp2;
		temp=temp2;
	}

	


	void del_1st(int vertex){
	temp=head;

	if (head==NULL){
	cout<<"List is empty"<<endl;
	return;
	}	

	if(temp->value==vertex){

	head=head->next;
	delete temp;
	return;
	}

	
	while(temp!=NULL){
	
		if(temp->next!=NULL){
		if(temp->next->value==vertex){
			
		temp2=temp->next;	
		temp->next=temp2->next;
		delete temp2;
		return;
		}
		}
		temp=temp->next;
	}
	
	cout<<"Edge doesn't exists"<<endl;
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

//====================================================Column LIST===============================================

struct node{

	char info;
	Row_List *obj_edge;
	node *next;
};

class Column_list{

	node *head,*temp,*temp2;
	
public:
	Column_list(){
	
		head=NULL;
		temp=NULL;
		temp2=NULL;
	}

	void add(int vertex){
	
		if(head==NULL){
		
			head=new node;
			head->info=vertex;
			head->next=NULL;
			head->obj_edge=NULL;
			temp=head;
			return;
		}
		
		if(temp->next!=NULL){
			while(temp->next!=NULL){
			temp=temp->next;
			}
		}
		
		temp2=new node;
		temp2->info=vertex;
		temp2->next=NULL;
		temp2->obj_edge=NULL;
		temp->next=temp2;
		temp=temp2;
	}


	//-------------------------------------------
		void del_node(int vertex){
	temp=head;

	if (head==NULL){
	cout<<"Graph is empty"<<endl;
	return;
	}	

	if(temp->info==vertex){

	head=head->next;
	
	if(temp->obj_edge != NULL){
	delete temp->obj_edge;
	}
	
	delete temp;

	return;
	}

	
	while(temp!=NULL){
	
		if(temp->next!=NULL){
		if(temp->next->info==vertex){
			
		temp2=temp->next;	
		temp->next=temp2->next;

			if(temp2->obj_edge != NULL){
			delete temp2->obj_edge;
			}

		delete temp2;
		return;
		}


		}
		temp=temp->next;
	}
	
	cout<<"Node doesn't exists"<<endl;
	}//function end


		//--------------------------------

		void add_adj(int vertex,int adj){  // adding edge

			temp=head;
			bool chk_adj=0;

			if(temp == NULL){
			
				cout<<"NO node exists"<<endl;
				return;
			}
			while(temp != NULL){           // checking if the terminal node exists or not
	
				
				
				cout<<"searching adj"<<endl;
				if(temp->info == adj){
				
					chk_adj=1;
					break;
				}

				if(temp->next == NULL && !chk_adj){
				
					cout<<"Adjacent node doesn't exists"<<endl;
					return;
				
				}
			
				temp=temp->next;
			}


			if(chk_adj){
			temp=head;
			while(temp != NULL){           // searching the starting node 
			
				cout<<"searching starting"<<endl;

				if(temp ->info == vertex){
				
					if(temp->obj_edge == NULL){
					
						temp->obj_edge=new Row_List;
						temp->obj_edge->add(adj);
						return;
					}

					temp->obj_edge->add(adj); 
					return;

				}

				
				if(temp->next == NULL){
				
					cout<<"Vertex dosen't exists"<<endl;

				}
			
				temp=temp->next;
			}
			}//if
	
		}
	//--------------------------------------

		void del_adj(int vertex,int adj){
		
		 
			temp=head;
			bool chk_adj=0;
			
			if(temp == NULL){
			
				cout<<"NO node exists"<<endl;
				return;
			}

			while(temp != NULL){           // checking if the terminal node exists or not
			
				
				if(temp->info == adj){
				
					chk_adj=1;
					break;
				}

				if(temp->next == NULL && !chk_adj){
				
					cout<<"Adjacent node doesn't exists"<<endl;
					return;
				
				}
			
				temp=temp->next;
			}


			if(chk_adj){
			temp=head;
			while(temp != NULL){           // searching the starting node 
			
				
				if(temp ->info == vertex){
				
					temp->obj_edge->del_1st(adj);
					break;
				}

				
				if(temp->next == NULL){
				
					cout<<"Vertex dosen't exists"<<endl;
				}
			
				temp=temp->next;
			}
			}//if
		
		}


	//-------------------------------------
		void print(){
		temp=head;
		while(temp->next!=NULL){
		
		cout<<temp->info<<" ";
		temp=temp->next;
		if(temp->next==NULL){
		cout<<temp->info<<endl;
		}
		}
	}
};


class Graph{

	Column_list obj;
	int vertex;
	int adj_node;

public:
	
	Graph(){
	
		adj_node=NULL;
		vertex=NULL;
	}
	void add_node(){

		cout<<"Node addition"<<endl;
		cout<<"Enter node value: ";
		cin>> vertex;

		obj.add(vertex);
	cout<<"\n\n"<<endl;
		
	}

	void add_edge(){
	
		cout<<"Edge addition"<<endl;
		
		cout<<"Enter Node: ";
		cin>>vertex;
		cout<<"Enter adjacent Node:";
		cin>>adj_node;

		obj.add_adj(vertex,adj_node);
	cout<<"\n\n"<<endl;
		
	}

	void del_node(){
	
		cout<<"Node Deletion"<<endl;
		
		cout<<"Enter node: "<<endl;
		cin>> vertex;

		obj.del_node(vertex);
		cout<<"\n\n"<<endl;
		
	}

	void del_edge(){
	
		cout<<"edge deletion"<<endl;
		
		cout<<"Enter Node : ";
		cin>>vertex;
		cout<<"Enter adjacent Node: ";
		cin>>adj_node;

		obj.del_adj(vertex,adj_node);
			cout<<"\n\n"<<endl;
		
	
	}
};

void main(){
	int a;
	Graph obj;

	obj.del_edge();
	obj.add_edge();
	obj.add_node();
	obj.add_node();
	obj.add_edge();
	obj.del_edge();
	obj.del_node();
	obj.del_node();
	obj.del_node();

	cin>>a;
	system("pasue");
}