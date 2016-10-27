#ifndef TreeMap
#define TreeMap_h

#include "Data.h"
#include "BTree.h"

template <typename KEY, typename VALUE, typename COMP  >
class TreeMap {


private:
	BTree<Pair<KEY, VALUE>,COMP> *tree;

public:

	Node<KEY>* ptr() { return tree->root; }
	TreeMap() {
	
		tree = new BTree<Pair<KEY, VALUE>, COMP> ;
	}

	~TreeMap() {
		delete tree;
	}


	void insert(KEY key, VALUE value){
		
		tree->insert(Pair<KEY, VALUE>(key, value));
		

	}

	VALUE find(KEY key){

		return (tree->find(Pair<KEY, VALUE>(key, NULL)))->value;


	}

	KEY findMin(){

//		return (tree->findMin()))->value;
		//KEY ret = (tree->findMin())->key;
		return (tree->findMin())->key;


	}

	KEY findMax(){

//		return (tree->findMax()))->value;
		//return (tree->findMax())->value;
		return (tree->findMax())->key;


	}

	void removeAll(){

		tree->removeAll(tree->root);


	}

	void remove(KEY key){

		//tree->remove(Pair)

	}


	unsigned int getSize() { return tree->size; }

	VALUE& operator[] (KEY key){

		return (tree->find(Pair<KEY, VALUE>(key, NULL)))->value;


	}


};





#endif
