//#include "pch.h"
#include "ChessFigure.h"
#include <string>
#include <cmath>

using namespace std;

ChessFigure::ChessFigure(/*ChessFigure::FigureType type,*/ std::string coord)
		: /*type(type),*/ currentCoord(coord)	{
}


ChessFigure::~ChessFigure()
{
}

bool ChessFigure::Move(string nextCoord)
{
	/*if (type == PAWN)
	{
		if (isWithinBoard(nextCoord))
		{
			if (nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')))
				return false;
			else
				return true;
		}
		else return false;
			
	}
	
	else if (type == ROOK)
	{
		if (isWithinBoard(nextCoord))
		{
			if ((nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])))
				return false;
			else
				return true;

		}
		else return false;
	}
	else if (type == KNIGHT)
	{
		if (isWithinBoard(nextCoord))
		{
			int dx, dy;
			dx = abs(nextCoord[0] - currentCoord[0]);
			dy = abs(nextCoord[1] - currentCoord[1]);
		    if (!(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1))
			  return false;
			else
			return true;
		}
		else return false;
	}
	
	else if (type == BISHOP)
	{
		if (isWithinBoard(nextCoord))
		{
			if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1])))
				return false;
			else
				return true;
		}
		else return false;
	}
	
	else if (type == KING)
	{
		if (isWithinBoard(nextCoord))
		{
			if (!(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1))
				return false;
			else
				return true;
		}
		else return false;
	}
	else if (type == QUEEN)
	{
		if (isWithinBoard(nextCoord))
		{
			if (!(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]))
				return false;
			else
				return true;
		}
		else return false;
	}
	else
		return false;*/

	return isWithinBoard(nextCoord) && isValidMove(nextCoord);
}

bool ChessFigure::isWithinBoard(string nextCoord) {
	return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' && nextCoord[1] <= '8';
}

bool Pawn::isValidMove(string nextCoord) {
	return nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] || (nextCoord[1] - currentCoord[1] != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4'));
}

bool Rook::isValidMove(string nextCoord) {
	return (nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) || ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1]));
}

bool Knight::isValidMove(string nextCoord) {
	return !(abs(nextCoord[0] - currentCoord[0]) == 1 && abs(nextCoord[1] - currentCoord[1]) == 2 || abs(nextCoord[0] - currentCoord[0]) == 2 && abs(nextCoord[1] - currentCoord[1]) == 1);
}

bool Bishop::isValidMove(string nextCoord) {
	return !(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]));
}

bool King::isValidMove(string nextCoord) {
	return !(abs(nextCoord[0] - currentCoord[0]) <= 1 && abs(nextCoord[1] - currentCoord[1]) <= 1);
}

bool Queen::isValidMove(string nextCoord) {
	return !(abs(nextCoord[0] - currentCoord[0]) == abs(nextCoord[1] - currentCoord[1]) || nextCoord[0] == currentCoord[0] || nextCoord[1] == currentCoord[1]);
}