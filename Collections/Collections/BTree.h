#ifndef BTree_h
#define BTree_h

#include "Data.h"

class NodeError : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "Node does not exist ...";
	}
};

template <typename U, typename C = Comparator<U> >
class BTree{
//private:
public:
	Node<U> *root;
	int size;
	C compobj;

	Node<U>* ptr() { return root; }

//public:
	BTree(){
		root = NULL;
		size = 0;

	}

	void removeAll(Node<U>* curr){

		if (curr == NULL) {
			return;
		}

		if (curr->leftchild == NULL && curr->rightchild == NULL){
			
			size--;
//			cout << "freeing " << curr->value << " ..." << size << endl;

			delete curr;
			//curr = NULL;

			
			return;
		}
		if (curr->leftchild != NULL) {
			removeAll(curr->leftchild);
		}
		if (curr->rightchild != NULL) {
			removeAll(curr->rightchild);
		}

		size--;
//		cout << "freeing " << curr->value << " ..." << size << endl;
		delete curr;

		if (size == 0) root = NULL;
		
	}

	~BTree() {

		// destrcutor function to free memory of each node in the tree
		removeAll(root);



	}

	void insert(U val){
		// returns 0 on succes and 1 if fails


		Node<U>* curr = root;
		
		Node<U> *nodevar = new Node<U>;
		nodevar->value = val;

		if (root == NULL) {
			root = nodevar;
			root->parent = NULL;
			root->leftchild = NULL;
			root->rightchild = NULL;
			size++;
			//return 0;
		}
		else{

			//Node<U>* curr = root;

			//while (curr->leftchild != NULL || curr->rightchild != NULL){
			while (1){

				if (compobj(val, curr->value)== 1){

					if (curr->rightchild != NULL)	
					{ curr = curr->rightchild; 
					continue; }
					
					else { 
						curr->rightchild = nodevar;
						curr->rightchild->parent = curr;
						size++;
						break;
						//return 0;
					}

				}


				if (compobj(val, curr->value)== -1){

					if (curr->leftchild != NULL)	{ 
						curr = curr->leftchild;
						continue; }

					else { 
						curr->leftchild = nodevar;
						curr->leftchild->parent = curr;
						size++;
						break;
						//return 0;
					}

				}

			}



		}

		//return 1; // insertion fails


	}



	U* find (U val){

		Node<U>* curr = root;

		Node<U> *nodevar = new Node<U>;
		nodevar->value = val;

		if (root == NULL) {

			return NULL;
		}
		else{


			while (1){

				if (compobj(val, curr->value) == 1){

					if (curr->rightchild != NULL)
					{
						curr = curr->rightchild;
						continue;
					}

					else {

						return NULL;
					}

				}


				if (compobj(val, curr->value) == -1){

					if (curr->leftchild != NULL)	{
						curr = curr->leftchild;
						continue;
					}

					else {

						return NULL;
					}

				}

				if (compobj(val, curr->value) == 0){

					return &(curr->value);

				}



			}



		}


	}



	U* findMin(){

		Node<U>* curr = root;

		if (root == NULL) {

			return NULL;
			//NodeError ne;
			//throw ne;
		}
		else{

			//if (curr->leftchild == NULL) return root->value;
			if (curr->leftchild == NULL) return &root->value;

			while (curr->leftchild != NULL){

				curr = curr->leftchild;



			}



		}

		//return curr->value;
		return &curr->value;

	}

	U* findMax(){


		Node<U>* curr = root;

		if (root == NULL) {

			return NULL;
			//NodeError ne;
			//throw ne;
		}
		else{

			//if (curr->rightchild == NULL) return root->value;
			if (curr->rightchild == NULL) return &root->value;

			while (curr->rightchild != NULL){

				curr = curr->rightchild;



			}



		}

		//return curr->value;
		return &curr->value;


	}



	void remove(U val){

		Node<U>* curr = root;

		Node<U> *nodevar = new Node<U>;
		nodevar->value = val;

		if (root == NULL) {


			return ;
		}
		else{


			while (1){

				if (compobj(val, curr->value) == 1){

					if (curr->rightchild != NULL)
					{
						curr = curr->rightchild;
						continue;
					}

					else {

					}

				}


				if (compobj(val, curr->value) == -1){

					if (curr->leftchild != NULL)	{
						curr = curr->leftchild;
						continue;
					}

					else {

					}

				}

				if (compobj(val, curr->value) == 0){

					// case 1: the node has no right or left child
					if (curr->leftchild == NULL && curr->rightchild == NULL){
						
						if (compobj(curr->value, curr->parent->value) ==  1) curr->parent->rightchild = NULL;
						if (compobj(curr->value, curr->parent->value) == -1) curr->parent->leftchild  = NULL;
						
						size--;
						delete curr;
						break;

					}

					// case 2: the node has no left child
					if (curr->leftchild == NULL && curr->rightchild != NULL){

						curr->rightchild->parent = curr->parent;

						if (compobj(curr->value, curr->parent->value) == 1) curr->parent->rightchild = curr->rightchild;
						if (compobj(curr->value, curr->parent->value) == -1) curr->parent->leftchild = curr->rightchild;
						
						size--;
						delete curr;
						break;


					}


					// case 3: the node has no right child
					if (curr->leftchild != NULL && curr->rightchild == NULL){

						curr->leftchild->parent = curr->parent;

						if (compobj(curr->value, curr->parent->value) == 1) curr->parent->rightchild = curr->leftchild;
						if (compobj(curr->value, curr->parent->value) == -1) curr->parent->leftchild = curr->leftchild;
						
						size--;
						delete curr;
						break;


					}

					// case 4: the node has two child
					if (curr->leftchild != NULL && curr->rightchild != NULL){
						
						// find the smallest value on the right subtree
						Node<U>* minValue = curr->rightchild;
						

						Node<U>* minValueLeftChild = NULL;
						Node<U>* minValueRightChild = NULL;
						Node<U>* minValueParent = NULL;


						while (minValue->leftchild != NULL){

							minValue = minValue->leftchild;
							
						}
						
						minValueLeftChild = minValue->leftchild;
						minValueRightChild = minValue->rightchild;
						minValueParent = minValue->parent;


						if (compobj(curr->value, curr->parent->value) == 1) {
							
							curr->parent->rightchild = minValue;
														

							
							if (minValue->parent != curr){
								minValue->parent = curr->parent;
								minValue->rightchild = curr->rightchild;
								minValue->leftchild = curr->leftchild;

																
								if (compobj(minValue->value, minValueParent->value) == -1){
									minValueParent->leftchild = NULL;
								}
								if (compobj(minValue->value, minValueParent->value) == 1){
									minValueParent->rightchild = NULL;
								}
							}
							else{

								if (compobj(minValue->value, minValueParent->value) == -1){
									minValue->parent = curr->parent;
									minValue->rightchild = curr->rightchild;
									minValue->leftchild = NULL;
									
									minValueParent->leftchild = minValue;
								}

								if (compobj(minValue->value, minValueParent->value) == 1){
									minValue->parent = curr->parent;
									minValue->rightchild = NULL;
									minValue->leftchild = curr->leftchild;

									minValueParent->rightchild = minValue;
								}

							}

							
							if (minValue->leftchild != NULL) minValue->leftchild->parent = minValue;
							if (minValue->rightchild != NULL) minValue->rightchild->parent = minValue;

							
							size--;
							delete curr;
							break;

						}



						if (compobj(curr->value, curr->parent->value) == -1) {

							curr->parent->leftchild = minValue;

							
							if (minValue->parent != curr){
								minValue->parent = curr->parent;
								minValue->rightchild = curr->rightchild;
								minValue->leftchild = curr->leftchild;

								minValueParent->leftchild = minValueLeftChild;
								minValueParent->rightchild = minValueRightChild;
							}
							else{
								if (compobj(minValue->value, minValueParent->value) == -1){
									minValue->parent = curr->parent;
									minValue->rightchild = curr->rightchild;
									minValue->leftchild = NULL;

									minValueParent->leftchild = minValue;
								}

								if (compobj(minValue->value, minValueParent->value) == 1){
									minValue->parent = curr->parent;
									minValue->rightchild = NULL;
									minValue->leftchild = curr->leftchild;

									minValueParent->rightchild = minValue;
								}

							}

							if (minValue->leftchild != NULL) minValue->leftchild->parent = minValue;
							if (minValue->rightchild != NULL) minValue->rightchild->parent = minValue;


							size--;
							delete curr;
							break;
						}
						

						
					}


				}



			}
			// end while(1)


		}


	}

	unsigned int getSize() { return size; }

	bool isMember(U val){

		Node<U>* curr = root;

		Node<U> *nodevar = new Node<U>;
		nodevar->value = val;

		if (root == NULL) {

			return false;
		}
		else{


			while (1){

				if (compobj(val, curr->value) == 1){

					if (curr->rightchild != NULL)
					{
						curr = curr->rightchild;
						continue;
					}

					else {

						return false;
					}

				}


				if (compobj(val, curr->value) == -1){

					if (curr->leftchild != NULL)	{
						curr = curr->leftchild;
						continue;
					}

					else {

						return false;
					}

				}

				if (compobj(val, curr->value) == 0){

					return true;

				}



			}



		}


	}


};

#endif