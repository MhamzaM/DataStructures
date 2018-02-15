#include<iostream>


using namespace std;

struct node{

	int value;
	node* left;
	node* right;
	
};


class min_heap{
		int Num_curNodes; //n will use to calculate num of half nodes that can accumudate in a level 
public:
	node *root,*temp,*last,*P_last;
	int level;

	min_heap(){
		root=temp=NULL;
		Num_curNodes=level=0;
	}


	void insert (node *& point, int num,int L,int n){

		if(root==NULL){
			cout<<"in root"<<endl;
			
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

			if(point->left !=NULL && point->value > point->left->value){

			swap(point,point->left);

		}
		
		if(point->right !=NULL && point->value > point->right->value){
			
			swap(point,point->right);

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

	
		if(point->left !=NULL && point->value > point->left->value){

		swap(point,point->left);

		}
		
		if(point->right !=NULL && point->value > point->right->value){
			
			swap(point,point->right);

		}
		
		
	}


	//---------Insertion----------

	//--------swap--------

	void swap(node * parent,node * child){
	
		int xtra=0;

		xtra=parent->value;
		parent->value=child->value;
		child->value=xtra;
	
	}

	//--------swap--------
	
	
	//--------Delete min--------

	void del_min(){
	
		if(last==root){
		
			delete last;
			last=P_last=root=NULL;
			level--;
			return;
		
		}
		

		else{

		root->value=last->value;
	

		if(P_last->left==last){
				
				P_last->left=NULL;
		}
		else{
				
				P_last->right=NULL;
		}

			delete last;
			last=NULL;
			

			Num_curNodes--;


		if(Num_curNodes==0){
			cout<<"Level decreased"<<endl;
			level--;

			if(level >= 0){
				Num_curNodes=pow(2,level);
			}

			}
		
					
			temp=last=P_last=root;
			
			precolate_down(root);
			setLast(level,level);
		

		}
	
	}

	//---------Delete min----------

	//--------------------truncate down------------


	void precolate_down(node *point){
	
		if(point->left != NULL){
		
			if(point->value > point->left->value){
			
				swap(point,point->left);
				precolate_down(point->left);
			}
		}
		

		if(point->right != NULL){
		
			if(point->value > point->right->value){
			
				swap(point,point->right);
				precolate_down(point->right);
			}
		}
		

	}


	//--------------------truncate down------------


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
	
	//---------Transverse-------------
	void transverse (node *point){
	
		if(point==NULL){
		
			cout<<"Tree is empty"<<endl;
			return;
		
		}

			cout<<point->value<<endl;

		if(point->left!=NULL){
		
			cout<<"Going left"<<endl;
			transverse(point->left);
		}

	

		if(point->right!=NULL){
		
			cout<<"Going right"<<endl;
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
	min_heap obj;
	int i=0;




	for(int j=0;j<9;j++){
	
		cin>>i;
		obj.insert(obj.root,i,obj.level,obj.level);
		
		//cout<<"\n\n\n";
	}
	cout<<"\n\n\n";
	obj.transverse(obj.root);
	
	obj.del_min();
	
	obj.transverse(obj.root);
	

	/*
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
	
	*/
	

	system("pause");
}