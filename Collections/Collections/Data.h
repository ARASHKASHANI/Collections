#ifndef Data_h
#define Data_h

template <typename T>
struct Data {
	T val;
	Data* next;

	Data(T& value) : val(value), next(NULL)	{}
	Data() : val(0), next(NULL){}

	~Data() {}

};

template <typename T, typename U>
struct Pair {
	T key;
	U value;

	Pair(){}
	Pair(T k, U v) : key(k), value(v) {}
	
	bool operator== (Pair<T,U > P ){
		if (key == P.key) return true;
		return false;
	}
		
};

template <typename T>
struct Node{

	T value;
	Node<T>  *parent;
	Node<T>  *leftchild;
	Node<T>  *rightchild;

	Node(){
		//value();
		parent = NULL;
		leftchild = NULL;
		rightchild = NULL;
	}

};


template<typename T>
struct Comparator{

	virtual int operator()(const T node1,
		const T node2){
		if (node1 > node2) {
			return 1;
		}
		if (node1 < node2) {
			return -1;
		}
		if (node1 == node2) {
			return 0;
		}

		return 0;

	}


};

template <typename T>
using itr = struct Data<T>*;

#endif
