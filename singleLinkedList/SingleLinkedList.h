#ifndef SINGLELINKEDLIST_H_INCLUDED
#define SINGLELINKEDLIST_H_INCLUDED

#define Null  (void *) 0

/**
 * @brief Represents data type that tell me result of function operation is successful do wanted things or No .
 */
typedef enum { Failed_operation = 0 , Success_operation = 1 }OperationType;

/**
 * @brief Represents data type that tell me result from function search for value .
 */
typedef enum { Element_Not_Found = 0 , Element_Found = 1 }SearchResultType;

// Representation for Node

//          Node
//    ------------------------------------------
//   |            |                             |
//   |   value    |    link next Node           |
//   |            |                             |
//    ------------------------------------------
///-------
//        |
//        |
//        \/
/*Apply concept of "struct Padding" */
/*In this struct to minimize size of struct I put pointer first then variable as size of pointer in machine 8Bytes and int is 4Bytes*/
struct Node
{
    struct Node* Next;
    int Data;
};

//        |
//        |
//        |   Look -> this happen as can use Head in any place I include and can use it in  "SingleLinkedList.c"
//        |
//        \/

extern struct Node* Head;  // Declare head as an external variable


/**
 * Brief description :this function insert element at first of single linked list.
 *
 * @param param1 :value you want to put for this element.
 * @return Void.
 */
void InsertAtFirstSSL(int);

/**
 * Brief description :this function insert element at last of single linked list.
 *
 * @param param1 :value you want to put for this element.
 * @return Void.
 */
void InsertAtLastSSL(int);

/**
 * Brief description :this function insert element at position you want in single linked list.
 * More detailed description , if I have list of 4 element so I can put new element in [1 : 5] but can't put in 6
 *
 * @param param1 :position I want to put new element as valid position.
 * @param param2 :value I want to put in this position.
 * @return OperationType : which is 1: success_operation if position passing to function is valid , 2: failed_operation if position is not valid and this mean that no new element placed.
 */
OperationType InsertAtPositionSSL(int, int);

/**
 * Brief description :this function insert element at last of single linked list After reverse all element.
 *
 * @param param1 :value you want to put for this element.
 * @return Void.
 */
void InsertAtLastAfterReverseSLL(int);

/**
 * Brief description :this function delete first element in linked list.
 *
 * @return Void.
 */
void DeleteAtFirstSLL(void);

/**
 * Brief description :this function delete last element in linked list.
 *
 * @return Void.
 */
void DeleteAtLastSLL(void);

/**
 * Brief description :this function delete element using position in linked list.
 *
 * @param param1 :position I want to delete ->> note if this position is already element will delete it and if there isn't element in this position do Nothing .
 * @return Void.
 */
void DeleteAtPositionSLL(int);

/*
//  Before function

		Head					1980						2000		  		2020
	 ------------		 -----------------       -----------------       -----------------
	|            |		|	 	|	      |     |	 	|	      |     |	 	|	      |
	|   1980     |	--> |	20 	|	2000  | -->	|	50 	|	2020  | -->	|	50 	|	Null  |
	|            |		|	 	|	      |		|	 	|	      |   	|	 	|	      |
	 ------------		 -----------------		 -----------------    	 -----------------

//  After function
				1980						2000		  		2020						Head
			 -----------------       -----------------       -----------------  		 ------------
			|	 	|	      |     |	 	|	      |     |	 	|	      | 		|            |
			|	20 	|	Null  | <--	|	50 	|	1980  | <--	|	50 	|	2000  | <---	|   2020     |
			|	 	|	      |		|	 	|	      |   	|	 	|	      | 		|            |
			 -----------------		 -----------------    	 -----------------  		 ------------
			  */
/**
 * Brief description :this function reverse list by change order of addresses that point to each other .
 * this Done using iterative method
 *
 * @return Void.
 */
void ReverseItertionSLL(void);

/**
 * Brief description :this function reverse list by change order of addresses that point to each other .
 * this Done using Recursion method
 *
 * @param param1 :start node of list (I mean Head node)
 * @return Void.
 */
void ReverseRecursionSSL_1(struct Node*);

/**
 * Brief description :this function reverse list by change order of addresses that point to each other .
 * this Done using Recursion method
 *
 * @param param1 :start node of list (I mean Head node)
 * @param param2 :address I want to make first node before reverse to point after reverse (Mostly Null )
 * @return Void.
 */
void ReverseRecursionSSL_2(struct Node*, struct Node*);

/**
 * Brief description :this function display element of list .
 * this Done using iterative method
 *
 * @return Void.
 */
void PrintSLL(void);

/**
 * Brief description :this function display element of list reversed.
  * this Done using Recursion method
 *
 * @return Void.
 */
void PrintReversalSLL(struct Node*);

/**
 * Brief description :this function give size of element in list .
 * this Done using Recursion method
 *
 * @return number of element in list.
 */
int SizeofSLL(void);

/**
 * Brief description :this function search about value given for specefic element .
 *
 * @return SearchResultType which is 1.Found element : this mean that there are element hold this value 2.not found element  : this mean no element hold this value.
 */
SearchResultType SearchElementSLL(int);

/**
 * Brief description :this function update value for element with current certain value.
 *
 * @param param1 : value for element that if found I will change it with new value.
 * @param param2 : new value that will put for this element.
 * @return OperationType : which is 1: success_operation if position passing to function is valid , 2: failed_operation if position is not valid and this mean that no new element placed.
 */
OperationType UpdateByValueSLL(int , int);

/**
 * Brief description :this function update value for element with certain position.
 *
 * @param param1 : position for element that will change it's value with new one.
 * @param param2 : new value that will put for this element.
 * @return OperationType : which is 1: success_operation if position passing to function is valid , 2: failed_operation if position is not valid and this mean that no new element placed.
 */
OperationType UpdateByPositionSLL(int , int);

/**
 * Brief description :this function like insert at first but here .
 * I send address of Head node as first dereference happen ->>give me first node if exist
 *
 * @param param1 : address of Head Node.
 * @param param2 : value for node that will created.
 * @return void.
 */
void insert_SSL(struct Node**, int);



#endif // SINGLELINKEDLIST_H_INCLUDED
