#include <stdio.h>

// this printing function formats the results for me
void parenChecker(int numofParen, int numofCurly, int numofprecursorStatement, int numofComments){
	printf(" All () match\n All {} match\n %d precursor statements found\n %d comments found\n", numofprecursorStatement, numofComments);
}

// this printing function is used if the parenthesis or braces are not in order
void error(int numofParen, int numofCurly, int numofprecursorStatement, int numofComments){
	printf("There is an error, the number of unpaired parenthesis is %d and the number of unpaired curly braces is %d, both should be 0\n %d precursor statements\n %d comments\n", numofParen, numofCurly, numofprecursorStatement, numofComments);
}


int main(void){

	// creating variables for program
	
    int ch;

    int numofParen = 0;
    int numofCurly = 0;
    int numofprecursorStatement = 0;
    int numofComments = 0;
    char last;

	// while statement that reads in the program one character at a time
    while ((ch=getchar()) != EOF) {  // read in the file, one char at a time

	    // numerous switch statements that determine how many parenthesis there are, curly braces, and statements
        switch(ch){
		case '#' :
			numofprecursorStatement += 1;
			break;
		case '(' :
			numofParen += 1;
			break;
		case ')' :
			numofParen -= 1;
			break;
		case '{' :
			numofCurly += 1;
			break;
		case '}' :
			numofCurly -= 1;
			break;		 
	
		case '/' : numofComments += (last == '/') ? 1: 0;
				   break;
	}
	// after checking the character, I set it equal to the last that way we dont get ahead of ourselves
	last = ch;
	

    }

	// using ternary operator for number of parenthesis and number of curlybraces, also takes in the precursor statements
	(numofParen == 0) && (numofCurly == 0)  ? parenChecker(numofParen, numofCurly, numofprecursorStatement, numofComments)

			  : error(numofParen, numofCurly, numofprecursorStatement, numofComments);
    

    return 0;
}

