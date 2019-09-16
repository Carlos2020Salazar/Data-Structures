#include <iostream>
#include <string>
#include "MovieTree.hpp"

using namespace std;

MovieTree::MovieTree(){
	root = NULL;
}
MovieTree::~MovieTree()
{
	DeleteAll(root);
	root = NULL;
}
void MovieTree::printMovieInventory()
{
	printMovieInventory(root);
}

int MovieTree::countMovieNodes()
{
	int count = 0;
	countMovieNodes(root, &count);
	return count;
}
void MovieTree::deleteMovieNode(std::string title)
{
	MovieNodeBST *newNode = searchBST(root, title);
	if(node!=NULL)
	{
		MovieNodeLL *temp = searchLL(newNode->head, title);
		if(temp != NULL)
		{
			if(newNode->head->next != NULL)
			{
				if(temp == newNode->head)
				{
					newNode->head = newNode->head->next;
					delete temp;
					return;
				}
				else
				{
					MovieNodeLL *left = newNode->head;
					while(left->next != temp)
					{
						left = left->next;
					}
					left->next = temp->next;

					delete temp;
				}
			}
			else
			{
				delete temp;
				newNode->head = NULL;
				if(newNode != root)
				{
					if (newNode->leftChild == NULL && newNode->rightChild == NULL) 
					{			//no children
						if (newNode == newNode->parent->leftChild) 
						{
							newNode->parent->leftChild = NULL;
						}
						else if (newNode == newNode->parent->rightChild) 
						{
							newNode->parent->rightChild = NULL;
						}
						delete newNode;
					}
					else if(newNode->leftChild != NULL && newNode->rightChild != NULL)
					{
						MovieNodeBST *minimum = treeMinimum(newNode->rightChild);
						if(minimum == newNode->rightChild)
						{
							if(newNode == newNode->parent->leftChild)
							{
								newNode->parent->leftChild = minimum;
								minimum->parent = newNode->parent;
								minimum->leftChild = newNode->leftChild;
								minimum->leftChild->parent = minimum;
							}
							if(newNode == newNode->parent->rightChild)
							{
								newNode->parent->rightChild = minimum;
								minimum->parent = newNode->parent;
								minimum->leftChild = newNode->leftChild;
								minimum->leftChild->parent = minimum;
							}
						}
						else
						{
							minimum->parent->leftChild = minimum->rightChild;
							minimum->rightChild->parent = minimum->parent;
							minimum->parent = newNode->parent;
							minimum->parent->leftChild = minimum;
							minimum->leftChild = newNode->leftChild;
							minimum->rightChild = newNode->rightChild;
							newNode->rightChild->parent = minimum;
							newNode->leftChild->parent = minimum;
						}
						delete newNode;
					}
					else
					{
						if(newNode == newNode->parent->leftChild)
						{
							if(newNode->leftChild != NULL)
							{
								MovieNodeBST *node = newNode->leftChild;
								newNode->parent->leftChild = node;
								node->parent = newNode->parent;
								delete newNode;
							}
							else if(newNode->rightChild != NULL)
							{
								MovieNodeBST *node = newNode->rightChild;
								newNode->parent->leftChild = node;
								node->parent = newNode->parent;
								delete newNode;
							}
						}
						else if(newNode == newNode->parent->rightChild)
						{
							if(newNode->leftChild != NULL)
							{
								MovieNodeBST *node = newNode->leftChild;
								newNode->parent->rightChild = node;
								node->parent = newNode->parent;
								delete newNode;
							}
							else if(newNode->rightChild != NULL)
							{
								MovieNodeBST *node = newNode->rightChild;
								newNode->parent->rightChild = node;
								node->parent = newNode->parent;
								delete newNode;
							}
						}
					}
				}
				else
				{
					if(newNode->leftChild == NULL && newNode->rightChild == NULL)
					{//No children
						delete newNode;
						root = NULL;
					}
					else if(newNode->leftChild == NULL || newNode->rightChild == NULL)
					{//one child
						if(newNode->rightChild != NULL)
						{
							newNode->rightChild->parent = NULL;
							root = newNode->leftChild;
						}
						else if(newNode->leftChild != NULL)
						{
							newNode->leftChild->parent = NULL;
							root = newNode->leftChild;
						}
						delete newNode;
					}
					else
					{//two children
						MovieNodeBST *minimum = treeMinimum(newNode->rightChild);
						if (minimum == newNode->rightChild) 
						{
							root = minimum;
							minimum->parent = NULL;
							newNode->leftChild->parent = minimum;
							minimum->leftChild = newNode->leftChild;
						} // end of min is right child
						else 
						{
							root = minimum;
							if (minimum->rightChild != NULL) 
							{
								minimum->rightChild->parent = minimum->parent;
							}
							minimum->parent->leftChild = minimum->rightChild;
							minimum->parent = NULL;
							minimum->leftChild = newNode->leftChild;
							if (newNode->leftChild != NULL) 
							{
								newNode->leftChild->parent = minimum;
							}
							minimum->rightChild = newNode->rightChild;
							if (newNode->rightChild != NULL) 
							{
								newNode->rightChild->parent = minimum;
							}
						} // end of if min is not the right child
						delete newNode;
					}
				}
			}
		}
		else
		{
			cout<<"Movie not found."<<endl;
		}
	}
	else
	{
		cout<<"Movie not found."<<endl;
	}
}

void MovieTree::addMovieNode(int ranking, string title, int releaseYear, int quantity) 
{
	MovieNodeLL* movie = new MovieNodeLL(ranking, title, releaseYear, quantity);
	//if tree is empty
	char letter_ = title[0];
	if (root == NULL) 
	{
		root = new MovieNodeBST(letter_);
		root->head = movie;
		return;
	}
	MovieNodeBST* curr_pos = root;
	//search for position
	bool flag = false;
	bool inserted = false;
	while (curr_pos != NULL)
	{
		if (letter_ < curr_pos->letter) 
		{
			flag = true;
			if (curr_pos->leftChild == NULL) 
			{
				break;
			}
			curr_pos = curr_pos->leftChild;
		}
		else if(letter_ == curr_pos->letter)
		{
			MovieNodeLL *currLL = curr_pos->head;
			MovieNodeLL *flag = curr_pos->head;
			while(currLL!=NULL)
			{
				if(title < currLL->title)
				{
					inserted = true;
					if(currLL==curr_pos->head)
					{
						movie->next = curr_pos->head;
						curr_pos->head = movie;
						break;
					}
					else
					{
						while(flag->next!=currLL)
						{
							flag = flag->next;
						}
						flag->next = movie;
						movie->next = currLL;
						break;
					}
				}
				currLL = currLL->next;
			}
			if(!inserted)
			{
				currLL = curr_pos->head;
				while(currLL->next!=NULL)
				{
					currLL = currLL->next;
				}
				currLL->next = movie;
			}

			return;
		}
		else
		{
			flag = false;
			if (curr_pos->rightChild == NULL) 
			{
				break;
			}
			curr_pos = curr_pos->rightChild;
		}
	} // end of search

	if (flag) 
	{
		curr_pos->leftChild = new MovieNodeBST(letter_);
		curr_pos->leftChild->head = movie;
		curr_pos->leftChild->parent = curr_pos;
	}
	else 
	{
		curr_pos->rightChild = new MovieNodeBST(letter_);
		curr_pos->rightChild->head = movie;
		curr_pos->rightChild->parent = curr_pos;
	}

	return;
}
void MovieTree::findMovie(std::string title)
{
	MovieNodeBST *node = searchBST(root, title);
	if(node != NULL)
	{
    	MovieNodeLL *newNode = searchLL(node->head, title);
    	if(newNode != NULL)
    	{
    		cout << "Movie Info:" << endl;
    		cout << "===========" << endl;
    		cout << "Ranking:" << newNode->ranking << endl;
    		cout << "Title:" << newNode->title << endl;
    		cout << "Year:" << newNode->year << endl;
    		cout << "Quantity:" << newNode->quantity << endl; 		
    	}
    	else
    	{
    		cout<<"Movie not found."<<endl;
    	}
	}
	else
	{
	    cout<<"Movie not found."<<endl;
	}
}
void MovieTree::rentMovie(std::string title)
{
	MovieNodeBST *node = searchBST(root, title);
	MovieNodeLL *newNode = searchLL(node->head, title);
	if(newNode != NULL)
	{
		if(newNode->quantity > 0)
		{
		    newNode->quantity--;
			cout << "Movie has been rented." << endl;
			cout << "Movie Info:" << endl;
			cout << "===========" << endl;
			cout << "Ranking:" << newNode->ranking << endl;
			cout << "Title:" << newNode->title << endl;
			cout << "Year:" << newNode->year << endl;
			cout << "Quantity:" << newNode->quantity << endl;
			if(newNode->quantity == 0)
			{
				deleteMovieNode(title);
			} 
		}
		else
		{
			cout<<"Movie not found."<<endl;
		}
	}
	else
	{
		cout<<"Movie not found."<<endl;
	}

}
void MovieTree::DeleteAll(MovieNodeBST * node)
{
	if(node->leftChild != NULL)
	{
		DeleteAll(node->leftChild);
	}
	if(node->rightChild!=NULL)
	{
		DeleteAll(node->rightChild);
	}
	MovieNodeLL *curr_1 = node->head;
	MovieNodeLL *curr_2 = node->head;

	while(curr_2 != NULL)
	{
		curr_1 = curr_2;
		cout <<"Deleting: "<< curr_2->title <<endl;
		delete curr_2;
		if(curr_1->next != NULL)
		{
			curr_2 = curr_1->next;
		}
		else
		{
			break;
		}
	}
}
void MovieTree::printMovieInventory(MovieNodeBST * node) 
{
	if (node->leftChild != NULL) 
	{
		printMovieInventory(node->leftChild);
	}
	MovieNodeLL *temp = node->head;
	while(temp != NULL)
	{
		cout << "Movie: " << temp->title << " " << temp->quantity << endl;
		temp = temp->next;	
	}
	if (node->rightChild != NULL) 
	{
		printMovieInventory(node->rightChild);
	}
}
void MovieTree::countMovieNodes(MovieNodeBST *node, int *c)
{
	if(root != NULL)
	{
		if (node->leftChild != NULL)
		{
			countMovieNodes(node->leftChild, c);
		}
		MovieNodeLL *pos = node->head;
		while(pos != NULL)
		{
			(*c)++;
			pos = pos->next;
		}

		if (node->rightChild != NULL) 
		{
			countMovieNodes(node->rightChild, c);
		}
	}

}
MovieNodeBST* MovieTree::searchBST(MovieNodeBST *node, std::string title)
{
	MovieNodeBST *temp = root;
	while(temp != NULL)
	{
		if(temp->letter > title[0])
		{
			temp = temp->leftChild;
		}
		else if(temp->letter < title[0])
		{
			temp = temp->rightChild;
		}
		else
		{
			return temp;
		}
	}
	return NULL;
} 
MovieNodeLL* MovieTree::searchLL(MovieNodeLL* head, std::string title)
{
	MovieNodeLL *curr = head;
	while(curr != NULL)
	{
		if(curr->title == title)
		{
			return curr;
		}
		curr = curr->next;
	}
	return NULL;
}
MovieNodeBST* MovieTree::treeMinimum(MovieNodeBST *node)
{
	while(node->leftChild!=NULL)
	{
		node = node->leftChild;
	}
	return node;
} 
