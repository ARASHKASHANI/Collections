#ifndef Hash_h
#define Hash_h

#include "Data.h"
#include "List.h"

#include <exception>

#define DEF_HTABLESIZE 11

template <typename KEY, int SIZE = DEF_HTABLESIZE>
class DEF_HASHCODE{
public:
	size_t operator() (KEY key) { return key%SIZE; }
};

template <typename KEY, typename VALUE, int SIZE = DEF_HTABLESIZE, typename HASHCODE = DEF_HASHCODE<KEY> >
class Hash{

private:
	
	unsigned int size=SIZE;
	unsigned int num_elements = 0;
	//List<Pair<KEY,VALUE>> *listarray;
	HASHCODE hashcode;

public: 

	List<Pair<KEY, VALUE>> *listarray;

	/*********************************************************************************************/

	Hash() {
		
		size = SIZE;
		listarray = new List<Pair<KEY,VALUE>> [size];
		num_elements = 0;
		
	}

	/*********************************************************************************************/

	Hash(KEY key, VALUE value) {

		size = SIZE;
		listarray = new List<Pair<KEY, VALUE>>[size];
				
		listarray[hashcode(key)].add(Pair<KEY, VALUE>(key, value));
		num_elemnts ++;

	}

	/*********************************************************************************************/

	void insert(KEY key, VALUE value) {

		int loc = hashcode(key);

		 
		Data< Pair<KEY, VALUE> > *ptr = listarray[loc].ptr();

		if (ptr == NULL)
		{
			listarray[hashcode(key)].add(Pair<KEY, VALUE>(key, value));
			num_elements++;
			return;
		}
		
		else {

			while (ptr != NULL) {

				if (ptr->val.key == key && ptr->val.value != value ) return;

				ptr = ptr->next;

			}

		}

		listarray[hashcode(key)].add(Pair<KEY, VALUE>(key, value));
		num_elements++;

		

	}

	/*********************************************************************************************/

	void remove(KEY key){

		int loc = hashcode(key);

		//Data< Pair<KEY, VALUE> > *ptr = listarray[loc].ptr();
		
		Pair<KEY, VALUE> p(key, VALUE(NULL));

		listarray[loc].remove(p);

		num_elements--;



	}

	/*********************************************************************************************/
		
	VALUE& operator[](KEY key) { //return find(key);
	
		//KeyError exc;

		int loc = hashcode(key);

		VALUE temp_val;


		Data< Pair<KEY, VALUE> > *ptr = listarray[loc].ptr();

		if (ptr == NULL)
		{
			
			listarray[hashcode(key)].add(Pair<KEY, VALUE>(key, temp_val));
			num_elements++;
			return (listarray[hashcode(key)].end()->val).value;

			//throw exc;
			//return VALUE(NULL);
		}

		else {

			while (ptr != NULL) {

				if (ptr->val.key == key) return (ptr->val.value);

				ptr = ptr->next;

			}

		}

		
		listarray[hashcode(key)].add(Pair<KEY, VALUE>(key, temp_val));
		num_elements++;
		return (listarray[hashcode(key)].end()->val).value;

		//throw exc;
		//return VALUE(NULL);
	
	
	
	
	}

	/*********************************************************************************************/

	VALUE find (KEY key){

		KeyError exc;

		int loc = hashcode(key);


		Data< Pair<KEY, VALUE> > *ptr = listarray[loc].ptr();

		if (ptr == NULL)
		{
			throw exc;
			return VALUE(NULL);
		}

		else {

			while (ptr != NULL) {

				if (ptr->val.key == key) return (ptr->val.value);

				ptr = ptr->next;

			}

		}

		throw exc;
		return VALUE(NULL);
		


	}

	/*********************************************************************************************/

	int number_elements() { return num_elemnts; }

	/*********************************************************************************************/

	KEY* keys() {

		KEY* results = new KEY[num_elements];
		int results_index = 0;

		

		for (int i = 0; i < size; i++){

			Data< Pair<KEY, VALUE> > *ptr = listarray[i].ptr();

			while (ptr != NULL) {
				
				results[results_index] = ptr->val.key;
				
				results_index++;

				ptr = ptr->next;
			}
		}

		return results;


	}

	/*********************************************************************************************/


	~Hash() {
		delete[] listarray;
	}

	/*********************************************************************************************/




};


class KeyError : public exception
{
public:
	virtual const char* what() const throw()
	{
		return "key does not exist ...";
	}
};


#endif
