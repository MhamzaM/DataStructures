#include<iostream>
#include<math.h>

using namespace std;


struct node{

	int value;
	node* left;
	node* right;

};

class CBT {
	int Num_curNodes; //n will use to calculate num of half nodes that can accumudate in a level 
public:
	node *root,*temp,*last,*P_last;
	int level;

	CBT(){
		root=temp=NULL;
		Num_curNodes=level=0;
	}


	void insert (node *& point, int num,int L,int n){

		if(root==NULL){
			
			
			root=new node;
			root->value=num;
			root->left=NULL;
			root->right=NULL;
			level++;

			P_last=root;
			last=root;
			return;
		}

		//-------------

		if(Num_curNodes == pow(2,level)){
		
			level++;
			Num_curNodes=0;
		
		}


		if( n-1 == 0 ){
		
			if(point->left==NULL){
			
				point->left=new node;
				point->left->value=num;
				point->left->left=NULL;
				point->left->right=NULL;
				
				P_last=point;
				last=point->left;
			}

			else {
			

				point->right=new node;
				point->right->value=num;
				point->right->left=NULL;
				point->right->right=NULL;

				P_last=point;
				last=point->right;			
			}

			Num_curNodes++;
			
			if(Num_curNodes == pow(2,level)){
			
				level++;
				Num_curNodes=0;
			}

	
			return;
		}

		//--------------------
	
		if(Num_curNodes < (pow(2,L) - pow(2,n-1))){

				
			insert(point->left,num,L-1,n-1);
		
		}
		else {
		
			

			insert(point->right,num,L,n-1);
		
		}
	
	}


	//---------Insertion----------

	

	//---------Delete---------

	void del_node(node* point,int num){
	
		temp=NULL;
		search(point,num);  //search ka function temp ko us number p khara kr da ga jisa delete krna ha 


		if(temp==NULL){
			cout<<"NUMBER NOT FOUND"<<endl;
			return;
		
		}

		else{
			cout<<"Search ki value :"<<temp->value<<endl;
		
			if(temp == root && root->left == NULL && root->right == NULL){
			
				root=NULL;
				last=NULL;
				P_last=NULL;

			}

			if(temp != last){
			
				temp->value=last->value;
			}
	
			if(P_last->left==last){
				
					P_last->left=NULL;
			}
			else{
				
					P_last->right=NULL;
			}

				delete last;
				last=temp=NULL;
			

				Num_curNodes--;


			if(Num_curNodes==0){
				cout<<"Level decreased"<<endl;
				level--;
				if(level >= 0){
					Num_curNodes=pow(2,level);
				}
				}
		
				
			
		}

		cout<<"Number of curent nodes after deletion: "<<Num_curNodes<<endl;

	
		if(root==NULL){
		
			last=NULL;
			P_last=NULL;
		}
		else{
			temp=last=P_last=root;
			int lev=level;
			setLast(lev,lev);
		}

		
	}


	//---------Delete---------


	//--------Set Last pointer-------
	//Set last pointer to last node and P_last pointer to its parent;

	void setLast(int n,int L){
	
		
		if( n == 0 ){
			
			last=temp;
			cout<<"parent :"<<P_last->value<<endl;
			cout<<"last :"<<last->value<<endl;

			return;
		}

		//--------------------
	
		P_last=temp;

		if(Num_curNodes <= (pow(2,L) - pow(2,n-1))){

				temp=temp->left;
			setLast(n-1,L-1);
		
		}
		else {
		
			
			temp=temp->right;
			setLast(n-1,L);
		
		}

	}


	//--------Set Last pointer-------
	//--------Search---------------


	void search (node *point,int num){
	
		if(root==NULL){
		
			cout<<"Tree is empty "<<endl;
			return;
		}


		if(point->value==num){
		
			temp=point;
			return;
		
		}

		if(point->left != NULL){
		
			search(point->left,num);

		}
		
		if(point->right != NULL){
		
			search(point->right,num);

		}


	}

	//--------Search---------------

	//---------Transverse-------------
	void transverse (node *point){
	
		if(point==NULL){
		
			cout<<"Tree is empty"<<endl;
			return;
		
		}

			cout<<point->value<<endl;

		if(point->left!=NULL){
		
			
			transverse(point->left);
		}

	

		if(point->right!=NULL){
		
			
			transverse(point->right);
		}

	}

	//---------Transverse-------------

	
	void dekh(){

	cout<<"parent: "<<P_last->value<<endl;
	cout<<"last: "<<last->value<<endl;

	}
};




void main(){

	CBT obj;
	int i=0;


	for(int j=0;j<9;j++){
	
		cin>>i;
		obj.insert(obj.root,i,obj.level,obj.level);
		
	}
	
	cout<<"Last is : "<<obj.last->value<<endl;

	obj.transverse(obj.root);


	obj.del_node(obj.root,9);
	cout<<"Last is : "<<obj.last->value<<endl;
	obj.transverse(obj.root);

	obj.del_node(obj.root,1);
	cout<<"Last is : "<<obj.last->value<<endl;
	obj.transverse(obj.root);
	
	cout<<"\n\n\n";
	obj.insert(obj.root,48,obj.level,obj.level);
	obj.dekh();

	obj.transverse(obj.root);

	obj.del_node(obj.root,6);
	cout<<"Last is : "<<obj.last->value<<endl;
	obj.transverse(obj.root);
	
	
	system("pause");
}