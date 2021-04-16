#include <iostream>

#include <iomanip>

#include <fstream>

#include <set>

#include <algorithm>



using namespace std;



ofstream out;

int lent=0,p=0;

string name1[40],name2[40];

int ID[40];



struct node{

int data;

string lname;

string fname;

float amount;

struct node *left;

struct node *right;

};



class BST{

public:

node *tree;

BST(){

tree=NULL;

}

void createTree(node **,int item,string ln,string fn,float am); //For Building Tree

void inOrder(node *,int);

void displayS(node *);

node **searchElement(node **,int);

void deleteNode(int);

};





//it is used for inseting an single element in

//a tree, but if calls more than once will create tree.

void BST :: createTree(node **tree,int item,string ln,string fn,float am){

if(*tree == NULL){

*tree = new node;

(*tree)->data = item;

(*tree)->lname = ln;

(*tree)->fname = fn;

(*tree)->amount = am;

(*tree)->left = NULL;

(*tree)->right = NULL;

}

else{

if( (*tree)->data > item)

createTree( &((*tree)->left),item,ln,fn,am);

else

createTree( &((*tree)->right),item,ln,fn,am);

}

lent++;

}



void BST :: inOrder(node *tree,int ch){

if(ch==6){

   if( tree!=NULL){

   inOrder( tree->left, 6);

   cout<<" "<< tree->data <<"\t"<<tree->lname<<"\t"<<tree->fname<<"\t"<<fixed<<setprecision(2)<<tree->amount<<endl;

   inOrder(tree->right, 6);

   }

}

else if(ch==8){

   if( tree!=NULL){

   inOrder( tree->left, 8);

   if(tree->amount > 10000)

   cout<<" "<< tree->data <<"\t"<<tree->lname<<"\t"<<tree->fname<<"\t"<<fixed<<setprecision(2)<<tree->amount<<endl;

   inOrder(tree->right, 8);

   }

}

}



void BST :: displayS(node *tree){

if(tree!= NULL){

displayS(tree->left);

name1[p]=tree->lname + " " + tree->fname;

ID[p]=tree->data;

p++;

displayS(tree->right);

}

}



node ** BST :: searchElement(node **tree, int item){

if( ( (*tree) == NULL) || ((*tree)->data == item) )

return tree;

else if( item < (*tree)->data)

return searchElement( &(*tree)->left, item);

else return searchElement( &(*tree)->right, item);

}



//Finding In_order Successor of given node..

//for Delete Algo.

node * find_Insucc(node *curr)

{

node *succ=curr->right; //Move to the right sub-tree.

if(succ!=NULL){

while(succ->left!=NULL) //If right sub-tree is not empty.

succ=succ->left; //move to the left-most end.

}

return(succ);

}



void BST :: deleteNode(int item){

node *curr=tree,*succ,*pred;

int flag=0,delcase;

//step to find location of node

while(curr!=NULL && flag!=1)

{

if(item < curr->data){

pred = curr;

curr = curr->left;

}

else if(item > curr->data){

pred = curr;

curr = curr->right;

}

else{ //curr->data = item

flag=1;

}

}



if(flag==0){

cout<<"\nItem does not exist : No deletion\n";

goto end;

}



//Decide the case of deletion

if(curr->left==NULL && curr->right==NULL)

delcase=1; //Node has no child

else if(curr->left!=NULL && curr->right!=NULL)

delcase=3; //Node contains both the child

else

delcase=2; //Node contains only one child

//Deletion Case 1

if(delcase==1){

if(pred->left == curr) //if the node is a left child

pred->left=NULL; //set pointer of its parent

else

pred->right=NULL;

delete(curr); //Return deleted node to the memory bank.

}



//Deletion Case 2

if(delcase==2){

if(pred->left==curr){ //if the node is a left child

if(curr->left==NULL)

pred->left=curr->right;

else

pred->left=curr->left;

}

else{ //pred->right=curr

if(curr->left==NULL)

pred->right=curr->right;

else

pred->right=curr->left;

}

delete(curr);

}



//Deletion case 3

if(delcase==3){

succ = find_Insucc(curr); //Find the in_order successor of the node.

int item1 = succ->data;

float am1 = succ->amount;

string ln1= succ->lname;

string fn1= succ->fname;

deleteNode(item1); //Delete the inorder successor

//Replace the data with the data of in order successor.

curr->data = item1;

curr->lname = ln1;

curr->fname = fn1;

curr->amount = am1;

}

end:

;

}



void input(BST& obj){

int item;

float amount;

string fn,ln;

while(1){

cout<<"Enter Id : ";

cin>>item;

   if(item<1000 || item >9999){

cout<<"Entered ID is incorrect."<<endl;

cout<<">>ID must be a 4 digit Integer"<<endl;

}else break;

}

while(1){

cout<<"Enter Last Name: ";

cin>>ln;

if(ln.length() >20){

cout<<"Entered name is long."<<endl;

   cout<<">>name must be atmost 20 character in length."<<endl;

   }else break;

}

while(1){

cout<<"Enter First Name: ";

   cin>>fn;

if(fn.length() >20){

cout<<"Entered name is long."<<endl;

cout<<">>name must be atmost 20 character in length."<<endl;

}else break;

}

while(1){

cout<<"Enter Amount: ";

cin>>amount;

if(amount <10 && amount > 99999.99){

cout<<"Entered amount is wrong."<<endl;

cout<<">>amount must be greate then 9.99."<<endl;

}else break;

}

obj.createTree(&obj.tree,item,ln,fn,amount);

}



void saveRecord(node *tree){

if(tree!=NULL){

saveRecord(tree->left);

out<<tree->data <<"\t"<<tree->lname<<"\t"<<tree->fname<<"\t\t"<<fixed<<setprecision(2)<<tree->amount<<endl;

saveRecord(tree->right);

}

}



int main(){

BST obj;

int choice;

int i,n,item,N1,rec;

float amount;

string fn,ln;

node **tmp;

out.open("Record.txt");

  

while(1){

   /**/cout<<"\n1. Add a new record."<<endl;

/**/cout<<"2. Delete a record by Student ID."<<endl;

/**/cout<<"3. Change amount by Student ID."<<endl;

/**/cout<<"4. Edit student information (i.e. last name or first name)."<<endl;

/**/cout<<"5. Delete all student records which has an amount zero."<<endl;

/**/cout<<"6. Display all records in order of student ID." <<endl;

/**/cout<<"7. Display all records in order of student's last name and first name."<<endl;

/**/cout<<"8. Display all records which has an amount over 10000."<<endl;

/**/cout<<"9. Exit."<<endl;

  

cout<<"Enter your choice : ";

cin>>choice;

switch(choice){

   case 1:

   cout<<"\n\n--Inserting Record in a tree--\n";

   cout<<"How many records you want to enter: ";

   cin>>rec;

   for(i=0;i<rec;i++){

   cout<<"\nInserting Record "<<(i+1)<<" :::\n";

input(obj);

   }

cout<<"\n\t"<<rec<<" Record Inserted\n";

   break;

  

case 2:

   cout<<"\n\n--Deleting a Record from a tree--\n";

cout<<"Enter Student's ID : ";

cin>>item;

obj.deleteNode(item);

cout<<"\nRecord with Student ID "<<item<<" Deleted\n\n";

   break;

  

case 3:

cout<<"Enter Student's ID : ";

cin>>item;

(tmp) = obj.searchElement(&obj.tree,item);

if( (*tmp) == NULL)

cout<<"\nID Not Found\n\n";

else{

   while(1){

      cout<<"Enter New Amount: ";

   cin>>amount;

      if(amount <10.00 && amount > 99999.99){

      cout<<"Entered amount is wrong."<<endl;

      cout<<">>amount must be greate then 9.99."<<endl;

   }else break;

   }

   (*tmp)->amount = amount;

   cout<<"\nAmount Modified\n"<<endl;

}

   break;

  

case 4:

   cout<<"Enter Student's ID : ";

cin>>item;

(tmp) = obj.searchElement(&obj.tree,item);

if( (*tmp) == NULL)

cout<<"\nID Not Found";

else{

   while(1){

    cout<<"Enter new Last Name: ";

      cin>>ln;

      if(ln.length() >20){

      cout<<"Entered name is long."<<endl;

   cout<<">>name must be atmost 20 character in length."<<endl;

   }else break;

   }

   (*tmp)->lname = ln;

  

while(1){

   cout<<"Enter new First Name: ";

   cin>>fn;

      if(fn.length() >20){

      cout<<"Entered name is long."<<endl;

      cout<<">>name must be atmost 20 character in length."<<endl;

   }else break;

   }

   (*tmp)->fname = fn;

   cout<<"\nName Modified\n"<<endl;

}

   break;

  

case 5:

   cout<<"\n No Record with amount = 0 found\n";

   break;

  

case 6:

cout<<"\nRecords organized in order of student ID:\n";

   obj.inOrder(obj.tree, 6);

   cout<<endl;

   break;

  

case 7:

   obj.displayS(obj.tree);

for(i=0;i<p;i++){

   name2[i]=name1[i];

   }

N1 = sizeof(name1)/sizeof(name1[0]);

sort(name1,name1+N1);

cout<<"Recordes organized in order of student's name:\n";

for(i=N1-p;i<N1;i++){

for(n=0;n<p;n++){

if(name1[i]==name2[n]){

item = ID[n];

(tmp) = obj.searchElement(&obj.tree,item);

cout<<" "<<(*tmp)->lname<<" "<<(*tmp)->fname<<"\t"<< (*tmp)->data <<"\t"<<fixed<<setprecision(2)<<(*tmp)->amount<<endl;

}

}

}

for(i=0;i<p;i++){

   name1[i]=name2[i];

   }

for(i=p;i<N1;i++)

name1[i] = "\0";

p=0;

   break;

  

case 8:

   cout<<"Records with amount > 10000:\n";

   obj.inOrder(obj.tree, 8);

   break;

  

case 9 : break;

default:

cout<<endl<<"Wrong Choice"<<endl<<endl;

  

}//end of switch

if(choice == 9) break;

}

saveRecord(obj.tree);

out.close();

return 0;

}

