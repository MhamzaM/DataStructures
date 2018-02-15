#include<iostream>
using namespace std;


struct node{
	
int value;
node *left;
node *right;
bool Lthread;
bool Rthread;
};

class TBT{

		node *temp,*temp2;int imid;
		


public:
		node *root,*dummy;
		
		TBT(){
			root=dummy=temp=temp2=NULL;
			imid=NULL;
			
		
		}

		void insert(node* point,int num){
		
			if(root==NULL){
				
				root=new node;
				root->value=num;
			
				dummy=new node;
				dummy->value=NULL;
				dummy->right=dummy;
				dummy->left=root;
				dummy->Lthread=0;
				dummy->Rthread=0;

				root->left=dummy;
				root->right=dummy;
				root->Lthread=1;
				root->Rthread=1;
				return;
			}
			
	

			if(point->value==num){
			cout<<"Value already exists"<<endl;
			
			}

			else if(num<point->value){
			
				if(point->Lthread){
			
					temp=new node;
					temp->value=num;
					temp->left=point->left;
					temp->Lthread=1;
					temp->right=point;
					temp->Rthread=1;
					point->left=temp;
					point->Lthread=0;
					return;
				}
				insert(point->left,num);

			}

			else if(num>point->value){
			
				if(point->Rthread){
					
					
					temp=new node;
					temp->value=num;
					temp->right=point->right;
					temp->Rthread=1;
					temp->left=point;
					temp->Rthread=1;
					point->right=temp;
					point->Rthread=0;
					return;

				}

				insert(point->right,num);
			}
		}//insertion


		//Deletion


		void del_node(node *&point,int num,int Pval=NULL){
		
			bool L_T=0,R_T=0;  // to check whether to set left and right thread bools of node or not when coming back after deletion

			if(root==NULL){
			
				cout<<"Tree is empty"<<endl;
				return;
			}
		
			if(point->value==num){
			
				if(point->Lthread && point->Rthread){
				
					if(point==root){
					delete root;
					root=NULL;
					delete dummy;
					dummy=NULL;
					point=NULL;
					return;
					}

					if(point->value<Pval){
					
						temp=point;
						point=point->left;
						delete temp;
						temp=NULL;
						return;
					}
					
					if(point->value>Pval){
					
						temp=point;
						point=point->right;
						delete temp;
						temp=NULL;
					
					}
				}

				else if(point->Lthread && !point->Rthread){
				
					temp=find_imd_successor(point->right);
					temp->left=point->left;

					temp2=point;
					point=point->right;
					delete temp2;
					temp2=NULL;
					if(dummy->left!=root){
					dummy->left=root;
					}
					
				
				}

				else if(!point->Lthread && point->Rthread){
					
					temp=find_imd_decessor(point->left);
					temp->right=point->right;

					temp2=point;
					point=point->left;
					delete temp2;
					temp2=NULL;

					if(dummy->left!= root){
					dummy->left=root;
					}

					
				
				}

				else{										  //(!point->Lthread && !point->Rthread)
				
					temp=find_imd_successor(point->right);
					imid=temp->value;
					del_node(root,temp->value);
					point->value=imid;
				}

			}
			


			else if(num<point->value){
				if(point->Lthread){
				
					cout<<"Number doesn't exists"<<endl;
					return;
				}

				if(point->left->value==num && point->left->Lthread && point->left->Rthread){
					L_T=1;
				}
				del_node(point->left,num,point->value);
			}

			else if(num>point->value){
				
				if(point->Rthread){
				
					cout<<"Number doesn't exists"<<endl;
					return;
				}
				
				if(point->right->value==num && point->right->Rthread && point->left->Rthread){
					R_T=1;
				}
				del_node(point->right,num,point->value);
			}

			if(L_T){
				point->Lthread=1;
			
			}

			if(R_T){
				point->Rthread=1;
			
			}
			
		}// deletion

		//finding imidiate decessor

		node* find_imd_decessor(node* find){
			if(find->Rthread){
	
				return find;
			}
			
			return find_imd_successor(find->right);		
		
		
		}

		//finding imidiate decessor



		//finding imidiate successor
		node*  find_imd_successor(node *find){
			if(find->Lthread){
	
				return find;
			}
			
			return find_imd_successor(find->left);

		}//finding imidiate successor



		//Inorder transversal
		node* nextInorder(node* point){
		
			if(point->Rthread){
			
				return point->right;
			}

			point=point->right;


			while(!point->Lthread){
		
				point=point->left;

			}

			return point;
		}

		void transverse(node *point){
		
			while(((point=nextInorder(point))!=dummy)){
				
				cout<<point->value<<endl;
		}
		}

};

void main(){

	TBT obj;


	int n=0;

	for(int i=0;i<11;i++){
	
		cin>>n;
		obj.insert(obj.root,n);

	}


	obj.transverse(obj.dummy);
	cout<<endl;


	obj.del_node(obj.root,15);

	obj.transverse(obj.dummy);
	cout<<endl;

	obj.del_node(obj.root,14);

	obj.transverse(obj.dummy);
	cout<<endl;

	obj.del_node(obj.root,3);
	
	obj.transverse(obj.dummy);
	cout<<endl;

	obj.del_node(obj.root,5);

	obj.transverse(obj.dummy);
	cout<<endl;

	obj.del_node(obj.root,20);

	obj.transverse(obj.dummy);
	cout<<endl;

	obj.del_node(obj.root,19);

	obj.transverse(obj.dummy);
	cout<<endl;

	cout<<"Last insertion"<<endl;
	obj.insert(obj.root,19);
	
	obj.transverse(obj.dummy);
	cout<<endl;

	system("pause");
}