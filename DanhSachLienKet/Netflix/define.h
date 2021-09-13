/*
 *      \\\   |||  |||||||  |||||||||  |||||||  |||      |||  \\\  ///
 *      |\\\  |||  |||         |||     |||      |||      |||   \\\///
 *      ||\\\ |||  |||         |||     |||||||  |||      |||    \///
 *      |||\\\|||  |||||||     |||     |||      |||      |||    ///\
 *      ||| \\\||  |||         |||     |||      |||      |||   ///\\\
 *      |||  \\\|  |||||||     |||     |||      |||||||  |||  ///  \\\
 *  
 *                          (c) 2021 Minh Thang
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Node
{
    char user_id[10],
        movie_id[10];
    int start;
    struct Node *next_user,
        *next_movie;
};

/* Kieu vi tri */
typedef struct Node *Position;

/* Kieu cua ma tran */
typedef Position Matrix;

typedef Position User;
typedef Position Movie;
typedef Position Rate;

Position makePosition()
{
    Position P = (Position)malloc(sizeof(struct Node));
    P->next_user = NULL;
    P->next_movie = NULL;
    return P;
}

void makenullMatrix(Matrix *pMx)
{
    *pMx = makePosition();
}

User makeUser(char id[10])
{
    User U = makePosition();
    strcpy(U->user_id, id);
    return U;
}

Movie makeMovie(char id[10])
{
    Movie M = makePosition();
    strcpy(M->movie_id, id);
    return M;
}

Position firstUser(Matrix Mx)
{
    return Mx;
}

Position nextUser(User U)
{
    return U->next_user;
}

Position endUser(Matrix Mx)
{
    Position P = firstUser(Mx);
    while (nextUser(P) != NULL)
        P = nextUser(P);
    return P;
}

Position firstMovie(Matrix Mx)
{
    return Mx;
}

Position nextMovie(Movie M)
{
    return M->next_movie;
}

Position endMovie(Matrix Mx)
{
    Position P = firstMovie(Mx);
    while (nextMovie(P) != NULL)
        P = nextMovie(P);
    return P;
}

int existUser(User U, Matrix Mx)
{
    Position P = firstUser(Mx);
    while (nextUser(P) != NULL)
    {
        if (strcmp(U->user_id, P->next_user->user_id))
            return 1;
        P = nextUser(P);
    }
    return 0;
}

int existMovie(Movie M, Matrix Mx)
{
    Position P = firstMovie(Mx);
    while (P->next_movie != NULL)
    {
        if (strcmp(M->movie_id, P->next_movie->movie_id) == 0)
            return 1;
        P = nextMovie(P);
    }
    return 0;
}

void addMovie(Movie M, Matrix *pMx)
{
    if (existMovie(M, *pMx))
        return;
    M->next_movie = (*pMx)->next_movie;
    (*pMx)->next_movie = M;
}

void addUser(User U, Matrix *pMx)
{
    if (existUser(U, *pMx))
        return;
    U->next_user = (*pMx)->next_user;
    (*pMx)->next_user = U;
}

Rate makeRate(int start)
{
    Rate R = makePosition();
    R->start = start;
    return R;
}

void rated(int start, User U, Movie M)
{
    Rate R = makeRate(start);

    R->next_movie = U->next_movie;
    U->next_movie = R;

    R->next_user = M->next_user;
    M->next_user = R;
}

void printMovieRate(Movie M)
{
    printf("id: ");
    puts(M->movie_id);
    puts("start:");
    Position P = firstUser(M);
    while (nextUser(P) != NULL)
    {
        printf("%d\n", P->next_user->start);
        P = nextUser(P);
    }
}
