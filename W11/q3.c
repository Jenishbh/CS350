void Binarytnc(add, int num){
        Node *temp, *dad;

        if (root==NULL) {
            root = new Node;
            root->data=num;
            root->left=0;
            root->right=0;
            temp=root;
            printf("Number is main root \n");
        } else {
            temp=root;
            while (temp!=NULL) {
                if (num <= temp->data){
                    dad = temp;
                    temp=temp->left;
                    //root =temp;
                    printf("value is to the left \n");
                } else {
                    dad =temp;
                    temp=temp->right;
                    //root=temp;
                    printf("value is to the right \n");
                }               
            }   
            

Node *newNode = new Node;
newNode->data = num;
newNode->left = NULL;
newNode->right = NULL;
if(num <= dad->data)
    dad->left = newNode;
else
    dad->right = newNode;

       }   
}
