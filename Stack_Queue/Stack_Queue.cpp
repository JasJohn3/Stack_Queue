// Stack_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<vector>
using namespace std;

//create a Node for the linked list.
struct Node {
	//declare the Node Value type
	int node_value;
	//Assign memory of the Nodes Next Value type.
	Node *next;
};
//declare a function newNode(integer value).  This function creates a Node.
Node* newNode(int value);
//declare a function insert for the Node.  insert(calls a reference to the node Node*, declares a value to be inserted(value of type integer))
Node* insert(Node* start, int value);
void printValue(Node* start);
void Build_Queue();
void Build_Vector_Stack();
void Stack_Display(vector<int> display_vector_stack);
int main()
{
	int menu_option;
	cout << "This program Demonstrates the use of a Queue and a Stack data Structure." << endl << endl;
	cout << "1.) Build a Queue Data Structure" << endl;
	cout << "2.) Build a Stack Data Structure" << endl;
	cout << "3.) Build an STL Queue" << endl;
	cout << "4.) Build an STL Stack" << endl;
	cout << "5.) Exit the program" << endl;
	cout << "\nPlease Enter your menu selection: " << flush;
	cin >> menu_option;
	switch (menu_option)
	{
	case 1:
		Build_Queue();
		break;
	case 2:
		cout << "Insert Function Name Here." << endl;
		break;
	case 3:
		cout << "Insert Function Name Here." << endl;
		break;
	case 4:
		cout << "Building a Stack using Vector function in C++." << endl;
		Build_Vector_Stack();
		break;
	case 5:
		cout << "Exiting the program.";
		system("pause");
		exit(0);

	default:
		break;
	}
	cout << "Thank you for using this program.  Have a wonderful day." << endl;
	system("pause");
	return 0;
}
Node* newNode(int value)
{
	Node *node = new Node;
	node->node_value = value;
	node->next = NULL;

	return node;
}
Node* insert(Node* start,int value)
{
	if (start == NULL)
		return newNode(value);
	Node *current = start;
	while (current->next!=NULL)
	{
		current = current->next;
	}
	current->next = newNode(value);
	return current;

}
void Build_Queue()
{
	bool End_Queue = true;
	Node *start = NULL;

	do
	{
		cout << "This is an example of a linked list.  You can store ten integer values into the list." << endl << endl;
		for (int i = 0; i < 10; i++)
		{
			int user_input;
			cout << "Please Enter a value you want to store in your list: " << flush;
			cin >> user_input;
			insert(start, user_input);
		}
		cout << "These are the Values that you entered: " << endl;
		printValue(start);
		End_Queue = false;

	} while (End_Queue != false);
	main();
}
void printValue(Node* start)
{
	Node *current = start;
	while (current != NULL)
	{
		cout << current->node_value<<endl;
		current = current->next;
	}
}
void Build_Vector_Stack()
{
	vector<int>vector_stack;
	bool user_continue = true;
	int user_input;
	int vector_menu_select;
	
	cout << "Vector Stack Menu Selection" << endl;
	cout << "1.) Push(insert) an Integer on the stack." << endl;
	cout << "2.) Pop(remove) an integer from the stack." << endl;
	cout << "3.)Show all values stored in the stack." << endl;
	cin >> vector_menu_select;
	system("CLS");
	switch (vector_menu_select)
	{

	case 1:
		do
		{
			cout << "Please enter a value you would like to add to your stack: " << flush;
			cin >> user_input;
			vector_stack.push_back(user_input);
			system("pause");
			system("CLS");
			cout << "Would you like to continue adding to your stack?"<< endl;
			cout << " 1.) Yes" << endl;
			cout << " 2.) No";
			int user_answer;
			cin >> user_answer;
			if (user_answer == 1)
			{
				continue;
			}
			else if (user_answer == 2)
			{
				cout << "Returning to the Main Menu." << endl;
				system("pause");
				user_continue = false;
				Build_Vector_Stack();
			}
			else
			{
				system("CLS");
				cout << "You entered an invalid selection.  Returning to main previous Menu." << endl;
				Build_Vector_Stack();
			}

		} while (user_continue!=false);
		break;
	case 2:
		system("CLS");
		cout << "Removing the last entry in the stack." << endl;
		if (vector_stack.size() != 0)vector_stack.pop_back();
		Stack_Display(vector_stack);
		break;
	case 3:
		break;


	}

}
void Stack_Display(vector<int> display_vector_stack)
{
	cout << "Total items on STACK: " << display_vector_stack.size()<<endl;
	for (int i = 0; i < display_vector_stack.size(); i++)
	{
		cout << "Element: " << i << flush << " Value: " << display_vector_stack[i] << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
