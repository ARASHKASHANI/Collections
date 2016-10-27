#ifndef Vector_h
#define Vector_h

#include <exception>


template <typename U>
class Vector{

private:
	unsigned int size;
	unsigned int capacity;
	double sizefactor;
	U *array;


public:

	/*********************************************************************************************/
	Vector(){
		size = 0;
		sizefactor = 1.1;
		capacity = 0;
		
		array = NULL;
	}

	Vector(unsigned int vsize,U val){
		size = vsize;
		sizefactor = 1.1;
		capacity = ceil(sizefactor*size);
		
		array = new U[capacity];
		for (int i = 0; i < vsize; i++){
			array[i] = val;
		}
		//for (int i = vsize; i < capacity; i++){
		//	array[i] = 0;
		//}
	}

	Vector(const U& copy_vector){

		if (copy_vector != NULL){
			size = copy_vector.size;
			sizefactor = copyvector.sizefactor;
			capacity = copy_vector.capacity;

			array = new U[capacity];

			for (int i = 0; i < capacity; i++){
				array[i] = copy_vector.array[i];
			}

		}


	}

	Vector(U *somearray, unsigned int somesize){
		size = somesize;
		sizefactor = 1.1;
		capacity = ceil(sizefactor*size);
		array = new U[capacity];

		for (int i = 0; i < size; i++){
			array[i] = somearray[i];
		}
		//for (int i = vsize; i < capacity; i++){
		//	array[i] = 0;
		//}

	}

	/*********************************************************************************************/
	~Vector(){
		if (array != NULL){
			delete[] array;
		}
	}

	/*********************************************************************************************/
	unsigned int getSize() { return size; }
	unsigned int getCapacity() { return capacity; }
	double getSizefactor() { return sizefactor; }
	void setSizefactor(unsigned int newsizefactor){ sizefactor = newsizefactor; }
	/*********************************************************************************************/

	void resize(unsigned int newsize){

		if (size != newsize) {

			// store current values in vector to a temporary array
			unsigned int tempsize = size;
			U* temparray = new U[capacity];
			for (unsigned int i = 0; i < capacity; i++){
				temparray[i] = array[i];
			}

			// create new vector
			if (array != NULL) {
				delete[] array;
				array = NULL;
			}


			size = newsize;
			capacity = unsigned int(ceil(sizefactor*size));
			array = new U[capacity];

			// find the minimum between the current size and the newsize

			unsigned int safesize = (tempsize < newsize) ? tempsize : newsize;
			if (safesize == 0 && newsize != 0) safesize = newsize;

			for (unsigned int i = 0; i < safesize; i++){
				array[i] = temparray[i];
				}


			//for (int i = safesize; i < capacity; i++){
			//	array[i] = temparray[i];
			//}

			delete[] temparray;



		}


	}

	/*********************************************************************************************/

	bool isEmpty(){
		if (array == NULL) return true;
		return false;

	}

	/*********************************************************************************************/
	void clear(){
		if (array != NULL) {
			delete[] array;
			array = NULL;
			size = 0;
			
			capacity = 0;

		}
	}

	/*********************************************************************************************/

	void reserve(unsigned int additionalspace){

			// store current values in vector to a temporary array
			unsigned int tempsize = size;
			U* temparray = new U[capacity];
			for (int i = 0; i < capacity; i++){
				tempaaray[i] = array[i];
			}

			// create new vector
			if (array != NULL) delete[] array; array = NULL;
			
			capacity = ceil(sizefactor*size)+additionalspace;
			sizefactor = capacity/size;
			array = new array[capacity];
						

			for (int i = 0; i < size; i++){
				array[i] = temparray[i];
			}
			//for (int i = size; i < capacity; i++){
			//	array[i] = 0;
			//}

			delete[] temparray;


	}

	/*********************************************************************************************/

	Vector<U> operator=(const Vector<U>somevector){
		
		if (array != NULL) delete[] array; array = NULL;

		size = somevector.size;
		sizefactor = somevector.sizefactor;
		capacity = somevector.capacity;

		array = new U[capacity];

		for (int i = 0; i < capacity; i++){
			array[i] = somevector.array[i];
		}

		return *this;

	}

	U& operator[](unsigned int index){

		VectorBoundError exc;

		if (array != NULL) {
			if (index > size) throw exc;
			return array[index];
		}

	}

	bool operator== (const Vector<U> somevector){
		
		if (size != somevector.size) return false;

		if (size == somevector.size){
			for (int i = 0; i < size; i++){
				if (array[i] != somevector.array[i]) return false;
			}
		}

		return true;
		
	}


	bool operator!= (Vector<U> const somevector){

		return !operator==(somevector);

	}


	bool operator> (Vector<U> const somevector){

		if (this == NULL || &somevector == NULL) return false;
		if (size > somevctor.size)  return true;
		return false;

	}

	bool operator< (Vector<U> const somevector){

		if (this == NULL || &somevector == NULL) return false;
		if (size < somevctor.size)  return true;
		return false;

	}

	bool operator>=(Vector<U> somevector){
		if (this == NULL || &somevector == NULL) return false;
			return (operator==(somevector) || operator>(somevector));

	}

	bool operator<=(Vector<U> somevector){
		if (this == NULL || &somevector == NULL) return false;
			return (operator==(somevector) || operator<(somevector));

	}
	


	/*********************************************************************************************/

	U* toArray(){
		if (this != NULL){
			U* ptr = new U[size];

			for (int i = 0; i < size; i++){
				ptr[i] = array[i];
			}

			return ptr;
		}

		return NULL;
	}
	


	/*********************************************************************************************/

	void insert(unsigned int index, U value ){
		if (this != NULL) {

			if (index <= capacity){
				array[index] = value;
				if (index > size) {
					size = index;
					sizefactor = capacity / size;
				}
			}

			if (index > capacity){
				resize(index);
				array[index] = value;
			}

		}
		
	}


	void insert(unsigned int index, const U* newarray, unsigned int arraysize){
		if (this != NULL) {

			if (index+arraysize <= capacity){

				for (int i = index; i<index + arraysize; i++){

					array[i] = newarray[i-index];
					if (i > size) {
						size = i;
						sizefactor = capacity / size;
					}
				}


			}

			if (index+arraysize > capacity){
				resize(index+arraysize);

				for (int i = index; i < index + arraysize; i++){
					array[i] = newarray[i-index];
				}
			}



		}

	}


	void insert(unsigned int index, const Vector<U> somevector){
		if (this != NULL) {

			if (index + somevector.size <= capacity){

				for (int i = index; i<index + somevector.size; i++){

					array[i] = somevector.array[i-index];
					if (i > size) {
						size = i;
						sizefactor = capacity / size;
					}
				}


			}

			if (index + somevector.size > capacity){
				resize(index + somevector.size);

				for (int i = index; i < index + somevector.size; i++){
					array[i] = somevector.array[i - index];;
				}
			}



		}

	}


	/*********************************************************************************************/

	void remove(unsigned int index){

		if (this != NULL){


			if (index < size){

				for (unsigned int i = index; i < size; i++){
					array[i] = array[i + 1];
				}

				size--;
				sizefactor = capacity / size;

			}

			if (index == size) {
				size--;
				sizefactor = capacity / size;
			}

			return;


		}


	}


	void remove(unsigned int bindex, unsigned int eindex){

		if (this != NULL){


			if (bindex < size){

				for (unsigned int i = bindex; i < eindex; i++){
					remove(i);
				}

				size--;
				sizefactor = capacity / size;


			}

			if (bindex == size) {
				size--;
				sizefactor = capacity / size;
			}

			return;


		}


	}

	/*********************************************************************************************/


	void fill(unsigned int length, U value){

		if (array != NULL){

			for (unsigned int i = 0; i < length; i++){

				if (i < size) {
					array[i] = value;
				}
			}




		}





	}


	void fill(unsigned int bindex, unsigned int length, U value){

		if (array != NULL){

			for (unsigned int i = bindex; i < length; i++){

				if (i < size) {
					array[i] = value;
				}
			}




		}





	}





};



class VectorBoundError : public std::exception
{
public:
	virtual const char* what() const throw()
	{
		return "out of bound exception ...";
	}
};




#endif
