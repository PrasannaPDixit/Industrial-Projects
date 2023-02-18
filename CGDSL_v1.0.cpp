
//////////////////////////////////////////////////////////////////////////////////////////////////////
// Steps to follow while programming
//////////////////////////////////////////////////////////////////////////////////////////////////////

// Step1    Understand the problem statement
// Step2    Write an algorithm
// Step3    Decide the programming language 
// Step4    Write the program
// step5    Test the program

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//Project Name : Customised Generic Data Structure Library
//Author :       Prasanna Prabhakarrao Dixit
//Date :         11/02/2023
// 
///////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Algorithm
//////////////////////////////////////////////////////////////////////////////////////////////////////

/*
    START
        Define two different structures, one for singly & other for doubly linked list
        Design separate classes for each type of linked list
        Initialize the characteristics of class and start defining the methods
        Write a template to make the code generic
    End
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;
#pragma pack(1)

template <class T>
struct Node_Singly
{
    T data;
    struct Node_Singly * next;
};

template<class T>
struct Node_Doubly
{
    T data;
    struct Node_Doubly * next;
    struct Node_Doubly * prev;
};

template <class T>
struct Node_Binary
{
    T data;
    struct Node_Binary * Lchild;
    struct Node_Binary * Rchild;
};

//******************************Singly Linear linked list starts from here******************************

template <class T>
class Singly_LinkedList_Linear
{
    public:
        struct Node_Singly<T>* First;

        Singly_LinkedList_Linear();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPositon(T iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);
        void Display();
        int Count();
        int Search_First_Occurance(T iNo);
        int Search_Last_Occurance(T iNo);
        T Addition();
        T Largest_Element();
        T Smallest_Element();
        T Second_Max_Element();
        void ReverseTheLL();
};

template <class T>
Singly_LinkedList_Linear <T>:: Singly_LinkedList_Linear()
{
    First = NULL;
}

template <class T>
void Singly_LinkedList_Linear <T>:: InsertFirst(T iNo)
{
    struct Node_Singly<T>* newn = new struct Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
}

template <class T>
void Singly_LinkedList_Linear <T>:: InsertLast(T iNo)
{
    struct Node_Singly<T>* newn = new struct Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;

    struct Node_Singly<T>* temp = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

template <class T>
void Singly_LinkedList_Linear <T>:: InsertAtPositon(T iNo, int iPos)
{
    struct Node_Singly<T>* newn = new struct Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;

    struct Node_Singly<T>* temp = NULL;

    int iCount = Count();

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = First;
        int iCnt = 0;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void Singly_LinkedList_Linear <T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct Node_Singly<T>* temp = First;
        First = First->next;
        delete temp;
        temp = NULL;
    }
}

template <class T>
void Singly_LinkedList_Linear <T>:: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct Node_Singly<T>* temp = First;
        
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

template <class T>
void Singly_LinkedList_Linear <T>:: DeleteAtPosition(int iPos)
{
    int iCount = Count();
    if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct Node_Singly<T>* temp = First;
        struct Node_Singly<T>* temp1 = NULL;
        int iCnt = 0;
        
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp1 = temp->next->next;
        delete temp->next;
        temp->next = temp1;
    }
}

template <class T>
void Singly_LinkedList_Linear <T>:: Display()
{
    struct Node_Singly<T>* temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int Singly_LinkedList_Linear <T>:: Count()
{
    struct Node_Singly<T>* temp = First;
    int iCount = 0;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }
    return iCount;
}

template <class T>
int Singly_LinkedList_Linear <T> :: Search_First_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if(temp->data == iNo)
        {
            Ret = Counter;
            break;
        }
        Counter++;
        temp = temp->next;
    }
    if(temp == NULL) return -1;

    return Ret;
}

template <class T>
int Singly_LinkedList_Linear <T> :: Search_Last_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if((temp->data) == iNo)
        {
            Ret = Counter;
        }
        Counter++;
        temp = temp->next;
    }
    if(Ret == 0) return -1;

    return Ret;
}

template <class T>
T Singly_LinkedList_Linear <T> :: Addition()
{
    struct Node_Singly<T>* temp = First;
    T Sum = temp->data;
    temp = temp->next;

    while(temp!= NULL)
    {
        Sum = Sum + (temp->data);
        temp = temp->next;
    }
    return Sum;
}

template <class T>
T Singly_LinkedList_Linear <T> :: Largest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) > Large)
        {
            Large = temp->data;
        }
        temp = temp->next;
    }
    return Large;
}

template <class T>
T Singly_LinkedList_Linear <T> :: Smallest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Small = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) < Small)
        {
            Small = temp->data;
        }
        temp = temp->next;
    }
    return Small;
}

template <class T>
T Singly_LinkedList_Linear <T> :: Second_Max_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;
    T Second_Large;
    temp = temp->next;

    while(temp!= NULL)
    {
        if((temp->data) > Large )
        {
            Second_Large = Large;
            Large = temp->data;
        }
        else if((temp->data) > Second_Large)
        {
            Second_Large = temp->data;
        }
        temp = temp->next;
    }
    return Second_Large;
}

template <class T>
void Singly_LinkedList_Linear <T> :: ReverseTheLL()
{
    struct Node_Singly<T>* Curr = First;
    struct Node_Singly<T>* Next = NULL;
    struct Node_Singly<T>* Prev = NULL;

    while(Curr != NULL)
    {
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    First = Prev;

}   
    
//******************************Singly Linear linked list ends here******************************
/////////////////////////////////////////////////////////////////////////////////////////////////
//******************************Singly Circular linked list ends here******************************

template <class T>
class Singly_LinkedList_Circular
{
    public:
        struct Node_Singly<T>* First;

        Singly_LinkedList_Circular();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPositon(T iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);
        void Display();
        void Display_Circular();
        int Count();
        int Search_First_Occurance(T iNo);
        int Search_Last_Occurance(T iNo);
        T Addition();
        T Largest_Element();
        T Smallest_Element();
        T Second_Max_Element();
};

template <class T>
Singly_LinkedList_Circular <T>:: Singly_LinkedList_Circular()
{
    First = NULL;
}

template <class T>
void Singly_LinkedList_Circular <T>:: InsertFirst(T iNo)
{
    struct Node_Singly<T>* newn = new struct Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;
    struct Node_Singly<T>* temp = First;

    if(First == NULL)
    {
        First = newn;
        newn->next = First;
    }
    else
    {
        newn->next = First;

        while(temp->next != First)
        {
            temp = temp->next;
        }
        temp->next = newn;
        First = newn;
    }

}

template <class T>
void Singly_LinkedList_Circular <T>:: InsertLast(T iNo)
{
    struct Node_Singly<T>* newn = new struct Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;

    struct Node_Singly<T>* temp = NULL;

    if(First == NULL)
    {
        First = newn;
        newn ->next = First;
    }
    else
    {
        temp = First;

        while(temp->next != First)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->next = First;
    }
}

template <class T>
void Singly_LinkedList_Circular <T>:: InsertAtPositon(T iNo, int iPos)
{
    struct Node_Singly<T>* newn = new struct Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;

    struct Node_Singly<T>* temp = NULL;

    int iCount = Count();

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = First;
        int iCnt = 0;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

template <class T>
void Singly_LinkedList_Circular <T>:: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct Node_Singly<T>* temp = First;

        while(temp->next != First)
        {
            temp = temp->next;
        }
        First = First->next;
        delete temp->next;
        temp->next = First;
    }
}

template <class T>
void Singly_LinkedList_Circular <T>:: DeleteLast()
{
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct Node_Singly<T>* temp = First;
        
        while(temp->next->next != First)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = First;
    }
}

template <class T>
void Singly_LinkedList_Circular <T>:: DeleteAtPosition(int iPos)
{
    int iCount = Count();
    if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct Node_Singly<T>* temp = First;
        struct Node_Singly<T>* temp1 = NULL;
        int iCnt = 0;
        
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp1 = temp->next->next;
        delete temp->next;
        temp->next = temp1;
    }
}

template <class T>
void Singly_LinkedList_Circular <T>:: Display()
{
    struct Node_Singly<T>* temp = First;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    while(temp!= First);
    cout<<"\n";
}

template <class T>
void Singly_LinkedList_Circular <T>:: Display_Circular()
{
    struct Node_Singly<T>* temp = First;
    int iCount = 0;

    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
        iCount++;
    }
    while(iCount <= 10);
    cout<<"\n";
}

template <class T>
int Singly_LinkedList_Circular <T>:: Count()
{
    struct Node_Singly<T>* temp = First;
    int iCount = 0;

    do
    {
        iCount++;
        temp = temp->next;
    }while(temp != First);
    return iCount;
}

template <class T>
int Singly_LinkedList_Circular <T> :: Search_First_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    do
    {
        if(temp->data == iNo)
        {
            Ret = Counter;
            break;
        }
        Counter++;
        temp = temp->next;
    }while(temp!= First);
    if(temp == NULL) return -1;

    return Ret;
}

template <class T>
int Singly_LinkedList_Circular <T> :: Search_Last_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    do
    {
        if((temp->data) == iNo)
        {
            Ret = Counter;
        }
        Counter++;
        temp = temp->next;
    }while(temp!= First);
    if(Ret == 0) return -1;

    return Ret;
}

template <class T>
T Singly_LinkedList_Circular <T> :: Addition()
{
    struct Node_Singly<T>* temp = First;
    T Sum = temp->data;
    temp = temp->next;

    while(temp!= First)
    {
        Sum = Sum + (temp->data);
        temp = temp->next;
    }
    return Sum;
}

template <class T>
T Singly_LinkedList_Circular <T> :: Largest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;

    do
    {
        if((temp->data) > Large)
        {
            Large = temp->data;
        }
        temp = temp->next;
    }while(temp!= First);
    return Large;
}

template <class T>
T Singly_LinkedList_Circular <T> :: Smallest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Small = temp->data;

    do
    {
        if((temp->data) < Small)
        {
            Small = temp->data;
        }
        temp = temp->next;
    }while(temp!= First);
    return Small;
}

template <class T>
T Singly_LinkedList_Circular <T> :: Second_Max_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;
    T Second_Large;
    temp = temp->next;

    do
    {
        if((temp->data) > Large )
        {
            Second_Large = Large;
            Large = temp->data;
        }
        else if((temp->data) > Second_Large)
        {
            Second_Large = temp->data;
        }
        temp = temp->next;
    }while(temp!= First);

    return Second_Large;
}


//******************************Singly Circular linked list ends here******************************
///////////////////////////////////////////////////////////////////////////////////////////////////
//******************************Doubly Linear linked list Starts here******************************

template<class T>
class Doubly_LinkedList_Linear
{
    public:
        struct Node_Doubly <T>* First;
        struct Node_Doubly<T>* Last;

        Doubly_LinkedList_Linear();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPositon(T iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);
        void Display();
        void Display_Reverse();
        int Count();
        int Search_First_Occurance(T iNo);
        int Search_Last_Occurance(T iNo);
        T Addition();
        T Largest_Element();
        T Smallest_Element();
        T Second_Max_Element();
};

template<class T>
Doubly_LinkedList_Linear <T>:: Doubly_LinkedList_Linear()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void Doubly_LinkedList_Linear <T>:: InsertFirst(T iNo)
{
    struct Node_Doubly<T>* newn = new struct Node_Doubly<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
}

template<class T>
void Doubly_LinkedList_Linear <T>:: InsertLast(T iNo)
{
    struct Node_Doubly<T>* newn = new struct Node_Doubly<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        Last = newn;
    }
}

template<class T>
void Doubly_LinkedList_Linear <T>:: InsertAtPositon(T iNo, int iPos)
{
    struct Node_Doubly<T>* newn = new struct Node_Doubly<T>;
    struct Node_Doubly<T>* temp = NULL;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    int iCount = Count();

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = First;

        for(int iCnt = 1; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }
       
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

template<class T>
void Doubly_LinkedList_Linear <T>:: DeleteFirst()
{
    struct Node_Doubly<T>* temp = NULL;
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        First->prev =NULL;
        delete temp;
        temp = NULL;
    }
}

template<class T>
void Doubly_LinkedList_Linear <T>:: DeleteLast()
{
    struct Node_Doubly<T>* temp = NULL;
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        temp = Last;
        Last = Last->prev;
        Last->next = NULL;
        delete temp;
        temp = NULL;
    }
}

template<class T>
void Doubly_LinkedList_Linear <T>:: DeleteAtPosition(int iPos)
{
    struct Node_Doubly<T>* temp = NULL;
    struct Node_Doubly<T>* temp1 = NULL;

    int iCount = Count();
    if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        delete temp1;
        temp1 = NULL;
    }
}

template<class T>
void Doubly_LinkedList_Linear <T>:: Display()
{
    struct Node_Doubly<T>* temp = First;

    cout<<"NULL\t";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
void Doubly_LinkedList_Linear <T>:: Display_Reverse()
{
    struct Node_Doubly<T>* temp = Last;

    cout<<"NULL\t";
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->prev;
    }
    cout<<"NULL"<<"\n";
}

template<class T>
int Doubly_LinkedList_Linear <T>:: Count()
{
    struct Node_Doubly<T>* temp = First;
    int iCount = 0;

    while(temp != NULL)
    {
        iCount++;
        temp = temp->next;
    }
    return iCount;
}

template <class T>
int Doubly_LinkedList_Linear <T> :: Search_First_Occurance(T iNo)
{
    struct Node_Doubly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if(temp->data == iNo)
        {
            Ret = Counter;
            break;
        }
        Counter++;
        temp = temp->next;
    }
    if(temp == NULL) return -1;

    return Ret;
}

template <class T>
int Doubly_LinkedList_Linear <T> :: Search_Last_Occurance(T iNo)
{
    struct Node_Doubly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if((temp->data) == iNo)
        {
            Ret = Counter;
        }
        Counter++;
        temp = temp->next;
    }
    if(Ret == 0) return -1;

    return Ret;
}

template <class T>
T Doubly_LinkedList_Linear <T> :: Addition()
{
    struct Node_Doubly<T>* temp = First;
    T Sum = temp->data;
    temp = temp->next;

    while(temp!= NULL)
    {
        Sum = Sum + (temp->data);
        temp = temp->next;
    }
    return Sum;
}

template <class T>
T Doubly_LinkedList_Linear <T> :: Largest_Element()
{
    struct Node_Doubly<T>* temp = First;
    T Large = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) > Large)
        {
            Large = temp->data;
        }
        temp = temp->next;
    }
    return Large;
}

template <class T>
T Doubly_LinkedList_Linear <T> :: Smallest_Element()
{
    struct Node_Doubly<T>* temp = First;
    T Small = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) < Small)
        {
            Small = temp->data;
        }
        temp = temp->next;
    }
    return Small;
}

template <class T>
T Doubly_LinkedList_Linear <T> :: Second_Max_Element()
{
    struct Node_Doubly<T>* temp = First;
    T Large = temp->data;
    T Second_Large;
    temp = temp->next;

    while(temp!= NULL)
    {
        if((temp->data) > Large )
        {
            Second_Large = Large;
            Large = temp->data;
        }
        else if((temp->data) > Second_Large)
        {
            Second_Large = temp->data;
        }
        temp = temp->next;
    }
    return Second_Large;
}


//******************************Double Linear linked list ends here******************************
/////////////////////////////////////////////////////////////////////////////////////////////////
//******************************Double Circular linked list Starts here******************************

template<class T>
class Doubly_LinkedList_Circular
{
    public:
        struct Node_Doubly<T>* First;
        struct Node_Doubly<T>* Last;

        Doubly_LinkedList_Circular();
        void InsertFirst(T iNo);
        void InsertLast(T iNo);
        void InsertAtPositon(T iNo, int iPos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int iPos);
        void Display();
        void Display_Reverse();
        void Display_Circular();
        int Count();
        int Search_First_Occurance(T iNo);
        int Search_Last_Occurance(T iNo);
        T Addition();
        T Largest_Element();
        T Smallest_Element();
        T Second_Max_Element();
};

template<class T>
Doubly_LinkedList_Circular <T>:: Doubly_LinkedList_Circular()
{
    First = NULL;
    Last = NULL;
}

template<class T>
void Doubly_LinkedList_Circular <T>:: InsertFirst(T iNo)
{
    struct Node_Doubly<T>* newn = new struct Node_Doubly<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
        First->prev = First;
        First->next = First;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
        newn->prev = Last;
        Last->next = First;
    }
}

template<class T>
void Doubly_LinkedList_Circular <T>:: InsertLast(T iNo)
{
    struct Node_Doubly<T>* newn = new struct Node_Doubly<T>;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;
        First->prev = First;
        First->next = First;
    }
    else
    {
        Last->next = newn;
        newn->prev = Last;
        First->prev = newn;
        Last = newn;
        Last->next = First;
    }
}

template<class T>
void Doubly_LinkedList_Circular <T>:: InsertAtPositon(T iNo, int iPos)
{
    struct Node_Doubly<T>* newn = new struct Node_Doubly<T>;
    struct Node_Doubly<T>* temp = NULL;
    newn->data = iNo;
    newn->next = NULL;
    newn->prev = NULL;

    int iCount = Count();

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }
    else if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(iNo);
    }
    else
    {
        temp = First;

        for(int iCnt = 1; iCnt < iPos-1 ; iCnt++)
        {
            temp = temp->next;
        }
       
        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;
    }
}

template<class T>
void Doubly_LinkedList_Circular <T>:: DeleteFirst()
{
    struct Node_Doubly<T>* temp = NULL;
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        First->prev = Last;
        Last->next = First;
        delete temp;
        temp = NULL;
    }
}

template<class T>
void Doubly_LinkedList_Circular <T>:: DeleteLast()
{
    struct Node_Doubly<T>* temp = NULL;
    if(First == NULL && Last == NULL)
    {
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = Last = NULL;
    }
    else
    {
        temp = Last;
        Last = Last->prev;
        Last->next = First;
        First->prev = Last;
        delete temp;
        temp = NULL;
    }
}

template<class T>
void Doubly_LinkedList_Circular <T>:: DeleteAtPosition(int iPos)
{
    struct Node_Doubly<T>* temp = NULL;
    struct Node_Doubly<T>* temp1 = NULL;

    int iCount = Count();
    if(iPos <1 || iPos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }
    else if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(int iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next->prev = temp;
        delete temp1;
        temp1 = NULL;
    }
}

template<class T>
void Doubly_LinkedList_Circular <T>:: Display()
{
    struct Node_Doubly<T>* temp = First;

    cout<<"NULL\t";
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    } while(temp != First);
    cout<<"NULL"<<"\n";
}

template<class T>
void Doubly_LinkedList_Circular <T>:: Display_Reverse()
{
    struct Node_Doubly<T>* temp = Last;

    cout<<"NULL\t";
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->prev;
    }while(temp != Last);
    cout<<"NULL"<<"\n";
}

template<class T>
void Doubly_LinkedList_Circular <T>:: Display_Circular()
{
    struct Node_Doubly<T>* temp = Last;
    int iCount = 0;

    cout<<"NULL\t";
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->prev;
        iCount++;
    }while(iCount < 10);
    cout<<"NULL"<<"\n";
}

template<class T>
int Doubly_LinkedList_Circular <T>:: Count()
{
    struct Node_Doubly<T>* temp = First;
    int iCount = 0;

    do
    {
        iCount++;
        temp = temp->next;
    }while(temp != First);
    return iCount;
}

template <class T>
int Doubly_LinkedList_Circular <T> :: Search_First_Occurance(T iNo)
{
    struct Node_Doubly<T>* temp = First;
    int Counter = 1,Ret = 0;

    do
    {
        if(temp->data == iNo)
        {
            Ret = Counter;
            break;
        }
        Counter++;
        temp = temp->next;
    }while(temp!= First);
    if(temp == NULL) return -1;

    return Ret;
}

template <class T>
int Doubly_LinkedList_Circular <T> :: Search_Last_Occurance(T iNo)
{
    struct Node_Doubly<T>* temp = First;
    int Counter = 1,Ret = 0;

    do
    {
        if((temp->data) == iNo)
        {
            Ret = Counter;
        }
        Counter++;
        temp = temp->next;
    }while(temp!= First);
    if(Ret == 0) return -1;

    return Ret;
}

template <class T>
T Doubly_LinkedList_Circular <T> :: Addition()
{
    struct Node_Doubly<T>* temp = First;
    T Sum = temp->data;
    temp = temp->next;

    while(temp!= First)
    {
        Sum = Sum + (temp->data);
        temp = temp->next;
    }
    return Sum;
}

template <class T>
T Doubly_LinkedList_Circular <T> :: Largest_Element()
{
    struct Node_Doubly<T>* temp = First;
    T Large = temp->data;

    do
    {
        if((temp->data) > Large)
        {
            Large = temp->data;
        }
        temp = temp->next;
    }while(temp!= First);
    return Large;
}

template <class T>
T Doubly_LinkedList_Circular <T> :: Smallest_Element()
{
    struct Node_Doubly<T>* temp = First;
    T Small = temp->data;

    do
    {
        if((temp->data) < Small)
        {
            Small = temp->data;
        }
        temp = temp->next;
    }while(temp!= First);
    return Small;
}

template <class T>
T Doubly_LinkedList_Circular <T> :: Second_Max_Element()
{
    struct Node_Doubly<T>* temp = First;
    T Large = temp->data;
    T Second_Large;
    temp = temp->next;

    do
    {
        if((temp->data) > Large )
        {
            Second_Large = Large;
            Large = temp->data;
        }
        else if((temp->data) > Second_Large)
        {
            Second_Large = temp->data;
        }
        temp = temp->next;
    }while(temp!= First);

    return Second_Large;
} 
  
//******************************Double Circular linked list ends here******************************
///////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************Stack Starts here**************************************

template <class T>
class Stack
{
    private:
    struct Node_Singly <T> * First;
    
    public:
        int Count;
        Stack();
        void PUSH(T iNo);
        T POP();
        void Display();
        int Search_First_Occurance(T iNo);
        int Search_Last_Occurance(T iNo);
        T Addition();
        T Largest_Element();
        T Smallest_Element();
        T Second_Max_Element();
};

template <class T>
Stack <T>:: Stack()
{
    First = NULL;
    Count = 0;
} 

template <class T>
void Stack <T>:: PUSH(T iNo)
{
    Node_Singly <T>* newn = new Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;
    
    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Count++;
    cout<<First->data<<"\t pushed successfully\n";
}

template <class T>
T Stack <T>:: POP()
{
    T iRet;

    if(First == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }
    
    else
    {
        iRet = First->data;
        Node_Singly <T>* temp = First;
        First = First->next;
        delete temp;
        temp = NULL;
    }
    Count--;
    cout<<iRet<<"\t poped successfully\n";
    return iRet;

}

template <class T>
void Stack <T>:: Display()
{
    if(First == NULL)
    {
        cout<<"Stack is empty\n";
        return;
    }
    Node_Singly <T>* temp = First;

    while(temp != NULL)
    {
        cout<<"\n| "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

template <class T>
int Stack <T> :: Search_First_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if(temp->data == iNo)
        {
            Ret = Counter;
            break;
        }
        Counter++;
        temp = temp->next;
    }
    if(temp == NULL) return -1;

    return Ret;
}

template <class T>
int Stack <T> :: Search_Last_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if((temp->data) == iNo)
        {
            Ret = Counter;
        }
        Counter++;
        temp = temp->next;
    }
    if(Ret == 0) return -1;

    return Ret;
}

template <class T>
T Stack <T> :: Addition()
{
    struct Node_Singly<T>* temp = First;
    T Sum = temp->data;
    temp = temp->next;

    while(temp!= NULL)
    {
        Sum = Sum + (temp->data);
        temp = temp->next;
    }
    return Sum;
}

template <class T>
T Stack <T> :: Largest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) > Large)
        {
            Large = temp->data;
        }
        temp = temp->next;
    }
    return Large;
}

template <class T>
T Stack <T> :: Smallest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Small = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) < Small)
        {
            Small = temp->data;
        }
        temp = temp->next;
    }
    return Small;
}

template <class T>
T Stack <T> :: Second_Max_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;
    T Second_Large = 0;
    temp = temp->next;

    while(temp!= NULL)
    {
        if((temp->data) > Large )
        {
            Second_Large = Large;
            Large = temp->data;
        }
        else if((temp->data) > Second_Large)
        {
            Second_Large = temp->data;
        }
        temp = temp->next;
    }
    return Second_Large;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************Stack Ends here**************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************Queue Starts here************************************

template <class T>
class Queue
{
    private:
    struct Node_Singly <T> * First;
    
    public:
        int Count;
        Queue();
        void EnQueue(T iNo);
        T DeQueue();
        void Display();
        int Search_First_Occurance(T iNo);
        int Search_Last_Occurance(T iNo);
        T Addition();
        T Largest_Element();
        T Smallest_Element();
        T Second_Max_Element();
};

template <class T>
Queue <T>:: Queue()
{
    First = NULL;
    Count = 0;
} 

template <class T>
void Queue <T>:: EnQueue(T iNo)    //insertLast
{
    Node_Singly <T>* newn = new Node_Singly<T>;
    newn->data = iNo;
    newn->next = NULL;

    
    
    if(First == NULL)
    {
        First = newn;
        cout<<First->data<<"\t EnQueueed successfully\n";
    }
    else
    {
        Node_Singly <T>* temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        cout<<temp->next->data<<"\t EnQueueed successfully\n";
    }
    Count++;
    
}

template <class T>
T Queue <T>:: DeQueue()
{
    T iRet;

    if(First == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }
    
    else
    {
        iRet = First->data;
        Node_Singly <T>* temp = First;
        First = First->next;
        delete temp;
        temp = NULL;
    }
    Count--;
    cout<<iRet<<"\t DeQueueed successfully\n";
    return iRet;

}

template <class T>
void Queue <T>:: Display()
{
    if(First == NULL)
    {
        cout<<"Queue is empty\n";
        return;
    }
    Node_Singly <T>* temp = First;

    while(temp != NULL)
    {
        cout<<"\n| "<<temp->data<<" |\n";
        temp = temp->next;
    }
}

template <class T>
int Queue <T> :: Search_First_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if(temp->data == iNo)
        {
            Ret = Counter;
            break;
        }
        Counter++;
        temp = temp->next;
    }
    if(temp == NULL) return -1;

    return Ret;
}

template <class T>
int Queue <T> :: Search_Last_Occurance(T iNo)
{
    struct Node_Singly<T>* temp = First;
    int Counter = 1,Ret = 0;

    while(temp!= NULL)
    {
        if((temp->data) == iNo)
        {
            Ret = Counter;
        }
        Counter++;
        temp = temp->next;
    }
    if(Ret == 0) return -1;

    return Ret;
}

template <class T>
T Queue <T> :: Addition()
{
    struct Node_Singly<T>* temp = First;
    T Sum = temp->data;
    temp = temp->next;

    while(temp!= NULL)
    {
        Sum = Sum + (temp->data);
        temp = temp->next;
    }
    return Sum;
}

template <class T>
T Queue <T> :: Largest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) > Large)
        {
            Large = temp->data;
        }
        temp = temp->next;
    }
    return Large;
}

template <class T>
T Queue <T> :: Smallest_Element()
{
    struct Node_Singly<T>* temp = First;
    T Small = temp->data;

    while(temp!= NULL)
    {
        if((temp->data) < Small)
        {
            Small = temp->data;
        }
        temp = temp->next;
    }
    return Small;
}

template <class T>
T Queue <T> :: Second_Max_Element()
{
    struct Node_Singly<T>* temp = First;
    T Large = temp->data;
    T Second_Large = 0;
    temp = temp->next;

    while(temp!= NULL)
    {
        if((temp->data) > Large )
        {
            Second_Large = Large;
            Large = temp->data;
        }
        else if((temp->data) > Second_Large)
        {
            Second_Large = temp->data;
        }
        temp = temp->next;
    }
    return Second_Large;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//******************************************Queue Ends here**************************************
/////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************Binary Search Tree Starts here*******************************

template <class T>
class BST
{
    private:
    struct Node_Binary <T> * First;
    
    public:
        int Count;
        BST();
        void Insert(T iNo);
        void Display_InOrder();
        void Display_PreOrder();
        void Display_PostOrder();
};

template <class T>
BST <T>:: BST()
{
    First = NULL;
    Count = 0;
} 

template <class T>
void BST <T>:: Insert(T iNo)    //insertLast
{
    Node_Binary <T>* newn = new Node_Binary<T>;
    newn->data = iNo;
    newn->Lchild = NULL;
    newn->Rchild = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        Node_Binary <T>* temp = First;    
        while(1)
        {
            if(iNo > (temp->data))
            {
                if((temp->Rchild) == NULL)
                {
                    temp->Rchild = newn;
                    break;
                }
                temp = temp->Rchild;
            }
            else if(iNo < (temp -> data))
            {
                if((temp->Lchild) == NULL)
                {
                    temp->Lchild = newn;
                    break;
                }
                temp = temp->Lchild;
            }
            else
            {
                free (newn);
                cout<<"Duplicate values are not allowed\n";
                break;
            }
        }
    }
    Count++;
    
}

template <class T>
void BST <T> :: Display_InOrder()
{
    Display_InOrderX(this->First);
}

template <class T>
void BST <T> :: Display_PreOrder()
{
    Display_PreOrderX(this->First);
}

template <class T>
void BST <T> :: Display_PostOrder()
{
    Display_PostOrderX(this->First);
}

template <class T>
void Display_InOrderX(Node_Binary <T> * temp)
{ 

    if(temp != NULL)
    {        
        Display_InOrderX(temp->Lchild);
        cout<<temp->data<<"\t";
        Display_InOrderX(temp->Rchild);
    }
}

template <class T>
void Display_PreOrderX(Node_Binary <T> * temp)
{ 

    if(temp != NULL)
    {   
        cout<<temp->data<<"\t";     
        Display_PreOrderX(temp->Lchild);
        Display_PreOrderX(temp->Rchild);
    }
}

template <class T>
void Display_PostOrderX(Node_Binary <T> * temp)
{ 

    if(temp != NULL)
    {   
        Display_PostOrderX(temp->Lchild);
        Display_PostOrderX(temp->Rchild);
        cout<<temp->data<<"\t";  
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//**********************************Binary Search Tree Starts here*******************************
/////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int iRet = 0;
    double dRet = 0.0;
    
    Singly_LinkedList_Linear <double>objSLL;
    Singly_LinkedList_Circular <double>objSCL;
    Doubly_LinkedList_Linear <double>objDLL;
    Doubly_LinkedList_Circular <double>objDCL;
    Stack <char>objStack;
    Queue <char>objQueue;
    BST <int>objBST;

    cout<<"\n\n***************************Singly Linear Linked List***************************\n\n";

    objSLL.InsertFirst(51);
    objSLL.InsertFirst(21001);
    objSLL.InsertFirst(50000);
    objSLL.Display();
    iRet = objSLL.Count();
    cout<<"Count : "<<iRet<<"\n";

    objSLL.InsertLast(1);
    objSLL.InsertLast(21007);
    objSLL.InsertLast(1131);
    objSLL.InsertLast(90);
    objSLL.InsertLast(0);
    objSLL.Display();
    iRet = objSLL.Count();
    cout<<"Count : "<<iRet<<"\n";
    /////////////////////////////////////////////////////////////////////

    dRet = objSLL.Search_First_Occurance(1131);
    cout<<"First occurance : "<<dRet<<endl;

    dRet = objSLL.Search_Last_Occurance(1131);
    cout<<"Last occurance : "<<dRet<<endl;
    
    dRet = objSLL.Addition();
    cout<<"Addition : "<<dRet<<endl;

    dRet = objSLL.Largest_Element();
    cout<<"Largest_Element : "<<dRet<<endl;

    dRet = objSLL.Smallest_Element();
    cout<<"Smallest_Element : "<<dRet<<endl;

    dRet = objSLL.Second_Max_Element();
    cout<<"Second_Max_Element : "<<dRet<<endl;

    objSLL.ReverseTheLL();
    objSLL.Display();
    iRet = objSLL.Count();
    cout<<"Count : "<<iRet<<"\n";

    dRet = objSLL.Search_First_Occurance(1131);
    cout<<"First occurance : "<<dRet<<endl;

    dRet = objSLL.Search_Last_Occurance(1131);
    cout<<"Last occurance : "<<dRet<<endl;
    
    dRet = objSLL.Addition();
    cout<<"Addition : "<<dRet<<endl;

    dRet = objSLL.Largest_Element();
    cout<<"Largest_Element : "<<dRet<<endl;

    dRet = objSLL.Smallest_Element();
    cout<<"Smallest_Element : "<<dRet<<endl;

    dRet = objSLL.Second_Max_Element();
    cout<<"Second_Max_Element : "<<dRet<<endl;

    objSLL.ReverseTheLL();
    objSLL.Display();
    iRet = objSLL.Count();
    cout<<"Count : "<<iRet<<"\n";

    
    ////////////////////////////////////////////////////

    cout<<"\n\n***************************Singly Circular Linked List***************************\n\n";

    objSCL.InsertFirst(100);
    objSCL.InsertFirst(3);
    objSCL.InsertFirst(300);
    objSCL.Display();
    objSCL.Display_Circular();
    iRet = objSCL.Count();
    cout<<"Count : "<<iRet<<"\n";

    objSCL.InsertLast(4);
    objSCL.InsertLast(3);
    objSCL.InsertLast(5);
    objSCL.Display();
    objSCL.Display_Circular();
    iRet = objSCL.Count();
    cout<<"Count : "<<iRet<<"\n";   

    dRet = objSCL.Search_First_Occurance(3);
    cout<<"First occurance : "<<dRet<<endl;

    dRet = objSCL.Search_Last_Occurance(3);
    cout<<"Last occurance : "<<dRet<<endl;
    
    dRet = objSCL.Addition();
    cout<<"Addition : "<<dRet<<endl;

    dRet = objSCL.Largest_Element();
    cout<<"Largest_Element : "<<dRet<<endl;

    dRet = objSCL.Smallest_Element();
    cout<<"Smallest_Element : "<<dRet<<endl;

    dRet = objSCL.Second_Max_Element();
    cout<<"Second_Max_Element : "<<dRet<<endl;

    /////////////////////////////////////////

    cout<<"\n\n***************************Doubly Linear Linked List***************************\n\n";

    objDLL.InsertFirst(121.3);
    objDLL.InsertFirst(3);
    objDLL.InsertFirst(151.8);
    objDLL.Display();
    objDLL.Display_Reverse();
    iRet = objDLL.Count();
    cout<<"Count : "<<iRet<<"\n";

    objDLL.InsertLast(101.9);
    objDLL.InsertLast(3);
    objDLL.InsertLast(30);
    objDLL.Display();
    objDLL.Display_Reverse();
    iRet = objDLL.Count();
    cout<<"Count : "<<iRet<<"\n";

    dRet = objDLL.Search_First_Occurance(3);
    cout<<"First occurance : "<<dRet<<endl;

    dRet = objDLL.Search_Last_Occurance(3);
    cout<<"Last occurance : "<<dRet<<endl;
    
    dRet = objDLL.Addition();
    cout<<"Addition : "<<dRet<<endl;

    dRet = objDLL.Largest_Element();
    cout<<"Largest_Element : "<<dRet<<endl;

    dRet = objDLL.Smallest_Element();
    cout<<"Smallest_Element : "<<dRet<<endl;

    dRet = objDLL.Second_Max_Element();
    cout<<"Second_Max_Element : "<<dRet<<endl;

    ////////////////////////////////////////

    cout<<"\n\n***************************Doubly Circular Linked List***************************\n\n";

    objDCL.InsertFirst(51);
    objDCL.InsertFirst(21);
    objDCL.InsertFirst(1111);
    objDCL.Display();
    objDCL.Display_Reverse();
    objDCL.Display_Circular();
    iRet = objDCL.Count();
    cout<<"Count : "<<iRet<<"\n";

    objDCL.InsertLast(21);
    objDCL.InsertLast(111);
    objDCL.InsertLast(121);
    objDCL.Display();
    objDCL.Display_Reverse();
    objDCL.Display_Circular();
    iRet = objDCL.Count();
    cout<<"Count : "<<iRet<<"\n";

    dRet = objDCL.Search_First_Occurance(21);
    cout<<"First occurance : "<<dRet<<endl;

    dRet = objDCL.Search_Last_Occurance(21);
    cout<<"Last occurance : "<<dRet<<endl;
    
    dRet = objDCL.Addition();
    cout<<"Addition : "<<dRet<<endl;

    dRet = objDCL.Largest_Element();
    cout<<"Largest_Element : "<<dRet<<endl;

    dRet = objDCL.Smallest_Element();
    cout<<"Smallest_Element : "<<dRet<<endl;

    dRet = objDCL.Second_Max_Element();
    cout<<"Second_Max_Element : "<<dRet<<endl;

    cout<<"\n\n***************************Stack***************************\n\n";

    objStack.PUSH('a');
    objStack.PUSH('b');
    objStack.PUSH('c');
    objStack.PUSH('d');

    objStack.Display();
    iRet = objStack.Count;
    cout<<"Count : "<<iRet<<endl;

    iRet = objStack.Search_First_Occurance(21);
    cout<<"First occurance : "<<iRet<<endl;

    iRet = objStack.Search_Last_Occurance(21);
    cout<<"Last occurance : "<<iRet<<endl;
    
    dRet = objStack.Addition();
    cout<<"Addition : "<<dRet<<endl;

    dRet = objStack.Largest_Element();
    cout<<"Largest_Element : "<<dRet<<endl;

    dRet = objStack.Smallest_Element();
    cout<<"Smallest_Element : "<<dRet<<endl;

    dRet = objStack.Second_Max_Element();
    cout<<"Second_Max_Element : "<<dRet<<endl;
    
    cout<<"\n\n***************************Queue***************************\n\n";

    objQueue.EnQueue('a');
    objQueue.EnQueue('b');
    objQueue.EnQueue('a');
    objQueue.EnQueue('d');
    objQueue.EnQueue('e');
   
    objQueue.Display();
    iRet = objQueue.Count;
    cout<<"Count : "<<iRet<<endl;

    iRet = objQueue.Search_First_Occurance('a');
    cout<<"First occurance : "<<iRet<<endl;

    iRet = objQueue.Search_Last_Occurance('a');
    cout<<"Last occurance : "<<iRet<<endl;
    
    dRet = objQueue.Addition();
    cout<<"Addition : "<<dRet<<endl;

    dRet = objQueue.Largest_Element();
    cout<<"Largest_Element : "<<dRet<<endl;

    dRet = objQueue.Smallest_Element();
    cout<<"Smallest_Element : "<<dRet<<endl;

    dRet = objQueue.Second_Max_Element();
    cout<<"Second_Max_Element : "<<dRet<<endl;

    objQueue.DeQueue();
    objQueue.Display();
    iRet = objQueue.Count;
    cout<<"Count : "<<iRet<<endl;

    objQueue.DeQueue();
    objQueue.Display();
    iRet = objQueue.Count;
    cout<<"Count : "<<iRet<<endl;

    cout<<"\n\n***************************Queue***************************\n\n";


    objBST.Insert(7);
    objBST.Insert(11);
    objBST.Insert(76);
    objBST.Insert(4);
    objBST.Insert(13);
    
    cout<<"BST Display inorder\n";
   objBST.Display_InOrder();
   cout<<"\n";
   cout<<"BST Display inorder\n";
   objBST.Display_PreOrder();
   cout<<"\n";
   cout<<"BST Display inorder\n";
   objBST.Display_PostOrder();
   cout<<"\n";

    return 0;
}