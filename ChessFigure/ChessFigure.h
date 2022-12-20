#pragma once

#include <string>

using namespace std;

struct ChessFigure {
  string currentCoord;

  ChessFigure(string coord);
  ~ChessFigure();

  bool Move(string nextCoord);
  bool isWithinBoard(string nextCoord);
  virtual bool isValidMove(string nextCoord) = 0;
};

struct Pawn : ChessFigure {
  bool isValidMove(string nextCoord) override;
};

struct Rook : ChessFigure {
  bool isValidMove(string nextCoord) override;
};

struct Knight : ChessFigure {
  bool isValidMove(string nextCoord) override;
};

struct Bishop : ChessFigure {
  bool isValidMove(string nextCoord) override;
};

struct King : ChessFigure {
  bool isValidMove(string nextCoord) override;
};

struct Queen : ChessFigure {
  bool isValidMove(string nextCoord) override;
};