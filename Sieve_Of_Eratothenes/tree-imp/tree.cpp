//Sieve of eratothenes
//Tree Implementataion

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


struct node
{
	int data;
	struct node *left;
    struct node *right;
};

class BST{
    public:
    node *tree;
    BST()
    {
        tree=NULL;
    }
    void createTree(node **,int item);    //For Building Tree
    void removeTree(node **); //Remove tree from memory.
    void preOrder(node *);     //For Tree Traversal
    void inOrder(node *);
    void postOrder(node *);
    void deleteNode(int);
};

//it is used for inseting an single element in//a tree, but if calls more than once will create tree.
void BST :: createTree(node **tree,int item)
{
    if(*tree == NULL){
        *tree = new node;
        (*tree)->data = item;
        (*tree)->left = NULL;
        (*tree)->right = NULL;
    }
    else{
        if( (*tree)->data > item)
            createTree( &((*tree)->left),item);
        else
            createTree( &((*tree)->right),item);
    }
}


void BST :: preOrder(node *tree){
    if( tree!=NULL){
        cout<<"   "<< tree->data;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void BST :: inOrder(node *tree){
    if( tree!=NULL){
        inOrder( tree->left);
        cout<<"   "<< tree->data;
        inOrder(tree->right);
    }
}


void BST :: postOrder(node *tree){
    if( tree!=NULL){
        postOrder( tree->left);
        postOrder( tree->right);
        cout<<"   "<<tree->data;
    }
}

void BST :: removeTree(node **tree){
    if( (*tree) != NULL){
        removeTree( &(*tree)->left );
        removeTree( &(*tree)->right );
        delete( *tree );
    }
}

node * find_Insucc(node *curr)
{
    node *succ=curr->right; //Move to the right sub-tree.
    if(succ!=NULL)
    {
        while(succ->left!=NULL)    //If right sub-tree is not empty.
            succ=succ->left; //move to the left-most end.
    }
    return(succ);
}
void BST :: deleteNode(int item)
{
    node *curr=tree,*succ,*pred;
    int flag=0,delcase;
    //step to find location of node
    while(curr!=NULL && flag!=1)
    {
        if(item < curr->data)
        {
            pred = curr;
            curr = curr->left;
        }
        else if(item > curr->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        { //curr->data = item
            flag=1;
        }
    }

    if(flag==0){
        //cout<<"\nItem does not exist : No deletion\n";
        goto end;
    }

    //Decide the  case of deletion
    if(curr->left==NULL && curr->right==NULL)
        delcase=1; //Node has no child
    else if(curr->left!=NULL && curr->right!=NULL)
        delcase=3; //Node contains both the child
    else
        delcase=2; //Node contains only one child 
        //Deletion Case 1
    if(delcase==1)
    {
        if(pred->left == curr) //if the node is a left child
            pred->left=NULL; //set pointer of its parentelse
            pred->right=NULL;
        delete(curr); //Return deleted node to the memory bank.
    }

    //Deletion Case 2
    if(delcase==2)
    {
        if(pred->left==curr)
        { //if the node is a left child
        	if(curr->left==NULL)
                pred->left=curr->right;
            else
                pred->left=curr->left;
        }
        else
        { //pred->right=curr
        	if(curr->left==NULL)
                pred->right=curr->right;
            else
                pred->right=curr->left;
        }
        delete(curr);
    }

    //Deletion case 3
    if(delcase==3)
    {
        succ = find_Insucc(curr); //Find the in_order successor//of the node.
        int item1 = succ->data;
        deleteNode(item1);  //Delete the inorder successor
        curr->data = item1; //Replace the data with the data of//in order successor.
    }
 end: ;
}


int main()
{
	BST obj;
    clock_t t;
    int choice;
    int height=0,total=0,n,item;
    node **tmp;
    cout<<"\nHow many nodes do you want to enter : ";
    cin>>n;
    for(int i=2;i<n;i++)
    {
       obj.createTree(&obj.tree,i);
    }
//obj.inOrder(obj.tree);  
t=clock();
 for (int p=2; p<=n; p++)
 {int c=2;
 int mul = p*c;
  while(mul<n)
  {
    obj.deleteNode(mul);
    //Passing value to list for update.
	c++;
    mul = p*c;
   }
  }
t=clock()-t;
cout<<"It took me "<<t<<"clicks which is equal to :"<<((float)t)/CLOCKS_PER_SEC<<" seconds";
/*
cout<<"\n Done. The primes are \n";
cout<<"\n\nInorder Traversal : ";
obj.inOrder(obj.tree);

cout<<"\n\nPre-order Traversal : ";
obj.preOrder(obj.tree);

cout<<"\n\nPost-order Traversal : ";
obj.postOrder(obj.tree);
                
*/
obj.removeTree(&obj.tree);
cout<<"\n\nTree is removed from Memory";
cout<<"\n";
return 0;
}