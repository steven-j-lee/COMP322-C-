//Steven Lee
//260803947

#include <iostream>
#include <memory>
#include <cstdlib>
#include <array>

using namespace std;

//exception handling class
class NegativeException: public exception
{  
    public:
    virtual const char* what() const throw()
    {
        return "Error, negative number :) ";
    }
};
//exception handling array out of bounds
class ArrayOutOfBounds: public exception
{
    public:
     virtual const char* what() const throw()
     {
        return "Error, array out of bounds :) ";
    }
};

class DifferentArraySize: public exception
{
    public:
     virtual const char* what() const throw()
     {
        return "Error, two arrays of different sizes :) ";
    }

};

NegativeException negativeException;
ArrayOutOfBounds arrayOutOfBounds;
DifferentArraySize differentArraySize;

/*Question 1 
https://stackoverflow.com/questions/106508/what-is-a-smart-pointer-and-when-should-i-use-one
https://en.cppreference.com/book/intro/smart_pointers
http://www.cplusplus.com/reference/memory/unique_ptr/
http://www.cplusplus.com/reference/memory/shared_ptr/
https://thispointer.com/learning-shared_ptr-part-1-usage-details/
https://en.cppreference.com/w/cpp/memory/weak_ptr
https://stackoverflow.com/questions/12030650/when-is-stdweak-ptr-useful
http://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/memory/weak_ptr.html
https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/SmartPointerLibrary/WeakPointer

Smart pointer acts as a class which manages the life of the thing that the pointer is pointed to.
In other words, it manages by itself to prevent forgetting to delete the pointer, thus helping with memory leaks

There exists three templates for smart pointers:
1. unique_ptr

    unique pointers points to an object, and it is automatically deleted where they are destroyed.
    Unique pointers are set the moment they are created. They cannot be copied (only one owner per pointer, and making a copy 
    will cuase a compile-time error). But they can be moved to another unique_ptr<>, at the cost of invalidating the original

2. shared_ptr:
    Shared pointer allow for multiple objects of this type to point to the same pointer. It uses a reference counting method to keep track.
    This type of smart pointer points to two things in memory: the pointer pointing to the object, 
    and the pointer that keep tracks of the data through a counting mechanism (increments when new pointer points to an object, and 
    decrement when destructor of the object is called)

    However, the object pointed by the raw pointer will not be deleted, until all of the shared pointers are deleted also.
    So, only use shared_ptr for when we want one pointer to have multiple owners.

3. weak_ptr:
    These pointers allow pointing to an object that is already being managed by a shared pointer (created as a copy of a shared_ptr)
    but! It is not included in the reference counting. 
    weak pointers only allow temporary ownership of an object, since they can only access objects that already exists. They
    also cannot stop the deletion of an object it is pointing to. In other words, they are useful for keeping track of an object,
    In addition, It is also useful when breaking the cycle of the circular references of the shared pointer.


4. auto_ptr:
    This was the first implementation of the smart pointer. However, it was replaced by unique_ptr in the C++11 standard library.
            */	


/* question 2*/
/*
class SmartPointer
{
    private:
        int* value;
    
    public:
        //call constructor
        SmartPointer(){
            this->value = new int;
            *(this->value) = 0;
           // cout << "counstructor was called" << endl;
        }

        //call destructor
        ~SmartPointer(){
            delete this->value;
          //  cout << "destructor was called" << endl;
        }

        //pass integer as variable
        SmartPointer(int n){
            //question 3 test for exception (negative and when os runs out of space)
            //for bad allocation: http://www.cplusplus.com/reference/new/bad_alloc/
            //http://www.cplusplus.com/forum/beginner/208406/
            try
            {
                this->value = new int;

                if(n < 0) {
                    throw negativeException;
                }
            }
            catch(const std:: bad_alloc& e){
                cerr << "Error: ran out of memory " << e.what() << 'n';
            }
            catch(NegativeException e)
            {
                cerr << e.what() << 'n';
            }
        }

        int getValue(){  
                return *(this->value);
        }

        void setValue(int n){
            //question 3
             try
            {
                this->value = new int;

                if(n < 0) {
                    throw negativeException;
                }
                
                *(this->value) = n;
            }

            catch(const std:: bad_alloc& e){
                cerr << "Error: ran out of memory " << e.what() << 'n';
            }
            catch(NegativeException e)
            {
                cerr << e.what() << endl;
            }
        }
}; 

// Question 4 
//make class handle generic types http://www.cplusplus.com/doc/oldtutorial/templates/
// automatically delete memory for built-in integer type allocated through it


template <typename T>  class SmartPointer
{
    private:
        T* value; //value of smartpointer we will be manipulating with

    public:
        SmartPointer(){
            this-> value = new T;
            *(this-> value) = 0;
        }
        //call destructor
        ~SmartPointer(){
             delete this->value;
        } 

        void setValue(T n){
        //exception handling from q3
            try
            {
                 this-> value = new T;
                 *(this->value) = n;

                 if(n <0){
                     throw negativeException;
                 }
            }
            catch(const std:: bad_alloc& e){ cerr << "Error: ran out of memory" << e.what() << 'n'; }
            catch(NegativeException e){ cerr << e.what() << endl; }
        }

        SmartPointer(T n){
            //use setvalue function which also has error handling implemented
            setValue(n);
        }

        T getValue(){
            return *(this->value);
        }
        
        */
        
        /* question 5 */
        //overload operators using friend funciton
        //http://www.cplusplus.com/doc/tutorial/inheritance/
        //https://www.learncpp.com/cpp-tutorial/92-overloading-the-arithmetic-operators-using-friend-functions/

        /*
        friend SmartPointer operator + (const SmartPointer<T> &pointer1, const SmartPointer<T> &pointer2){
            return SmartPointer<T> ( (*pointer1.value) + (*pointer2.value));
        }

        friend SmartPointer operator - (const SmartPointer<T> &pointer1, const SmartPointer<T> &pointer2){
            return SmartPointer<T> ( (*pointer1.value) - (*pointer1.value));
        }

        friend SmartPointer operator * (const SmartPointer<T> &pointer1, const SmartPointer<T> &pointer2){
            return SmartPointer<T> ( (*pointer1.value) * (*pointer2.value) );
        }

    };
    */  


    /*Question 6: smartpointer Arrays*/

    template <typename T> 
    class SmartPointer
    {
        private:
        T *value;
        int size;

        public:
                //for single value, i.e. not array
                SmartPointer(){
                   this-> value = new T;
                   *(this->value) = 0;
                   this->size = 1;
                }

                   ~SmartPointer(){
                    if(this->size == 1)
                    {
                        delete this->value;
                    } else{
                        delete[] this->value;
                    }
                }

                SmartPointer(T n){
                        //use setvalue function which also has error handling implemented
                        setValue(n);
                 }

                 void setValue(T n){
                    //exception handling from q3
                        try
                        {
                            this-> value = new T;
                            *(this->value) = n;

                            if(n <0){
                                throw negativeException;
                            }
                        }
                        catch(const std:: bad_alloc& e){ cerr << "Error: ran out of memory" << e.what() << 'n'; }
                        catch(NegativeException e){ cerr << e.what() << endl; }
                }

                //get value for a single value
                 T getValue(){
                        return *(this->value);

                }

                //initialize for an array, taking in both the size of the array and the array itself
                SmartPointer(T array[], int size){
                    //exception handling
                    try
                    {
                        //initialize the two parameters of the constructor
                        this->size = size;
                        this->value = new T[size];
    
                    }
                    
                    catch(const std:: bad_alloc& e){ cerr << "Error: ran out of memory" << e.what() << 'n'; }
 
                    //loop through the elements, check whether an index contains a negative number
                    for(int i = 0; i < size; i++ ){
                        try{
                            //set value of the array
                            *(this->value + i) = array[i];
                            if(array[i] < 0){
                                throw negativeException;
                            }
                        }
                            catch(NegativeException e){ cerr << e.what() << endl; }
                        }   
                    }

                void setValueAt(T n, int index){
                        //catch array out of bounds error
                
                        try{
                            *(this->value + index) = n;
                            if(n < 0){
                            throw negativeException;
                                }
                            if(index > size){
                            throw arrayOutOfBounds;
                                }
                            }  
                        catch(NegativeException e){ cerr << e.what() << endl; }
                        catch(ArrayOutOfBounds e) { cerr << e.what() << endl; }
                        //assign value at the specific index
                        //while value initialized as array, it starts off at position 0. Adding index to it will give the position where we need to insert input n
                }

                T getValueAt(int index){
                    try{
                        if (index > size){
                            throw arrayOutOfBounds;
                        }
                    }

                     catch(ArrayOutOfBounds e) { cerr << e.what() << endl; }

                    T temp = *(this->value + index);
                    return temp;
                }

                //prints the array 
                  void getValues(){
                	for (int i = 0; i < this->size; i++){
                		cout << *(this->value+i) << "  ";
                	}
                	cout << endl;
                }

                 friend SmartPointer operator + (const SmartPointer<T> &pointer1, const SmartPointer<T> &pointer2){

                	if(pointer1.size != pointer2.size){
                		throw differentArraySize;
                	}

                	if(pointer1.size == 1 && pointer2.size ==1){
                		 return SmartPointer<T> ( (*pointer1.value) + (*pointer2.value));
                	} else{
                       // http://www.java2s.com/Tutorial/Cpp/0260__template/Defineyourowngenericarray.htm
                       //create generic array and add values there, then return it
                		int tempSize = pointer1.size;

                	    T temp[tempSize]; 

                	    SmartPointer<T> *tempArray = new SmartPointer<T>(temp, pointer1.size);
                	    tempArray -> size = pointer1.size;
                	
                        for(int i = 0; i < pointer1.size; i++){
                            tempArray->setValueAt(*(pointer1.value+i) + (*pointer2.value+i), i);
                        }
                        return *tempArray;
                	}
                    //return SmartPointer<T> ( (*pointer1.value) + (*pointer2.value));
                }

                friend SmartPointer operator - (const SmartPointer<T> &pointer1, const SmartPointer<T> &pointer2){
                if(pointer1.size != pointer2.size){
                		    throw differentArraySize;
                	    }

                    if(pointer1.size == 1 && pointer2.size ==1){
                		 return SmartPointer<T> ( (*pointer1.value) + (*pointer2.value));
                	} else{
                
                		int tempSize = pointer1.size;
                        
                	    T temp[tempSize]; 

                	    SmartPointer<T> *tempArray = new SmartPointer<T>(temp, pointer1.size);
                	    tempArray -> size = pointer1.size;
                	
                        for(int i = 0; i < pointer1.size; i++){
                            tempArray->setValueAt(*(pointer1.value+i) - (*pointer2.value+i), i);
                        }
                        return *tempArray;
                	    } 
                    }
                

                 friend SmartPointer operator * (const SmartPointer<T> &pointer1, const SmartPointer<T> &pointer2){
                 if(pointer1.size != pointer2.size){
                		    throw differentArraySize;
                	    }

                    if(pointer1.size == 1 && pointer2.size ==1){
                		 return SmartPointer<T> ( (*pointer1.value) + (*pointer2.value));
                	} else{
                
                		int tempSize = pointer1.size;
                        
                	    T temp[tempSize]; 

                	    SmartPointer<T> *tempArray = new SmartPointer<T>(temp, pointer1.size);
                	    tempArray -> size = pointer1.size;
                	
                        for(int i = 0; i < pointer1.size; i++){
                            tempArray->setValueAt(*(pointer1.value+i) * (*pointer2.value+i), i);
                        }
                        return *tempArray;
                	    } 
                 }




    };


int main(){
         // For SmartPointer class
cout << "Testing SmartPointer class" << endl;

// Testing Constructors
cout << "Creating a SmartPointer of type int with value 11" << endl;
SmartPointer<int> SmartIntPointer1(11);
cout << "SmartIntPointer1 = " << SmartIntPointer1.getValue() << endl;

cout << "Creating a SmartPointer of type int with value -1" << endl;
SmartPointer<int> SmartIntPointer(-1);

cout << "Creating a SmartPointer of type int with no value provided" << endl;
SmartPointer<int> SmartIntPointer2;
cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;



// Testing Setter & Getter
        cout << "Setting value of SmartIntPointer2 to 5" << endl;
        SmartIntPointer2.setValue(5);
        cout << "SmartIntPointer2 = " << SmartIntPointer2.getValue() << endl;

        cout << "Creating a SmartPointer of type float with no value provided" << endl;
        SmartPointer<float> SmartFloatPointer1;
        cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

        cout << "Setting value of SmartFloatPointer1 to 1.5" << endl;
        SmartFloatPointer1.setValue(1.5);
        cout << "SmartFloatPointer1 = " << SmartFloatPointer1.getValue() << endl;

        cout << "Creating a SmartPointer of type float with no value provided" << endl;
        SmartPointer<float> SmartFloatPointer2;
        cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

        cout << "Setting value of SmartFloatPointer2 to 2.5" << endl;
        SmartFloatPointer2.setValue(2.5);
        cout << "SmartFloatPointer2 = " << SmartFloatPointer2.getValue() << endl;

        SmartPointer<float> SmartFloatPointer3 = SmartFloatPointer1 + SmartFloatPointer2;
        cout << "SmartFloatPointer1 + SmartFloatPointer2 = " << SmartFloatPointer3.getValue() << endl;

        SmartPointer<float> SmartFloatPointer4 = SmartFloatPointer2 - SmartFloatPointer1;
        cout << "SmartFloatPointer2 - SmartFloatPointer1 = " << SmartFloatPointer4.getValue() << endl;

        SmartPointer<float> SmartFloatPointer5 = SmartFloatPointer1 * SmartFloatPointer2;
        cout << "SmartFloatPointer1 * SmartFloatPointer2 = " << SmartFloatPointer5.getValue() << endl;


        cout << "Testing arrays" << endl;
        cout << "Question 6" << endl;

        int temp[] = {1,2,3,4,5};
        cout << "array: {1,2,3,4,5}" << endl;

        SmartPointer<int> n(temp, 5);
        //index for get value starts at 1. I.e. index 0 would be 1
        cout << "value at the 2nd slot: " << n.getValueAt(0) << endl;

        cout << "value at the 5th slot: " << n.getValueAt(4) << endl;

        n.setValueAt(12, 5);
        cout << "set value 12 at 3rd slot: " << n.getValueAt(3) << endl;

        cout << "set 22 value at index 11 (out of bounds): " << endl;
        n.setValueAt(22, 111);

        cout << "set negative value at index 4" << endl;
        n.setValueAt(-22, 4);

        cout << "resetting array..." << endl;
        n.setValueAt(5,4);

        cout << "array 2: {1,2,3,4,5}" << endl;
       int temp2[] = {1,2,3,4,5};
       SmartPointer<int> n2(temp2, 5);

       n.getValues();
       n2.getValues();

       cout << "use operators" << endl;

       cout << "array1 + array2" << endl;
 		SmartPointer<int> n3 = n + n2;
 		n3.getValues();

        cout << "array 3: {1,1,1,1,1}" << endl;
        cout << "array1 - array3" << endl;
        int temp3[] = {1,1,1,1,1};
        SmartPointer<int> sub(temp3, 5);
        SmartPointer<int> n4 = n - sub;
        cout << "Array after" << endl;
        n4.getValues();

        cout << "array1 * array2" << endl;
        SmartPointer<int> n5 = n * n2;
        cout << "Array after" << endl;
        n5.getValues();

        cout << "End of program! good work! :) " << endl;
    
        return 0;

}   
