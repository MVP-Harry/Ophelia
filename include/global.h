#ifndef GLOBAL_FUCKING_BITCH
#define GLOBAL_FUCKING_BITCH

#include <string>

// Square names
 const int A8 = 56;  const int B8 = 57;  const int C8 = 58;  const int D8 = 59;
 const int E8 = 60;  const int F8 = 61;  const int G8 = 62;  const int H8 = 63;
 const int A7 = 48;  const int B7 = 49;  const int C7 = 50;  const int D7 = 51;
 const int E7 = 52;  const int F7 = 53;  const int G7 = 54;  const int H7 = 55;
 const int A6 = 40;  const int B6 = 41;  const int C6 = 42;  const int D6 = 43;
 const int E6 = 44;  const int F6 = 45;  const int G6 = 46;  const int H6 = 47;
 const int A5 = 32;  const int B5 = 33;  const int C5 = 34;  const int D5 = 35;
 const int E5 = 36;  const int F5 = 37;  const int G5 = 38;  const int H5 = 39;
 const int A4 = 24;  const int B4 = 25;  const int C4 = 26;  const int D4 = 27;
 const int E4 = 28;  const int F4 = 29;  const int G4 = 30;  const int H4 = 31;
 const int A3 = 16;  const int B3 = 17;  const int C3 = 18;  const int D3 = 19;
 const int E3 = 20;  const int F3 = 21;  const int G3 = 22;  const int H3 = 23;
 const int A2 =  8;  const int B2 =  9;  const int C2 = 10;  const int D2 = 11;
 const int E2 = 12;  const int F2 = 13;  const int G2 = 14;  const int H2 = 15;
 const int A1 =  0;  const int B1 =  1;  const int C1 =  2;  const int D1 =  3;
 const int E1 =  4;  const int F1 =  5;  const int G1 =  6;  const int H1 =  7;

#define ull unsigned long long

const int KNIGHT_MOVE_X[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
const int KNIGHT_MOVE_Y[8] = {2, -2, 2, -2, 1, -1, 1, -1};
const int KING_MOVE_X[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int KING_MOVE_Y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

const std::string SQUARENAME[64] = {"a1","b1","c1","d1","e1","f1","g1","h1",
                              "a2","b2","c2","d2","e2","f2","g2","h2",
                              "a3","b3","c3","d3","e3","f3","g3","h3",
                              "a4","b4","c4","d4","e4","f4","g4","h4",
                              "a5","b5","c5","d5","e5","f5","g5","h5",
                              "a6","b6","c6","d6","e6","f6","g6","h6",
                              "a7","b7","c7","d7","e7","f7","g7","h7",
                              "a8","b8","c8","d8","e8","f8","g8","h8"};

const std::string PIECENAMES[16] = {"  ","P ","K ","N ","  ","B ","R ","Q ",
                              "  ","p ","k ","n ","  ","b ","r ","q "};

const int NEWGAME[64] = {
	   6 , 3 , 5 , 7 , 2 , 5 , 3 , 6 ,
	   1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 ,
	   0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
	   0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
	   0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
	   0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
	   9 , 9 , 9 , 9 , 9 , 9 , 9 , 9 ,
	   14, 11, 13, 15, 10, 13, 11, 14
};

 const int FILES[64] = {
       1, 2, 3, 4, 5, 6, 7, 8,
       1, 2, 3, 4, 5, 6, 7, 8,
       1, 2, 3, 4, 5, 6, 7, 8,
       1, 2, 3, 4, 5, 6, 7, 8,
       1, 2, 3, 4, 5, 6, 7, 8,
       1, 2, 3, 4, 5, 6, 7, 8,
       1, 2, 3, 4, 5, 6, 7, 8,
       1, 2, 3, 4, 5, 6, 7, 8
};
 
 const int RANKS[64] = {
       1, 1, 1, 1, 1, 1, 1, 1,
       2, 2, 2, 2, 2, 2, 2, 2,
       3, 3, 3, 3, 3, 3, 3, 3,
       4, 4, 4, 4, 4, 4, 4, 4,
       5, 5, 5, 5, 5, 5, 5, 5,
       6, 6, 6, 6, 6, 6, 6, 6,
       7, 7, 7, 7, 7, 7, 7, 7,
       8, 8, 8, 8, 8, 8, 8, 8
};

// Piece identifiers, 4 bits each.
// Usefull bitwise properties of this numbering scheme:
// white = 0..., black = 1..., sliding = .1.., nonsliding = .0..
// rank/file sliding pieces = .11., diagonally sliding pieces = .1.1
// pawns and kings (without color bits), are < 3
// major pieces (without color bits set), are > 5
// minor and major pieces (without color bits set), are > 2
 const int EMPTY = 0;                //  0000
 const int WHITE_PAWN = 1;           //  0001
 const int WHITE_KING = 2;           //  0010
 const int WHITE_KNIGHT = 3;         //  0011
 const int WHITE_BISHOP =  5;        //  0101
 const int WHITE_ROOK = 6;           //  0110
 const int WHITE_QUEEN = 7;          //  0111
 const int BLACK_PAWN = 9;           //  1001
 const int BLACK_KING = 10;          //  1010
 const int BLACK_KNIGHT = 11;        //  1011
 const int BLACK_BISHOP = 13;        //  1101
 const int BLACK_ROOK = 14;          //  1110
 const int BLACK_QUEEN = 15;         //  1111

 // Value of material, in centipawns:
 const int PAWN_VALUE = 100;
 const int KNIGHT_VALUE = 300;
 const int BISHOP_VALUE = 300;
 const int ROOK_VALUE = 500;
 const int QUEEN_VALUE = 900;
 const int KING_VALUE = 9999;
 const int CHECK_MATE = KING_VALUE;

extern ull KNIGHT_ATTACK[64];
extern ull KING_ATTACK[64];
extern ull WHITE_PAWN_ATTACK[64];
extern ull BLACK_PAWN_ATTACK[64];
extern ull RANK_ATTACK[64][64];
extern ull FILE_ATTACK[64][64];

void genKnight();

void genKing();

void genPawns();

void init();
 
std::pair<int, int> intToPair(int num);

int pairToInt(std::pair<int, int> p);

void bitdisplay(ull x);

bool isSameFile(int x, int y);

#endif
