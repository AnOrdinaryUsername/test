 /*
Pseudocode
Start
	Ask user a word/phrase do cipher
	Validate the input

	String is an Characters array, so iterate through the aray to check 
	if all the characters are only letter (lower or uppercase). 
	If not, user will have to input again

	With a while loop, iterate through the char array
	and switch each letter according to our table or do an ASCII increment by 2
	Send a message on the screen with the "transposition cipher" word

	User input a word and the program returns the corresponding
	transpositioned word
End

*/

#include <iostream>
#include <string>
#include <emscripten/bind.h>

using namespace std;
using namespace emscripten;

char transpot(char c)
{
	switch (c)
	{
	case 'A': c = 'q'; break;
	case 'B': c = 'L'; break;
	case 'C': c = 'G'; break;
	case 'D': c = 'M'; break;
	case 'E': c = 'a'; break;
	case 'F': c = 'E'; break;
	case 'G': c = 'u'; break;
	case 'H': c = 'U'; break;
	case 'I': c = 'D'; break;
	case 'J': c = 'k'; break;
	case 'K': c = 'j'; break;
	case 'L': c = 'R'; break;
	case 'M': c = 'e'; break;
	case 'N': c = 'c'; break;
	case 'O': c = 'x'; break;
	case 'P': c = 'm'; break;
	case 'Q': c = 'y'; break;
	case 'R': c = 'd'; break;
	case 'S': c = 'Y'; break;
	case 'T': c = 'V'; break;
	case 'U': c = 'r'; break;
	case 'V': c = 'g'; break;
	case 'W': c = 'Q'; break;
	case 'X': c = 'H'; break;
	case 'Y': c = 'f'; break;
	case 'Z': c = 'X'; break;

	case 'a': c = 'B'; break;
	case 'b': c = 'C'; break;
	case 'c': c = 'z'; break;
	case 'd': c = 't'; break;
	case 'e': c = 'p'; break;
	case 'f': c = 'n'; break;
	case 'g': c = 'h'; break;
	case 'h': c = 'Z'; break;
	case 'i': c = 'b'; break;
	case 'j': c = 'F'; break;
	case 'k': c = 'J'; break;
	case 'l': c = 'o'; break;
	case 'm': c = 'P'; break;
	case 'n': c = 'W'; break;
	case 'o': c = 'w'; break;
	case 'p': c = 'A'; break;
	case 'q': c = 'i'; break;
	case 'r': c = 's'; break;
	case 's': c = 'I'; break;
	case 't': c = 'K'; break;
	case 'u': c = 'O'; break;
	case 'v': c = 'T'; break;
	case 'w': c = 'S'; break;
	case 'x': c = 'N'; break;
	case 'y': c = 'v'; break;
	case 'z': c = 'l'; break;
	}
	return c;
}

char undoTranspot(char c)
{
	switch (c)
	{
	case 'q': c = 'A'; break;
	case 'L': c = 'B'; break;
	case 'G': c = 'C'; break;
	case 'M': c = 'D'; break;
	case 'a': c = 'E'; break;
	case 'E': c = 'F'; break;
	case 'u': c = 'G'; break;
	case 'U': c = 'H'; break;
	case 'D': c = 'I'; break;
	case 'k': c = 'J'; break;
	case 'j': c = 'K'; break;
	case 'R': c = 'L'; break;
	case 'e': c = 'M'; break;
	case 'c': c = 'N'; break;
	case 'x': c = 'O'; break;
	case 'm': c = 'P'; break;
	case 'y': c = 'Q'; break;
	case 'd': c = 'R'; break;
	case 'Y': c = 'S'; break;
	case 'V': c = 'T'; break;
	case 'r': c = 'U'; break;
	case 'g': c = 'V'; break;
	case 'Q': c = 'W'; break;
	case 'H': c = 'X'; break;
	case 'f': c = 'Y'; break;
	case 'X': c = 'Z'; break;

	case 'B': c = 'a'; break;
	case 'C': c = 'b'; break;
	case 'z': c = 'c'; break;
	case 't': c = 'd'; break;
	case 'p': c = 'e'; break;
	case 'n': c = 'f'; break;
	case 'h': c = 'g'; break;
	case 'Z': c = 'h'; break;
	case 'b': c = 'i'; break;
	case 'F': c = 'j'; break;
	case 'J': c = 'k'; break;
	case 'o': c = 'l'; break;
	case 'P': c = 'm'; break;
	case 'W': c = 'n'; break;
	case 'w': c = 'o'; break;
	case 'A': c = 'p'; break;
	case 'i': c = 'q'; break;
	case 's': c = 'r'; break;
	case 'I': c = 's'; break;
	case 'K': c = 't'; break;
	case 'O': c = 'u'; break;
	case 'T': c = 'v'; break;
	case 'S': c = 'w'; break;
	case 'N': c = 'x'; break;
	case 'v': c = 'y'; break;
	case 'l': c = 'z'; break;
	}
	return c;
}

bool validInput(string word)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] < 65 || word[i] > 122)
		{
			cout << "Invalid Characters Used. (Please Only Use The Alphabet: A-Z, a-z)" << endl;
			return false;
		}
		else if (word[i] > 90 && word[i] < 97)
		{
			cout << "Invalid Characters Used. (Please Only Use The Alphabet: A-Z, a-z)" << endl;
			return false;
		}
	}

	return true;
}

 //ASKING CODE FUNCTION
 void askWord(string wordHolder, string newHolder, string endHolder)
 {
  	do
	{
		cout << "Please enter a word to decrypt: ";
		cin >> wordHolder;
	} while (!validInput(wordHolder));

	for (int i = 0; i<wordHolder.size(); i++)					// Loop professor used in his example
	{
		newHolder = newHolder + transpot(wordHolder[i]);
	}

	for (int i = 0; i<newHolder.size(); i++)					// Copy of loop professor used to undo encryption
	{
		endHolder = endHolder + undoTranspot(newHolder[i]);
	}
	
	cout << "Your Word" << "\t" << "Decrypted" << "\t" << "Encrypted" << endl;
	cout << wordHolder << "\t\t" << newHolder << "\t\t" << endHolder << endl;			// Displays all of the strings and what they hold
 }

//Change Word/phrase function
 void changeWord(string _continued,string _wordHolder, string _newHolder, string _endHolder)
 {
   cout << "Would you like to encrypt/decrypt other word/phrase? (Y(Yes)/N(No))";
   cin >> _continued;

   while (_continued == "Y" || _continued == "y" || _continued == "YES" || _continued == "yes")
   {
    askWord(_wordHolder, _newHolder, _endHolder);  
    cout << "Would you like to encrypt/decrypt other word/phrase? (Y(Yes)/N(No))";
    cin >> _continued;
   }
 }

int main()
{
	return 0;
}


EMSCRIPTEN_BINDINGS(my_module) {
  emscripten::function("transpot", &transpot);
  emscripten::function("undoTranspot", &undoTranspot);
  emscripten::function("validInput", &validInput);
}
