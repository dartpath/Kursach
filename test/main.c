#define CTEST_MAIN

#include "board.h"
#include <ctest.h>

char A[10][10];

CTEST(insert_coordinates, INCORRECT_MOVE) // a2 a12
{
    bool result = move(7, 1, -3, 1, A);
    ASSERT_FALSE(result);
}

CTEST(insert_coordinates, PAWN_CORRECT) // a2 a3 
{
	bool result = move(7, 1, 6, 2, A);
	ASSERT_TRUE(result);
}

CTEST(insert_coordinates, PAWN_INCORRECT) // a2 a7
{
	bool result = move(7, 1, 2, 1, A);
	ASSERT_FALSE(result);
}

CTEST(insert_coordinates, ROOK_INCORRECT) // h1 h2
{
	bool result = move(8, 1, 8, 2, A);
	ASSERT_FALSE(result);
}

CTEST(insert_coordinates, KNIGHT_CORRECT) // b1 c3
{
	bool result = move(8, 2, 6, 3, A);
	ASSERT_TRUE(result);
}

CTEST(insert_coordinates, KNIGHT_INCORRECT) // b1 b2
{
	bool result = move(8, 2, 7, 2, A);
	ASSERT_FALSE(result);
}

CTEST(insert_coordinates, BISHOP_INCORRECT) // c1 b2
{
	bool result = move(8, 3, 7, 2, A);
	ASSERT_FALSE(result);
}

CTEST(insert_coordinates, QUEEN_INCORRECT) // d1 c1
{
	bool result = move(8, 4, 8, 3, A);
	ASSERT_FALSE(result);
}

CTEST(insert_coordinates, KING_INCORRECT) // e1 e2
{
	bool result = move(8, 5, 7, 5, A);
	ASSERT_FALSE(result);
}

int main(int argc, const char** argv)
{
	layout(A);
    return ctest_main(argc, argv);
}