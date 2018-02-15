#include<iostream>

using namespace std;

struct node{
int value;
node *left,*right;
};

class AVL{
	node *temp,*temp2;
	int suc;
	int b_fact;bool chk_balance;
public:
	node *root;


	AVL(){
	
	temp=temp2=root=NULL;
	b_fact=0;
	chk_balance=0;
	suc=0;
	}

	//insertion
	void insertion(node* &point,int num){
		
		chk_balance=0;

		if(root==NULL){
			root=new node;
			root->value=num;
			root->left=root->right=NULL;
			temp=point=root;
			return;
		}

		if(point==NULL){
		
			point=new node;
			point->value=num;
			point->left=point->right=NULL;
			chk_balance=1;
			return;
		}

		if(point->value==num){
		
			cout<<"Number already exists"<<endl;
			return;
		}
		
		if(point->value>num){
		
			insertion(point->left,num);
		}
		else if(point->value<num){
		
				insertion(point->right,num);
		}
	
		if(chk_balance){
		
		b_fact=balance_fact(point);
	//	cout<<"balance factor:"<<b_fact<<endl; 
		// Addition to left child of current node
		if(b_fact==2){

			//check if node was added to left subtree of left child or right subtree of left child

			if(num<point->left->value){
				zic_zic(point);

			}

			else{
				zic_zac(point);
			}
		
		}
		

		// Addition to right child of current node
		else if(b_fact==-2){
		
			//check if node was added to left subtree of right child or right subtree of left child

			
			if(num<point->right->value){
				zac_zic(point);

			}

			else{
				zac_zac(point);
			}

		}

		}// if(chk_balance)
		
	}//insertion

	//zic_zic balance
	void zic_zic(node*& point){
	temp=point->left;
	point->left=temp->right;
	temp->right=point;
	point=temp;
	
	}

	// zic_zac balance
	void zic_zac(node*& point){

		 
	temp=point->left->right;
	point->left->right=temp->left;
	temp->left=point->left;
	point->left=temp->right;
	temp->right=point;
	point=temp;
	
	}


	//zac-zic balance
	void zac_zic(node* &point){
	temp=point->right->left;

	point->right->left=temp->right;
	temp->right=point->right;
	point->right=temp->left;
	temp->left=point;
	point=temp;
		
	}

	//zac-zac balance
	void zac_zac(node *&point){

		temp=point->right;
		point->right=temp->left;
		temp->left=point;
		point=temp;

	}








	//path calc
	int path(node *point){
	if(point==NULL){
		
		return 0;
		}
	
	else{
			int left=path(point->left);
			int right=path(point->right);
		

			if(left>right){
			return left+1;
			}
			else return right+1;
		}
	}

	//path calc

	//Balance factor
	int balance_fact(node *point){
	
		int left=0;
		int right=0;

		if(point!=NULL){
		if(point->left!=NULL){
		left=path(point->left);
		}

		if(point->right!=NULL){
		right=path(point->right);
		}
		}
		return left-right;
				
	}

	//Balance factor


	//deletion
	
	void del_node(int num,node *&point){
		
		int pre_balance=0;
		chk_balance=0;

		if(root==NULL){
		cout<<"Tree is empty"<<endl;
		return;
		}
	
		if(point==NULL){
		
			cout<<"value doesn't exists"<<endl;
			return;
		}
		
		pre_balance=balance_fact(point);
		

		if(num==point->value){
		
			if(point->left==NULL && point->right==NULL){
		

				if(point==root){
				root=NULL;
				delete temp;
				temp=NULL;
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
				suc=temp->value;
				
				del_node(temp->value,root);

				point->value=suc;
			}
			chk_balance=1;
			return;
		}

		else if(num>point->value)
			del_node(num,point->right);

		else if(num<point->value)
			del_node(num,point->left);
			
		
			b_fact=balance_fact(point);

			if(chk_balance){
			
				if((pre_balance==0) && (b_fact==1 || b_fact==-1 )){    //1a & 1b
				chk_balance=0;
				
				}
				
				else if((pre_balance==1 ||pre_balance==-1) && (b_fact=0)){  //2a & 2b
				return;
				}

				else if(pre_balance==-1 && num<point->value && (balance_fact(point->right)==0)){  //3a
				
					zac_zac(point);
					chk_balance=0;
					
				}

				else if(pre_balance==1 && num>point->value && (balance_fact(point->left)==0)){ //3b
				
					zic_zic(point);
					chk_balance=0;

				}


				else if(pre_balance==-1 && num<point->value && (balance_fact(point->right)==1)){  //4a
				
					zac_zic(point);
				}

				else if(pre_balance==1 && num>point->value && (balance_fact(point->left)==-1)){  //4b
				
					zic_zac(point);
				}

				else if(pre_balance==-1 && num<point->value && (balance_fact(point->right)==-1)){ //5a
					zac_zac(point);
				}
	
				else if(pre_balance==1 && num>point->value && (balance_fact(point->left)==1)){ //5b
					zic_zic(point);
				}


			}//if(chk_balance)
		

	}


	//deletion

	//imidiate successor

	node*  find_imd_successor(node *find){
	if(find->left==NULL){
	
		return find;
	}
	
	return find_imd_successor(find->left);

}
	//finding imidiate successor


	//transverse
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
	
	
	AVL obj;

	
	obj.insertion(obj.root,4);
	//obj.transverse(obj.root);
	
	obj.insertion(obj.root,5);
	//obj.transverse(obj.root);

	obj.insertion(obj.root,7);
	//obj.transverse(obj.root);
	
	obj.insertion(obj.root,2);
	//obj.transverse(obj.root);
	
	obj.insertion(obj.root,1);
	//obj.transverse(obj.root);
	
	obj.insertion(obj.root,3);
	//obj.transverse(obj.root);
	
	obj.insertion(obj.root,6);
	obj.transverse(obj.root);
	

	cout<<endl;
	obj.del_node(5,obj.root);
		obj.transverse(obj.root);

	system("pause");
}