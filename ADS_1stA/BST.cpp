#include <iostream>

	struct node {
	int key;
	struct node *left, *right;
	};


	struct node *newNode(int item) {
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->key = item;
		temp->left = temp->right = NULL;
		return temp;
	}

	void inorder(struct node *root) {
		if(root != NULL) {
			inorder(root->left);
			printf("%d \n", root->key);
			inorder(root->right);
		}
   }


   struct node *insert(struct node* node, int key) {
   		while(node == NULL)   {
   			 return newNode(key);
   		 }
   	while(node != NULL) {
   	
   	if(key < node->key)  
   		 	key = (int)node->left;
   		 	
  	else if(key > node->key)    
  		 	key = (int)node-> right;
	     	
	return node;
  }
  }
  
  





  struct node* search(struct node* root, int key) {
  	if(root == NULL || root->key == key)
  		return root;

  	if(root->key < key) 
  		return search(root->right, key);

  	return search(root->left, key);

  }


  struct node* minValueNode(struct node* node) {
  	struct node* current = node;

  	while(current->left != NULL)
  		current = current->left;

   	return current;
  }


  struct node* deleteNode(struct node* root, int key) {
  	if(root == NULL) return root;

  	if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if(key > root->key)
    	root->right = deleteNode(root->right, key);
    else {
    	 if(root->left == NULL) {
    	 	struct node *temp = root->right;
    	 	free(root);
    	 	return temp;
    	 }

    	else if(root->right == NULL) {
    		struct node *temp = root->left;
    		free(root);
    		return temp;
    	}

    	struct node* temp = minValueNode(root->right);

    	root->key = temp->key;

    	root->right = deleteNode(root->right, temp->key);
   	}

   	return root;
  }

    		



  int main() {

    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    root = search(root, 50);
 
    printf("Given inroder tree\n");
    inorder(root);
 
    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    
    inorder(root);
 
    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
       inorder(root);
 
    printf("\nDelete 50\n");
    root = deleteNode(root, 50); 
    inorder(root);
 
    return 0;
}