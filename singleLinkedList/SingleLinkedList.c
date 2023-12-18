#include <stdio.h>
#include "SingleLinkedList.h"

struct Node* Head = NULL;  // Define head as a global variable

void InsertAtFirstSSL(int value)
{
    /*Avoid lose reference Node*/
    struct Node* New_Node = (struct Node*)malloc(sizeof(struct Node)); /*memory allocate for new node*/
    New_Node->Next = Head; /*make next of new node have address of head*/
    Head = New_Node; /*As insert at first make this node first node access*/
    New_Node->Data = value; /*give value of new node*/
}

void InsertAtLastSSL(int value)
{
    if (Head == Null)
    {
        InsertAtFirstSSL(value);
    }
    else
    {
        struct Node* temp = Head;
        struct Node* New_Node = (struct Node*)malloc(sizeof(struct Node));
        New_Node->Data = value;
        New_Node->Next = (struct Node*)Null;

        while (temp->Next != Null)
        {
            temp = temp->Next;
        }
        temp->Next = New_Node;
    }

}

OperationType InsertAtPositionSSL(int value, int position)
{
    OperationType state = Failed_operation;
    if (position == 1)
        InsertAtFirstSSL(value), state = Success_operation;
    else
    {
        struct Node* temp = Head;
        int NodePos = 1;
        while (temp != Null)
        {
            NodePos++;
            if (NodePos == position)
            {
                state = Failed_operation;
                struct Node* New_node = (struct Node*)malloc(sizeof(struct Node));
                New_node->Data = value;
                New_node->Next = temp->Next;
                temp->Next = New_node;
                break;
            }
            temp = temp->Next;
        }
    }
    return state;
}

void InsertAtLastAfterReverseSLL(int value)
{
    struct Node* New_Node = (struct Node*)malloc(sizeof(struct Node));
    New_Node->Data = value;
    New_Node->Next = (struct Node*)Null;
    ReverseRecursionSSL_2(Head, New_Node);

}


void PrintSLL(void)
{
    struct Node* temp = Head; /*Take copy of head to move in  list without miss address of first element*/
    printf("List : [");
    while (temp != Null)
    {
        printf("%d", temp->Data);
        if (temp->Next != Null)
            printf(",");
        temp = temp->Next;
    }
    printf("]\n");
}



void DeleteAtPositionSLL(int pos)
{
    if (pos == 1)
    {
        DeleteAtFirstSLL();
    }
    else
    {
        int NodePos = 1;
        struct Node* temp = Head;
        while (temp != Null && NodePos < pos)
        {
            NodePos++;
            if (NodePos == pos)
            {
                struct Node* NodeD = temp->Next;
                if (NodeD != Null) /*If Node I want to delete Isn't Null I will go ahead in process of delete ->> to avoid any error or run time error*/
                {
                    temp->Next = NodeD->Next;  //temp ->Next  = temp->Next->Next ;
                    free(NodeD);
                }
                break;
            }
            temp = temp->Next;
        }
    }
}

void ReverseItertionSLL(void)
{
    struct Node* prev, * current, * next;
    prev = (struct Node*)Null;
    current = Head;
    while (current != Null)
    {
        next = current->Next; //take copy of next  to avoid lose it
        current->Next = prev;
        prev = current;
        current = next;
    }
    /*after end this loop current  will point to Null so previous already store last element in linked list that will be first element*/
    Head = prev;
}


void PrintReversalSLL(struct Node* Current)
{
    static int counter = 0;
    counter++;
    if (Current == Null) //Exit condition as I reach reach last element in Linked list in previous call for this function
    {
        printf("Reversed List : [");
        if (counter == 1) printf("]\n"); // solve bug of not close this -> "Reversed List : ["  by  "]\n"  when Head of linked list point to Null -->can comment this line and run when list is empty
        return;
    }
    PrintReversalSLL(Current->Next); //Recursive Call
    printf("%d", Current->Data); //Print Value
    counter--;
    if (counter > 1)
        printf(",");
    if (counter == 1)
        printf("]\n");

}

void ReverseRecursionSSL_1(struct Node* Current)
{
    if (Current == Null) return; // solve bug of run time error when linked list is free
    if (Current->Next == Null) //Exist condition
    {
        Head = Current;
        return;
    }
    ReverseRecursionSSL_1(Current->Next); //Recursion Call
    //    struct Node * NextOfCurrent = Current ->Next ;
    //    NextOfCurrent ->Next = Current ;
    //            |
    //            | look
    //            \/
        /*this line is replacing for previous two lines*/
    Current->Next->Next = Current;
    Current->Next = (struct Node *)Null;

}

void ReverseRecursionSSL_2(struct Node* Current, struct Node* Prev)
{
    if (Current == Null) //Exist comndition
    {
        Head = Prev;
        return;
    }
    ReverseRecursionSSL_2(Current->Next, Current);
    Current->Next = Prev;
}



int SizeofSLL(void)
{
    int counter = 0;
    struct Node* temp = Head;
    while (temp != Null)
    {
        counter++;
        temp = temp->Next;
    }
    return counter;
}

void DeleteAtFirstSLL(void)
{
    if (Head != Null) //to avoid run time error that will happen if Linked list is empty -->(Due to) try to make get next (use arrow ->) will Null (0 address) and make free to null
    {
        struct Node* NodeD = Head;
        Head = NodeD->Next;  //Head = Head->Next ;
        free(NodeD);
    }
}

void DeleteAtLastSLL(void)
{
    //        |
    //        | If I have empty List
    //        \/
    if (Head == Null) return; //

    //        |
    //        | If I have only one element in List
    //        \/
    if (Head->Next == Null)
    {
        free(Head);
        Head = (struct Node*) Null;
        return;
    }

    struct Node* temp = Head;
    while (temp->Next->Next != Null)
    {
        temp = temp->Next;
    }
    free(temp->Next);
    temp->Next = (struct Node*) Null;

}

SearchResultType SearchElementSLL(int search_value)
{
    struct Node * temp = Head ;
    while(temp != Null)
    {
        if(temp->Data == search_value)
            return Element_Found ;
        temp = temp->Next ;
    }
    return Element_Not_Found ;
}

OperationType UpdateByValueSLL(int old_value, int new_value)
{
    OperationType state = Failed_operation ;
    struct Node * temp  = Head ;
    if(temp != Null)
    {
        if(temp ->Data == old_value)
        {
            temp->Data = new_value ;
            return Success_operation ;
        }
        temp = temp->Next;
    }
    return state;
}

OperationType UpdateByPositionSLL(int pos , int new_value)
{
    int NodePos = 1;
    OperationType state = Failed_operation ;
    struct Node * temp = Head ;
    while(temp != Null)
    {
        if(NodePos == pos)
        {
            temp->Data = new_value ;
            return Success_operation ;
        }
        NodePos++;
        temp =temp ->Next;
    }
    return state ;
}

/*In this function although here not make two dereference for "point2Head" and only make one I should make pointer to pointer to struct*/
void insert_SSL(struct Node** point2Head, int value)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->Data = value;
    temp->Next = *point2Head;
    *point2Head = temp;

}
