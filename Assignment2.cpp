//Joo Hyung Lee
//260803947

#include <iostream>
#include <iterator>
#include <algorithm>
#include <ctime>
#include <random>


using namespace std;

struct ticket
{
    unsigned int numbers[6];
    ticket* next;
};

class SuperDraw
{
    public:
            SuperDraw();
            ~SuperDraw();
            SuperDraw(SuperDraw &obj);
            void newTicket(int verbose);
            SuperDraw(int n);
            void printAllTicketNumbers();
            bool verifySequence(unsigned int toVerify[]);
            bool deleteSequence(unsigned int toDelete[]);
            //void testFuction(int verbose);


     private:
            ticket* ticketListHead;
            ticket* ticketListTail;
};

             /* test function to see when same ticket generated, verifySequence properly assesses whether the ticket
            already exists or not */
           /* void SuperDraw:: testFuction(int verbose = 0){
                ticket* temp = new ticket;
                 unsigned int tempArray[6] = {2,4,17,29,31,34};

                 for(int i = 0; i < 6; i++){
                     temp->numbers[i] = tempArray[i];
                 }

                   if(verbose == 1){
                cout << "A new ticket was successfully generated. the numbers are: ";

                for(int i = 0; i < 6; i++){
                    cout << temp->numbers[i] << " ";
                }
                    cout << endl;
                }
                
                if(ticketListHead == nullptr){
                    ticketListHead = temp;
                    ticketListTail = ticketListHead;
                }
                else{
                    temp->next = ticketListHead;
                    ticketListHead = temp;
                }
            
                
            }  */

            SuperDraw::SuperDraw()
            {
                this->ticketListHead = nullptr;
                this->ticketListTail = nullptr;
             //cout << "constructor was called" << endl;
            }

            SuperDraw::~SuperDraw()
            {
             //delete[] this->ticketListHead;
             //delete[] this->ticketListTail;
            //cout << "destructor was called" << endl;

              ticket* current = ticketListHead;
              while(current != nullptr){
                  ticket* next = current->next;
                  delete current;
                  current = next;
              }
            }

             void SuperDraw:: newTicket(int verbose = 0) {

                ticket* tempticket = new ticket;

                tempticket->next = nullptr;

                unsigned int tempArray[6];
                int size = 6;
                int tempNumber;
                
                for(int i = 0; i < size; i++){
                    bool same;
                    do
                    {
                        same = false;
                        tempArray[i] = rand() % 49 + 1;

                        for(int check = 0; check < i; check++){
                            if(tempArray[i] == tempArray[check]){
                                same = true;
                                break;
                            }
                        }
                    } while(same);
                }
               
        

                //sort order of numbers of the ticket
                for(int j =  0; j < size; j++){
                    for(int k = 0; k < size; k++){
                        if(tempArray[j] < tempArray[k]){
                            tempNumber = tempArray[j];
                            tempArray[j] = tempArray[k];
                            tempArray[k] = tempNumber;
                        }
                    }
                }

                  for(int i = 0; i < size; i++){
                    tempticket->numbers[i] = tempArray[i];
                }

                //print out array and copy it to the temp ticket node
                if(verbose == 1){
                cout << "A new ticket was successfully generated. the numbers are: ";

                for(int i = 0; i < size; i++){
                    cout << tempticket->numbers[i] << " ";
                }
                    cout << endl;
                }

                //if nothing exists in the list, add the ticket we created
                if(ticketListHead == nullptr){
                    ticketListHead = tempticket;
                    ticketListTail = ticketListHead;
                }
                //else go in the list, and add first
                else{
                    tempticket->next = ticketListHead;
                    ticketListHead = tempticket;
                }
            }

            SuperDraw:: SuperDraw(int n){
                int i = 0;
                while(i < n){
                    newTicket(1);
                    i++;
                }
            }


            void SuperDraw:: printAllTicketNumbers(){
                int counter = 0;
                int size = 6;

                ticket* temp= new ticket;
                
                temp = ticketListHead;
                //while there is no "null" ticket, go through the list and print out the ticket(s) numbers
                while(temp != nullptr){ 

                    for(int i = 0; i < size; i++){
                        cout << temp->numbers[i] << " ";
                    }
                    cout << endl;

                    temp = temp->next;
                    counter++;
                }
                cout << "We found " << counter << " generated ticket(s)." << endl;
            }

            bool SuperDraw:: verifySequence(unsigned int toVerify[]){
                ticket* temp = new ticket;
                bool checker = true;
                int size = 6;

                temp = ticketListHead;

                while(temp != nullptr){
                        for(int i = 0; i < size; i++){
                            //check through the list, go through the tickets, go through the list unless it finds a ticket with the same values.
                            //without the return statements, the messages loops for all the tickets, returns to boolean for sake of print readability
                            if(temp->numbers[i] != toVerify[i]){
                                cout <<  "The Provided sequence of numbers was never generated before" << endl;
                                return checker = false;
                            }   
                                cout << "The provided sequence of numbers was already generated" << endl;
                                return checker = true;
                        }
                        //go through all the tickets in the linked list
                        temp = temp->next;
                } return true;
            }

            bool SuperDraw:: deleteSequence(unsigned int toDelete[]){
                ticket* temp = new ticket;
                bool checker = true;
                int size = 6;
            
                temp = ticketListHead;
            //Similarly to verifySequence, when it finds a ticket with the same values, delete it 
            //without the return statements, messages loops for all the tickets, returns to boolean for sake of print readability
                while(temp!= nullptr){
                    for(int i = 0; i < size; i++){
                        //check if it's not equal
                        if(temp->numbers[i] != toDelete[i]){
                            cout <<  "The Provided sequence of numbers was never generated before" << endl;
                            return checker = false;
                        } 
                        //delete the ticket 
                         temp->next = temp->next->next;
                         cout <<  "The Provided sequence of numbers was successfully deleted" << endl;
                         return checker = true;
                }
                temp = temp -> next;
            } return true;  
        }

        SuperDraw:: SuperDraw(SuperDraw &obj){
            int size = 6;
            ticket* temp = obj.ticketListHead;
            ticket* current = new ticket;

            //point head to ticket temp which points to sd's ticket head
            ticketListHead = current;
            
            //deep copy all the numbers of the ticket, and all the tickets
            while(temp != nullptr){
                for(int i = 0; i < size; i ++){
                    current->numbers[i] = temp->numbers[i];
                }
                temp = temp->next;
                if(temp != nullptr){
                    current->next = new ticket;
                    current = current->next;
                } else{
                    current->next = nullptr;
                }
            } 
        }

           


    int main(){
       srand(time(NULL));
       SuperDraw sd;
       //SuperDraw sd(2);

       //sd.newTicket(1);

       sd.newTicket();
       //sd.newTicket();
       //sd.newTicket();
       //sd.newTicket();
       
      SuperDraw sd2(sd);
      //sd.printAllTicketNumbers();
      sd2.printAllTicketNumbers();
      //unsigned int myNumbers[6] = {2,4,17,29,31,34};
      //sd.verifySequence(myNumbers);
      //sd.deleteSequence(myNumbers);
    }