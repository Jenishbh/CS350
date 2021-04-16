void BST (Nodetype * Insert, Nodetype * tree, int key, char * name);
    {
    if(ptr == NULL) {
        ptr = new node;
        ptr->info = num;
        ptr->lchild = NULL;
        ptr->rchild = NULL;     
       if(start == NULL)
         start = ptr;
       return;
    }
    else if(ptr->info){
        insert(ptr->lchild);
	Return num;
     }
     else if( ptr->info) {
        insert(ptr->rchild);
     }
    else {
       printf "Duplicate element \n";
       return;
    }
   }

