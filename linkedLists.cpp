#include <iostream>

struct nodeType
{
    int info;
    nodeType *link;
};

//Function prototypes
void createList(nodeType *&first, nodeType *&last);
bool isEmpty(nodeType *first);
void printList(nodeType *first);
void destroyList(nodeType *&first, nodeType *&last);
void insertFirst(nodeType *&first, nodeType *&last, int newItem);
void insertLast(nodeType *&first, nodeType *&last, int newItem);
void deleteNode(nodeType *&first, nodeType *&last, int deleteItem);
void insertNode(nodeType *&first, nodeType *&last, int newItem);
void mergeList(nodeType *&firstHead, nodeType *&secondHead, nodeType *&mergedHead, nodeType *&mergedTail);

int main()
{
    //Pointers for the first list
    nodeType *firstHead = NULL;
    nodeType *firstTail = NULL;

    //Pointers for the second list
    nodeType *secondHead = NULL;
    nodeType *secondTail = NULL;

    //Pointers for the merged list
    nodeType *mergedHead = NULL;
    nodeType *mergedTail = NULL;

    //Creating the lists
    createList(firstHead, firstTail);
    createList(secondHead, secondTail);

    std::cout << "\n";
    //Printing the lists
    std::cout << "First List: "; printList(firstHead);
    std::cout << "Second List: "; printList(secondHead);
    std::cout << "Merged List: "; printList(mergedHead);

    std::cout << "\n";
    std::cout << "----------------------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "Merging the lists..." << std::endl;
    std::cout << "----------------------------------------------------------------------------------------------------------" << std::endl;
    //Merging the lists
    mergeList(firstHead, secondHead, mergedHead, mergedTail);

    //Destroying the lists
    destroyList(firstHead, firstTail);
    destroyList(secondHead, secondTail);

    std::cout << "\n";
    //Printing the lists
    std::cout << "First List: "; printList(firstHead);
    std::cout << "Second List: "; printList(secondHead);
    std::cout << "Merged List: "; printList(mergedHead);

    return 0;
}

void createList(nodeType *&first, nodeType *&last)
{
    bool done = false;
    int newItem;

    while(!done)
    {
        std::cout << "Please enter a number to add to the list, or -999 to end the list." << std::endl;
        std::cin >> newItem;

        if(newItem != -999)
        {
            insertNode(first, last, newItem);
        }
        else
        {
            std::cout << "Finishing the list" << std::endl;
            done = true;
        }
    }

    done = false; //This must be reset to recall the function in main
} //End createList

bool isEmpty(nodeType *first)
{
    return(first == NULL);
} //End isEmpty

void printList(nodeType *first)
{
    if(first == NULL)
        std::cout << "The list is empty!";

    nodeType *current; //Pointer to traverse the list
    current = first; //Set current to point to the first node

    while(current != NULL) //While there are nodes in the list
    {
        std::cout << current->info << " ";
        current = current->link;
    }

    std::cout << "\n";
} //End printList

void destroyList(nodeType *&first, nodeType *&last)
{
    nodeType *temp = new nodeType; //Pointer to deallocate the memory occupied by the node

    while(first != NULL) //While there are nodes in the list
    {
        temp = first; //Set temp to the current node
        first = first->link; //Move first to the next node
        delete temp; //Deallocate the memory occupied by temp
    }

    last = NULL; //Initialize last to NULL

} //End destroyList

void insertFirst(nodeType *&first, nodeType *&last, int newItem)
{
    insertNode(first, last, newItem);
} //End insertFirst

void insertLast(nodeType *&first, nodeType *&last, int newItem)
{
    insertNode(first, last, newItem);
} //End insertLast

void deleteNode(nodeType *&first, nodeType *&last, int deleteItem)
{
    nodeType *current; //Pointer to traverse the list
    nodeType *trailCurrent; //Pointer just before current
    bool found;

    if(first == NULL)
        std::cout << "Cannot delete from an empty list." << std::endl;
    else
    {
        current = first;
        found = false;

        while(current != NULL && !found) //Search the list
            if(current->info >= deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if(current == NULL)
            std::cout << "The item to be deleted is not in the list." << std::endl;
        else
            if(current->info == deleteItem) //The item to be deleted is in the list
            {
                if(first == current)
                {
                    first = first->link;

                    if(first == NULL)
                        last = NULL;

                    delete current;
                }
                else
                {
                    trailCurrent->link = current->link;

                    if(current == last)
                        last = trailCurrent;

                    delete current;
                }
            }
            else
                std::cout << "The item to be deleted is not in the list." << std::endl;
    }
} //End deleteNode

void insertNode(nodeType *&first, nodeType *&last, int newItem)
{
    nodeType *current; //Pointer to traverse the list
    nodeType *trailCurrent; //Pointer just before current
    nodeType *newNode; //Pointer to create a node
    bool found;

    newNode = new nodeType; //Create the node
    newNode->info = newItem; //Store newItem in the node
    newNode->link = NULL; //Set the link of the node to NULL

    if(first == NULL)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        current = first;
        found = false;

        while(current != NULL && !found)
            if(current->info >= newItem)
                found = true;
            else
            {
                trailCurrent = current;
                current = current->link;
            }
        if(current == first)
        {
            newNode->link = first;
            first = newNode;
        }
        else
        {
            trailCurrent->link = newNode;
            newNode->link = current;

            if(current == NULL)
                last = newNode;
        }
    } //End else
} //End insertNode

void mergeList(nodeType *&firstHead, nodeType *&secondHead, nodeType *&mergedHead, nodeType *&mergedTail)
{
    nodeType *firstCurrent; //Pointer to traverse the first list
    nodeType *secondCurrent; //Pointer to traverse the second list

    firstCurrent = firstHead; //Assign the traversal pointer to the first list
    secondCurrent = secondHead; //Assign the traversal pointer to the second list

    if(firstHead == NULL) //Handles the first list being empty
    {
        insertFirst(mergedHead, mergedTail, secondCurrent->info);
        secondCurrent = secondCurrent->link;

        while(secondCurrent != NULL)
        {
            insertNode(mergedHead, mergedTail, secondCurrent->info);
            secondCurrent = secondCurrent->link;
        }
    }
    if(secondHead == NULL) //Handles the second list being empty
    {
        insertFirst(mergedHead, mergedTail, firstCurrent->info);
        firstCurrent = firstCurrent->link;

        while(firstCurrent != NULL)
        {
            insertNode(mergedHead, mergedTail, firstCurrent->info);
            firstCurrent = firstCurrent->link;
        }
    }
    if(firstCurrent->info <= secondCurrent->info)
    {
        insertNode(mergedHead, mergedTail, firstCurrent->info);
        firstCurrent = firstCurrent->link;
    }
    else
    {
        insertNode(mergedHead, mergedTail, secondCurrent->info);
        secondCurrent = secondCurrent->link;
    }
    while(firstCurrent != NULL && secondCurrent != NULL)
    {
        if(firstCurrent->info <= secondCurrent->info)
        {
            insertNode(mergedHead, mergedTail, firstCurrent->info);
            firstCurrent = firstCurrent->link;
        }
        else
        {
            insertNode(mergedHead, mergedTail, secondCurrent->info);
            secondCurrent = secondCurrent->link;
        }
    }
    if(firstCurrent == NULL)
    {
        mergedTail->link = secondCurrent;
    }
    else
    {
        mergedTail->link = firstCurrent;
    }
} //End mergeList