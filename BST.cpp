#include<iostream>

using namespace std;


struct node{
	char value;
	node *left;
	node *right;


};


class BST{
node *temp,*temp2;
char ch;

public:
	node *root;
BST(){

	   root=temp=temp2=NULL;

	  ch=' '; 
}

void insert(char val,node *&ptr){
	if(ptr==NULL){
	ptr=new node;
	ptr->value=val;
	ptr->left=ptr->right=NULL;

	return;
	}
	
		if(val==ptr->value){
		cout<<"Number already exists"<<endl;
		
		}
	
		else if(val<ptr->value){
		insert(val,ptr->left);
		}

		else if(val>ptr->value){
		insert(val,ptr->right);
		}
	

}// insertion functioin

void del_node(char val,node *&point){
	

	if(root==NULL){
	cout<<"Tree is Empty"<<endl;
	return;
	}

	if(point==NULL){
	cout<<"Value doesn't exist"<<endl;
	return;
	}

	if(point->value==val){

	if(point->left==NULL && point->right==NULL){
	
		if(point==root){

		root=NULL;
		delete point;
		point=NULL;
		return;
		}

		delete point;
		point=NULL;
	
	}

	else if(point->left==NULL){
		temp=point;
		point=point->right;
		delete temp;
		temp=NULL;

	}
	else if(point->right==NULL){
		temp=point;
		point=point->left;
		delete temp;
		temp=NULL;
	
	}

	else{

		temp=find_imd_successor(point->right);

		ch=temp->value;
		
		del_node(temp->value,root);

		point->value=ch; 
		
	}
	
	
	
	}//main if


	else if(val<point->value){
	del_node(val,point->left);
	}

	else if(val>point->value){
	del_node(val,point->right);
	}

}//delete function

node*  find_imd_successor(node *find){
	if(find->left==NULL){
	
		return find;
	}
	temp2=find;
	return find_imd_successor(find->left);

}//finding imidiate successor


void transverse(node* point){

	if(root==NULL){
	cout<<"Tree is empty"<<endl;
	return;
	}

	

	if(point->left!=NULL){
	
	transverse(point->left);
	}

	cout<<point->value<<" ";

	if(point->right!=NULL){
	transverse(point->right);
	}

}// transverse


};


void main(){

	
	
	BST obj;
	char ch=' ';
	for(int i=0;i<3;i++){

	cin>>ch;
	obj.insert(ch,obj.root);
	}

	obj.transverse(obj.root);

	obj.del_node('c',obj.root);
	cout<<endl;

	obj.transverse(obj.root);
	

	system("pause");
}