#include<iostream>
using namespace std;

struct node{
	int data;
	node* right;
	node* left;
};
node *n, *temp1, *temp2;
node *root = NULL;
node *leaf = NULL;

bool isEmpty(){
	if(root == NULL){
		return true;
	}
	else{
		return false;
	}
}

void tambah(int data){
	n = new node;
	n->data = data;
	n->right = NULL;
	n->left = NULL;
	if(isEmpty()){
		root = n;
		cout << "Data berhasil dimasukkan" << endl;
	}
	else{
		temp1 = root;
		temp2 = root;
		while(temp1 != NULL && n->data != temp1->data){
			temp2 = temp1;
			if(n->data < temp2->data){
				temp1 = temp2->left;
			}
			else{
				temp1 = temp2->right;
			}
		}
		if(n->data == temp2->data){
			cout << "Data yang sama telah ada" << endl;
		}
		else{
			if(n->data < temp2->data){
				temp2->left = n;
			}
			else{
				temp2->right = n;
			}
			cout << "Data berhasil dimasukkan" << endl;
		}
	}
}

void preorder(node *temp2){
	if(temp2 != NULL){
		cout << temp2->data << " ";
		preorder(temp2->left);
		preorder(temp2->right);
	}
}

void inorder(node *temp2){
	if(temp2 != NULL){
		inorder(temp2->left);
		cout << temp2->data << " ";
		inorder(temp2->right);
	}
}

void postorder(node *temp2){
	if(temp2 != NULL){
		postorder(temp2->left);
		postorder(temp2->right);
		cout << temp2->data << " ";
	}
}

void clear(){
	root = NULL;
}

int main(){
	int data;
	char ulang, pilihan;
	
	do{
		system("cls");
		cout << "=====================\n";
		cout << " Program Binary Tree\n";
		cout << "=====================\n";
	
		cout << "Menu : "<<endl;
		cout << "1. Input data" << endl;
		cout << "2. PreOrder" << endl;
    	cout << "3. InOrder" << endl;
    	cout << "4. PostOrder" << endl;
    	cout << "5. Clear Tree" << endl; 
    	cout << "\nMasukkan pilihan Anda : ";
		cin >> pilihan;
		
		switch(pilihan){
    		case '1' :
            	cout<<"\nMasukkan data : ";
            	cin>>data;
            	tambah(data);
            	break;
    		case '2' :
    			if(isEmpty()){
    				cout << "Tree Kosong" << endl;
				}
				else{
					preorder(root);
				}
        	    break;
      		case '3' :
				if(isEmpty()){
    				cout << "Tree Kosong" << endl;
				}
				else{
					inorder(root);
				}
        	    break;
      		case '4' :
        	    if(isEmpty()){
    				cout << "Tree Kosong" << endl;
				}
				else{
					postorder(root);
				}
            	break;
            case '5' :
            	clear();
            	cout << "Tree telah dikosongkan" << endl;
            	break;
      		default :
            	cout<<"\nPilih ulang"<<endl;
      	}
      		cout<<"\nKembali ke menu?(y/n)";
     		cin>>ulang;
    }
	while(ulang=='y' || ulang=='Y');
}
