#include<iostream>
#include<string>
using  namespace std;

class list{
private:
	int p[10];
	int max,len,*current,*temp;
public:

	list(){
	max=10;
	current=p;
	temp=p;
	}


	list(list& othrList){
	othrList.max=max;
	othrList.len=len;
	
	for(int i=0;i<len;i++){
	othrList.p[i]=p[i];

	}
	
	}


	void clear(){
	
		temp=p;

		for(int i=0;i<len;i++){
		*temp=0;
		temp++;
		}

	len=0;
	}



	void insert(int value,int pos){
	
		if(pos<=0 ||pos>len){
		cout<<"Invalid position!!!!";
		}

		else
		{
			current=p;
		
			for(int i=1;i<pos;i++){
			current++;
			}

			for(int i=1;i<len;i++){
			temp++;
			}

			while(temp>=current){
			*(temp+1)=*temp;
			temp--;
			}

			*current=value;
		}

	}


	void remove(int pos){
	
	current=p;

	for(int i=1;i<pos;i++){
	
	current++;
	}

	temp=current;

	for(int i=pos-1;i<len;i++){
	*temp=*(temp+1);
	temp++;
	}

	}




	int get(int pos){
	temp=p;
	
	for(int i=1;i<pos;i++){
	temp++;
	}
	return *temp;
	}


	void update(int value,int pos){
	current=p;

	for(int i=1;i<pos;i++){
	
	current++;
	}
	
	*current=value;

	}



	bool find(int value){
	
	bool chk=0;
	temp=p;


	for(int i=0;i<len;i++){
	if(*temp==value){
		chk=1;
	}
	}

	return chk;
	}



	int length(){
	return len;
	}



	void start(){
	current=p;
	}

	void end(){
	
	current=p;
	for(int i=1;i<len;i++){
	
	current++;
	}
	}

	void next(){
		if(current<(p+(len-1))){
		current++;
		}

		else{
		cout<<"Standing on last element"<<endl;
		}
	
	}


	void back(){
		if(current>p){
		current--;
		}
		else{
		cout<<"Standing on first element"<<endl;
		}
	}

	void Add(int value){
	current=p;
	while(current<=(p+len-1)){
	current++;
	}
	*current=value;
	}

};

void main(){

	

	system("pause");
}    