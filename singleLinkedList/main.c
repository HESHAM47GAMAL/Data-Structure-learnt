#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"


int main()
{
    Head = (struct Node*)Null;  /*Empty List*/
    //  Head
    //  ----
    // |    | --> Null
    //  ----

    DeleteAtFirstSLL();
    DeleteAtLastSLL();
    PrintSLL();
    printf("check if number 5 exist : %s",SearchElementSLL(5) == Element_Found ? "Element found\n":"Element Not found\n");
    printf("list size = %d\n", SizeofSLL());
    InsertAtPositionSSL(2, 1);
    PrintSLL();
    DeleteAtLastSLL();
    PrintSLL();
    InsertAtFirstSSL(10);
    InsertAtPositionSSL(3, 4);
    DeleteAtLastSLL();
    PrintSLL();
    InsertAtPositionSSL(4, 1);
    InsertAtPositionSSL(5, 2);
    InsertAtPositionSSL(50, 2);
    printf("list size = %d\n", SizeofSLL());


    PrintSLL();
    printf("check if number 50 exist : %s",SearchElementSLL(50) == Element_Found ? "Element found\n":"Element Not found\n");
    DeleteAtLastSLL();
    PrintSLL();
    ReverseRecursionSSL_2(Head, (struct Node*) Null);
    PrintSLL();
    InsertAtPositionSSL(200, 1);
    PrintSLL();
    InsertAtLastAfterReverseSLL(89);
    PrintSLL();
    printf("list size = %d\n", SizeofSLL());

//     ---------------------------------------------------------------------------
//    |                                                                           |
//    |                                                                           |
//    |       Try any of those Functions , They are staible free from Buges       |
//    |                                                                           |
//    |                                                                           |
//     ---------------------------------------------------------------------------

    return 0;
}
