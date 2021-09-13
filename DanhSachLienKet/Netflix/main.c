#include "define.h"

int main()
{
    Matrix M;
    makenullMatrix(&M);

    addUser(makeUser("1234"), &M);
    addUser(makeUser("1234"), &M);
    addUser(makeUser("123e4"), &M);

    addMovie(makeMovie("2332"), &M);

    rated(5, M->next_user, M->next_movie);
    printMovieRate(M->next_movie);
    return 0;
}