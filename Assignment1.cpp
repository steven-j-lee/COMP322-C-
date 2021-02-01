//Steven Lee
//260803947

#include <iostream>
#include <ctype.h>
using namespace std;

void countLetter();
void convertPhonetic();
void factorial();
void enhancedFactorial();


int main(){

	countLetter();

	convertPhonetic();

	factorial();

	enhancedFactorial();

	return 0;
}

void countLetter(){

//initialize variables
	string inputSentence;
	char letterInput;
	int countLetter = 0;

	cout << "Please enter a sentence: ";
	//store input
	getline(cin, inputSentence);

	cout << "Please enter a letter: ";
	cin >> letterInput;

	for(int i =0; i < inputSentence.length(); i++){
		//use tolower() to take uppercase letters, and convert it as lowercase letters
		if(tolower(inputSentence[i]) == letterInput){
			countLetter++;
		}
	}

	cout << "The letter " << letterInput;
	cout << " is repeated " << countLetter;
	cout << " times in your sentence" << endl;


//ignores the maximum amount of characters until it reaches '\n'
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
}

void convertPhonetic(){

	string wordInput;
	int numberChecker;

	int counter = 0;

	//stores the NATO alphabet in a string array
	/*string alphabet[26] = {"Alfa ","Bravo ","Charlie ","Delta ","Echo ","Foxtrot ","Golf ","Hotel ","India ","Juliet ","Kilo ","Lima ",
	"Mike ", "November ", "Oscar ", "Papa ", "Quebec ", "Romeo ", "Sierra ", "Tango ", "Uniform ", "Victor ", "Whiskey ", "X-ray ",
	"Yankee ", "Zulu "}; */

	cout << "Please enter a word: ";
	getline(cin, wordInput);

	if(wordInput.empty()){
		cout << "Error: you have not entered a word." << endl;
		cin.clear();
	}

	//for loop to iterate through string and check each character whether it is an integer or not
	for(int j = 0; j < wordInput.length(); j++){
		//checks for the first occurence of an interger within the input, and if it finds one, break the loop.
		if(isdigit(wordInput[j])){
			cout << "Error: you have entered an interger." << endl;
			cin.clear();
			break;	
		}
	}

	while(counter < wordInput.length()){
			switch(wordInput[counter]){
				//formatted this way for the sake of making it shorter 
				//On one line, there's the cases for both capital and small letters
				//for each value (case), switch determines if the word is equal to the specific case.
				//Then outputs the proper NATO alphabet
				case 'A': cout << "Alfa "; break; case 'a': cout << "Alfa "; break;
				case 'B': cout<<"Bravo "; break; case 'b': cout<<"Bravo "; break;
			    case 'C': cout<<"Charlie "; break; case 'c': cout<<"Charlie "; break;
			    case 'D': cout<<"Delta "; break; case 'd': cout<<"Delta "; break;
			    case 'E': cout<<"Echo "; break; case 'e': cout<<"Echo "; break;
			    case 'F': cout<<"Foxtrot "; break; case 'f': cout<<"Foxtrot "; break;
			    case 'G': cout<<"Golf "; break; case 'g': cout<<"Golf "; break;
			    case 'H': cout<<"Hotel "; break; case 'h': cout<<"Hotel "; break;
			    case 'I': cout<<"India "; break; case 'i': cout<<"India "; break;
			    case 'J': cout<<"Juliet "; break; case 'j': cout<<"Juliet "; break;
			    case 'K': cout<<"Kilo "; break; case 'k': cout<<"Kilo "; break;
			    case 'L': cout<<"Lima "; break; case 'l': cout<<"Lima "; break;
			    case 'M': cout<<"Mike "; break; case 'm': cout<<"Mike "; break;
			    case 'N': cout<<"November "; break; case 'n': cout<<"November "; break;
			    case 'O': cout<<"Oscar "; break; case 'o': cout<<"Oscar "; break;
			    case 'P': cout<<"Papa "; break; case 'p': cout<<"Papa "; break;
			    case 'Q': cout<<"Quebec "; break; case 'q': cout<<"Quebec "; break;
			    case 'R': cout<<"Romeo "; break; case 'r': cout<<"Romeo "; break;
			    case 'S': cout<<"Sierra "; break; case 's': cout<<"Sierra "; break;
			    case 'T': cout<< "Tango "; break; case 't': cout<< "Tango "; break;
			    case 'U': cout<< "Uniform "; break; case 'u': cout << "Uniform "; break;
			    case 'V': cout<< "Victor "; break; case 'v': cout<< "Victor "; break;
			    case 'W': cout<< "Whiskey "; break; case 'w': cout<< "Whiskey "; break;
			    case 'X': cout<< "X-Ray "; break; case 'x': cout<< "X-Ray "; break;
			    case 'Y': cout<< "Yankee "; break; case 'y': cout<< "Yankee "; break;
			    case 'Z': cout<< "Zulu "; break; case 'z': cout<< "Zulu "; break;
				} 
				counter++;
			} 
			cout << endl;
		}

//Question 3
		/*
		Research tail recursivity and explain in your own words why it is better to design your recursive function this way.

		A tail recursive function computes all the processes of operation before the end of the recursive call. It is much more
		efficient than a recursive call. Tail-recursion will skip the whole process of calling the call stack until the end result,
		and will compute right away to the final result and then return it.


		Can any recursive function be designed to be tail recursive? Please develop your answer by providing clear explanation

		If we need to maintain the signature of the function, no. However, a recursive function can be designed as tail-recursive
		if we pass another input as an argument to the function as a form of control mechasism that helps with continuing the call
		so that it can arrive to the final result.
		*/


		//helper method
		int computeFactorial(int n, int a){
			if(n == 0){
				return a;
			} else{
				return computeFactorial(n-1, n*a);
			}
		}

		void factorial(){

			int number;

			cout << "Please enter a number: ";
			cin >> number;
			
			if(number < 0){
				cout << "I do not accept negative numbers" << endl;
				cin.clear();
			}
			else{ 
			int result = computeFactorial(number, 1);

			cout << "The factorial of " << number << " is " << result << endl;
			}
		}

		//helper method for enhancedFactorial
		int enhancedComputeFactorial(int n, int a){
			//stop at 6
			if(n == 6){
				return a;
			} else{
				return enhancedComputeFactorial(n-1, n*a); 
			}
		}

		void enhancedFactorial(){

			int number;
			int array[10];
			int result = 0;

			cout << "Please enter a number: ";
			cin >> number;

			if(number < 0){
				cout << "I do not accept negative numbers" << endl;
				cin.clear();
			}
			else{
				//iterate and store within the integer array the first 6 factorials
			for(int i = 1; i < 7; i++){
				array[i] = computeFactorial(i, 1);
				//cout << array[i] << "\n";
			}
			if(number == 1){
				result = array[1];
			}
			if(number == 2){
				result = array[2];
			}
			if(number == 3){
				result = array[3];
			}
			if(number == 4){
				result = array[4];
			}
			if(number == 5){
				result = array[5];
			}
			if(number == 6){
				result = array[6];
			}

			if(number > 6){
				//if bigger than 6, multiply with the 6th factorial of 720
				result = enhancedComputeFactorial(number, 1);
				result = result * array[6];
			}

			cout << "The factorial of " << number << " is " << result << endl;
			}
		}