#include  <iostream>

#include "Vector.h"
#include "List.h"
#include "Hash.h"
#include "BTree.h"
#include "TreeMap.h"
#include "Data.h"
#include <string>
#include <sstream>
#include <typeinfo>

// Just a test

using namespace std;

template <typename KEY, unsigned int SIZE = DEF_HTABLESIZE>
class StringHash{
public:
	size_t operator() (KEY key) {
	
		int h = 0;
		int x = 7;

		for (unsigned int i = 0; i < key.size(); i++)
		{
			h = h + key[i]; // *int(pow(7, i));
		}
		
		
		return h%SIZE;
	}
	
};

class Person{
public:
	int age, height, weight;

	Person() : age(0), height(0), weight(0) {}
	Person(int a, int h, int w) : age(a), height(h), weight(w) {}

};


class Comp_Person {
public:
	virtual int operator()(const Person node1,
	const Person node2){
		if (node1.age > node2.age) {
			return 1;
		}
		if (node1.age < node2.age) {
			return -1;
		}
		if (node1.age == node2.age) {
			return 0;
		}

		return 0;

	}


	friend ostream& operator<<(ostream& os,  Person p);




};

ostream& operator<< (ostream& os,  Person p){
	os << p.age;
	return os;
}


class Comp_Pair_Person {
public:
	virtual int operator()(const Pair<Person,char*> node1,
		const Pair<Person, char*> node2){
		if (node1.key.age > node2.key.age) {
			return 1;
		}
		if (node1.key.age < node2.key.age) {
			return -1;
		}
		if (node1.key.age == node2.key.age) {
			return 0;
		}

		return 0;

	}


	friend ostream& operator<<(ostream& os, Pair<Person,char*> p);




};

ostream& operator<< (ostream& os, Pair<Person, char*> p){
	os << p.key.age;
	return os;
}


class parent {
	
public:
	int a;
	parent(int aa) : a(aa) {}
};

class child : public parent {
public:
	int b;
	child(int aa, int bb) : parent(aa), b(bb) {}
};

int main(){

	//parent* p = new child(1, 2);
	//cout << p->a << endl;
	//
	////child* c = static_cast<child*> (p);
	//cout << static_cast<child*> (p)->b << endl;


	TreeMap<Person, char*, Comp_Pair_Person> treemap;

	treemap.insert(Person(94, 181, 60),"21314234");
	treemap.insert(Person(97, 140, 75),"2311");
	treemap.insert(Person(10, 120, 30),"safsf");
	treemap.insert(Person(24, 167, 70),"sdfwrfgdfw");
	treemap.insert(Person(5, 115, 30),"FFFFFFFFFFFFFFFFFFFF");
	treemap.insert(Person(15, 175, 60),"fsdfwersdfsd");
	treemap.insert(Person(27, 178, 80),"sdfsdf23424");
	treemap.insert(Person(17, 172, 66),"2343572342");
	treemap.insert(Person(12, 155, 45),"867464");
	treemap.insert(Person(6, 115, 28),"4536757");
	treemap.insert(Person(50, 190, 88),"3336");
	treemap.insert(Person(25, 185, 82),"990797");

	cout<<treemap.find(Person(25, 185, 82))<<endl;
	cout << treemap.findMin() << endl;
	cout << treemap.findMax() << endl;
	treemap[Person(25, 185, 82)]="5000";
	cout << treemap.find(Person(25, 185, 82))<<endl;


	//Comp_Person myCOMP;

	//cout << myCOMP(Person(100, 10, 0), Person(150, 20, 1)) << endl;

	//BTree<Person, Comp_Person> btree;

	//btree.insert(Person(94, 181, 60));
	//btree.insert(Person(97, 140, 75));
	//btree.insert(Person(10, 120, 30));
	//btree.insert(Person(24, 167, 70));
	//btree.insert(Person(5, 115, 30));
	//btree.insert(Person(15, 175, 60));
	//btree.insert(Person(27, 178, 80));
	//btree.insert(Person(17, 172, 66));
	//btree.insert(Person(12, 155, 45));
	//btree.insert(Person(6, 115, 28));
	//btree.insert(Person(50, 190, 88));
	//btree.insert(Person(25, 185, 82));

	//cout << btree.findMin()->age << endl;
	////Person a = btree.findMin();
	//cout << btree.findMax() << endl;
	//cout << btree.getSize() << endl;
	//cout << btree.find(Person(25, 185, 82))->age << endl;


	//btree.remove(Person(24, 167, 70));


	//cout << "Btree destructor is called ..." << endl;
	//cout << "------------------------------------------------------" << endl;

	/*btree.removeAll(btree.root);
	btree.insert(Person(0, 35, 3));
	cout << btree.getSize() << endl;*/


	//BTree<int > btree;

	//btree.insert((94));
	//btree.insert((97));
	//btree.insert((10));
	//btree.insert((24));
	//btree.insert((5));
	//btree.insert((15));
	//btree.insert((27));
	//btree.insert((17));
	//btree.insert((12));
	//btree.insert((6));
	//btree.insert((50));
	//btree.insert((25));

	//cout << *btree.findMin() << endl;
	////int a = btree.findMin();
	//cout << btree.findMax() << endl;
	//cout << btree.getSize() << endl;
	//cout << *btree.find((25)) << endl;


	//btree.remove((24));

	// I made this change and want to upload to Git
	// boosboos

	// Just a test
	return 0;
}