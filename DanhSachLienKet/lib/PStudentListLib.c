/**
 * @file PStudentListLib.c
 * @author Minh Thắng (https://github.com/thangved)
 * @brief 
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) Minh Thắng 2021
 * 
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*__DEFINE__TYPE__*/
typedef struct
{
    char ID[10], Name[50];
    float R1, R2, R3;
} Student;

struct Node
{
    Student Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef struct Node *List;
/*__END__DEFINE__TYPE__*/

/*__FUNCTIONS__DECLARATION__*/
int append(Student s, List *pL);    // chen 1 sinh vien vao cuoi danh sach
List getList();                     // tra ve danh sach rong
List getFailedList(List L);         // tra ve sinh sach sinh vien chua dat
Position locate(char ID[], List L); // tra ve vi tri dau tien cua ID
void printList(List L);             // hien thi danh sach
void showPassedList(List L);        // hien th sinh vien dat
/*__END__FUNCTIONS__DECLARATION__*/

/*__FUNCTIONS__BODY__*/
int append(Student s, List *pL)
{
    List P = *pL;
    while (P->Next != NULL)
    {
        if (strcmp(s.ID, P->Next->Element.ID) == 0)
            return 0;
        P = P->Next;
    }
    P->Next = (List)malloc(sizeof(List));
    strcpy(P->Next->Element.ID, s.ID);
    strcpy(P->Next->Element.Name, s.Name);
    P->Next->Element.R1 = s.R1;
    P->Next->Element.R1 = s.R2;
    P->Next->Element.R1 = s.R3;
    return 1;
}
List getList()
{
    List L;
    L = (List)malloc(sizeof(List));
    return L;
}
List getFailedList(List L)
{
    List S = L,
         FL = getList();
    int a;
    while (S->Next != NULL)
    {
        if ((S->Next->Element.R1 + S->Next->Element.R2 + S->Next->Element.R3) / 3 < 4)
            a = append(S->Next->Element, &FL);
        S = S->Next;
    }
    a++;
    return FL;
}
List locate(char ID[], List L)
{
    List P = L;
    while (P->Next != NULL)
    {
        if (strcmp(ID, P->Next->Element.ID) == 0)
            return P;
        P = P->Next;
    }
    return P;
}
void printList(List L)
{
    List P = L;
    int i = 1;
    while (P->Next != NULL)
    {
        printf("%2d -", i);
        printf("%11s -", P->Next->Element.ID);
        printf("%51s - ", P->Next->Element.Name);
        printf("%.3f - ", P->Next->Element.R1);
        printf("%.3f - ", P->Next->Element.R2);
        printf("%.3f - ", P->Next->Element.R3);
        printf("%.3f\n", (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
        P = P->Next;
        i++;
    }
}
void showPassedList(List L)
{
    List P = L;
    int i = 1;
    while (P->Next != NULL)
    {
        if ((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3 >= 4)
        {
            printf("%2d -", i);
            printf("%11s -", P->Next->Element.ID);
            printf("%51s - ", P->Next->Element.Name);
            printf("%.3f - ", P->Next->Element.R1);
            printf("%.3f - ", P->Next->Element.R2);
            printf("%.3f - ", P->Next->Element.R3);
            printf("%.3f\n", (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
            i++;
        }
        P = P->Next;
    }
    printf("%d students in total", i - 1);
}
/*__END__FUNCTIONS__BODY__*/