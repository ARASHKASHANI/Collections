#ifndef List_h
#define List_h

#include "Data.h"

#include <iostream>
using namespace std;

template <typename U>
class List {
private:
	Data <U>* head;
	Data <U>* tail;
	unsigned int size;

public:
	/*********************************************************************************************/
	~List(){

		Data <U>* itr = head;

		if (size>1){
			Data <U>*  itr_nxt = head->next;




			int i = 0;

			while (itr != NULL) {

				if ((itr) != tail) {


					if (itr_nxt != NULL){
						head = itr_nxt;
						delete itr;
						itr = head;
						itr_nxt = head->next;

						i++;
					}





				}

				else {

					delete tail;
					break;
				}



			}

		}

		else {
			delete itr;
		}



	}

	/*********************************************************************************************/

	void clear() {

		Data <U>* itr = head;
		Data <U>*  itr_nxt = head->next;


		int i = 0;

		while (itr != NULL) {

			if ((itr) != tail) {


				if (itr_nxt != NULL){
					head = itr_nxt;
					delete itr;
					itr = head;
					itr_nxt = head->next;

					i++;
				}





			}

			else {

				delete tail;
				break;
			}



		}


		head = NULL;
		tail = NULL;
		size = 0;



	}

	/*********************************************************************************************/

	List() : head(NULL), tail(NULL), size(0){}

	List(U* arr, int arrsize) : head(NULL), tail(NULL){

		for (int i = 0; i <arrsize; i++){
			Data <U> *data = new Data <U>(arr[i]);
			if (head == NULL){

				head = data;
				size++;
				tail = head;

			}

			else {

				tail->next = data;
				tail = data;
				size++;


			}
		}


	}

	/*********************************************************************************************/

	List(List <U> & list) : head(NULL), tail(NULL), size(0)   {



		Data <U>* itrlist = list.head;


		while (itrlist != NULL) {

			Data <U> *data = new Data <U>(itrlist->val);
			data->next = itrlist->next;

			if (head == NULL){

				head = data;
				size++;
				tail = head;

			}

			else {

				tail->next = data;
				tail = data;
				size++;


			}

			itrlist = itrlist->next;

		}




	}

	/*********************************************************************************************/

	List(U new_mem) : head(NULL), tail(NULL), size(0){

		Data <U> *data = new Data <U>(new_mem);



		if (head == NULL){

			head = data;
			size++;
			tail = head;



		}

		else {

			tail->next = data;
			tail = data;
			size++;


		}


	}

	/*********************************************************************************************/

	List<U>& operator= (List <U> & list)    {



		Data <U>* itrlist = list.head;


		while (itrlist != NULL) {

			clear();
				
			Data <U> *data = new Data <U>(itrlist->val);
			data->next = itrlist->next;

			if (head == NULL){

				head = data;
				size++;
				tail = head;

			}

			else {

				tail->next = data;
				tail = data;
				size++;


			}

			itrlist = itrlist->next;

		}


		return*this;

	}


	/*********************************************************************************************/
	

		bool isEmpty() {

			if (head != NULL) {
				return true; }
			else { 
				return false; }

		}

	
	/*********************************************************************************************/

	void add(U new_mem){

		Data <U> *data = new Data <U>(new_mem);



		if (head == NULL){
			
			head = data;
			size++;
			tail = head;



		}

		else {

			tail->next = data;
			tail = data;
			size++;


		}

	}

	/*********************************************************************************************/

	void add(U* arr, int arrsize){

		for (int i = 0; i <arrsize; i++){
			Data <U> *data = new Data <U>(arr[i]);
			if (head == NULL){

				head = data;
				size++;
				tail = head;

			}

			else {

				tail->next = data;
				tail = data;
				size++;


			}
		}


	}

	/*********************************************************************************************/

	void add(List <U> & list){

		if (this == &list) return;

		Data <U>* itrlist = list.head;

		while (itrlist != NULL) {

			Data <U> *data = new Data <U>(itrlist->val);
			data->next = itrlist->next;

			if (head == NULL){

				head = data;
				size++;
				tail = head;

			}

			else {

				tail->next = data;
				tail = data;
				size++;


			}

			itrlist = itrlist->next;

		}



	}

	/*********************************************************************************************/

	void disp(){

		int i = 0;
		Data <U>* itr = head;
		
		while (itr != NULL) {

			cout << "data [" << i << "]= " << (itr->val) << endl;

			i++;
			itr = itr->next;

		}


	}

	/*********************************************************************************************/

	int len(){ return size; }

	/*********************************************************************************************/

	bool isMember(U mem){

		int i = 0;
		Data <U>* itr = head;

		while (itr != NULL) {

			if ((itr->val) == mem) return true;

			i++;
			itr = itr->next;

		}

		return false;

	}

	/*********************************************************************************************/

	void remove(U val_check){

		int i = 0;
		Data <U>* itr = head;
		Data <U>* itr_prv = head;

		Data <U>* itr_temp = head;





		while (itr != NULL) {

			if ((itr->val) == val_check) {

				itr_temp = itr;

				if (i == 0) {
					head = itr->next; 
					
					delete itr_temp;

					return;
				} // the elemnt to remove is located at the head
				
				

				itr_prv->next = itr->next;
				itr = itr_prv;
				i++;
				itr_prv = itr;

				if (itr->next == NULL) tail = itr; // the elemnt to remove is located at the tail
				itr = itr->next;

				delete itr_temp;

				size--;
				return;

			}

			i++;
			itr_prv = itr;
			itr = itr->next;



		}



	}

	/*********************************************************************************************/

	void removeall(U val_check){
		int i = 0;
		Data <U>* itr = head;
		Data <U>* itr_prv = head;


		Data <U>* itr_temp = head;


		while (itr != NULL){

			itr_temp = itr;

			if (itr->val == val_check) {

				if (head->val == val_check){
					head = itr->next;
				}
				
				itr_prv->next = itr->next;
				itr = itr->next;

				delete itr_temp;
				
				continue;

			}

			
			itr_prv = itr;
			itr = itr->next;
		}

		if (tail->next == NULL) {
			tail = itr_prv;
		}


	}

	/*********************************************************************************************/

	void replace(U src, U target){

		int i = 0;
		Data <U>* itr = head;
		Data <U>* itr_prv = head;

		Data <U> *data_target = new Data <U>(target);


		while (itr != NULL) {

			if ((itr->val) == src) {


				itr_prv->next = data_target;
				data_target->next = itr->next;

				itr = itr_prv;
				return;


			}

			i++;
			itr_prv = itr;
			itr = itr->next;

		}



	}


	/*********************************************************************************************/


	void replaceall(U src, U target){

		int i = 0;
		Data <U>* itr = head;
		Data <U>* itr_prv = head;

		Data <U> *data_target = new Data <U>(target);


		while (itr != NULL) {

			if ((itr->val) == src) {


				itr_prv->next = data_target;
				data_target->next = itr->next;

				itr = itr_prv;



			}

			i++;
			itr_prv = itr;
			itr = itr->next;

		}



	}

	/*********************************************************************************************/

	Data <U> *ptr(){ return head; }

	Data <U> *end(){ return tail; }

	/*********************************************************************************************/

	U* toArray(){

		U* ptr = new U[size];

		int i = 0;
		Data <U>* itr = head;

		while (itr != NULL) {

			ptr[i] = itr->val;

			i++;
			itr = itr->next;

		}

		return ptr;


	}

	/*********************************************************************************************/

	bool operator== (List<U> list){

		if (this == &list) return true;
		if (head == NULL && list.head == NULL) return true;
		if (this == NULL && &list == NULL) return true;
		if (size != list.size) return false;

		if (size == list.size) {
			Data <U>* itr = head;
			Data <U>* itr_list = list.head;

			


			while (itr != NULL) {

				if (itr->val != itr_list->val) {

					return false;

				}

				else {

					itr = itr->next;
					itr_list = itr_list->next;
					
				}
				

			}

			return true;


		}

	}

	/*********************************************************************************************/

	bool operator!= (List<U> list){
		return !operator == (list);
	}

	/*********************************************************************************************/

	bool operator> (List<U> list){
		if (this==NULL || &list==NULL) return false
		if (size > list.size) { return true; }
		else { return false; }
	}

	/*********************************************************************************************/

	bool operator< (List<U> list){
		if (this == NULL || &list == NULL) return false
		if (size < list.size) { return true; }
		else { return false; }
	}

	/*********************************************************************************************/

	bool operator>=(List<U> list){
		if (this == NULL || &list == NULL) return false
		return (operator==(List) || operator>(List) );
	
	}

	/*********************************************************************************************/

	bool operator<= (List<U> list){
		if (this == NULL || &list == NULL) return false
		return (operator==(List) || operator<(List));
	}


};





#endif