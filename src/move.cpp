#include "global.h"
#include <iostream>
#include <move.h>

Move::Move() {
	move = 0;
}

Move::Move(int m) {
	move = m;
}

void Move::clear() {
	move = 0;
}

void Move::setFrom(int from) {
	move &= 0xffffffc0; 
	move |= (from & 0x0000003f);
}

void Move::setTo(int to) {
	move &= 0xfffff03f;
	move |= (to & 0x0000003f) << 6;
}

void Move::setPiece(int piece) {
	move &= 0xffff0fff;
	move |= (piece & 0x0000000f) << 12;
}

void Move::setCapture(int capture) {
	move &= 0xfff0ffff;
	move |= (capture & 0x0000000f) << 16;
}

void Move::setProm(int prom) {
	move &= 0xff0fffff;
	move |= (prom & 0x0000000f) << 20;
}

int Move::getFrom() {
	return move & 63;
}

int Move::getTo() {
	return (move >> 6) & 63;
}

int Move::getPiece() {
	return (move >> 12) & 15;
}

int Move::getCapture() {
	return (move >> 16) & 15;
}

int Move::getProm() {
	return (move >> 20) & 15;
}

bool Move::isWhitemove() {   
	 // piec is white: bit 15 must be 0
    return ((move >> 15) & 1) == 0;
} 
 
bool Move::isBlackmove()  {
	// piec is black: bit 15 must be 1
	return (move >> 15) & 1;
} 
 
bool Move::isCapture() {
   	// capt is nonzero, bits 16 to 19 must be nonzero
    return ((move >> 16) & 15) != 0;
} 
 
bool Move::isKingcaptured() {
   	// bits 17 to 19 must be 010
    return ((move >> 17) & 7) == 2;
} 
 
bool Move::isRookmove() {
   	// bits 13 to 15 must be 110
    return ((move >> 13) & 7) == 6;
} 
 
bool Move::isRookcaptured() {
	// bits 17 to 19 must be 110
    return ((move >> 17) & 7) == 6;
} 
 
bool Move::isKingmove() {
    // bits 13 to 15 must be 010
    return ((move >> 13) & 7) == 2;
} 
 
bool Move::isPawnmove() {
    // bits 13 to 15 must be 001
    return ((move >> 13) & 7) == 1;
} 
 
bool Move::isPawnDoublemove() {
    // bits 13 to 15 must be 001 &
       //     bits 4 to 6 must be 001 (from rank 2) & bits 10 to 12 must be 011 (to rank 4)
    // OR: bits 4 to 6 must be 110 (from rank 7) & bits 10 to 12 must be 100 (to rank 5)
 
  	return (((move >> 13) & 7) == 1 && ((move >> 4) & 7) == 1 && ((move >> 10) & 7) == 3) || 
		(((move >> 13) & 7) == 1 && ((move >> 4) & 7) == 6  && ((move >> 10) & 7) == 4);
 } 
 
bool Move::isEnpassant() {
    // prom is a pawn, bits 21 to 23 must be 001
    return ((move >> 20) & 7) == 1;
} 

bool Move::isPromotion() {
    // prom (with color bit removed), .xxx > 2 (not king or pawn)
    return ((move >> 20) & 7) > 2;
} 

bool Move::isCastle() {
    // prom is a king, bits 21 to 23 must be 010
    return ((move >> 20) & 7) == 2;
} 

bool Move::isCastleOO() {
    // prom is a king and tosq is on the g-file
    return isCastle() && (getTo() % 8 == 6);
} 
 
bool Move::isCastleOOO() {   
	// prom is a king and tosq is on the c-file
    return isCastle() && (getTo() % 8 == 2);
}

void Move::display() {
	std::cout << "Original Square is: " << SQUARENAME[getFrom()] << std::endl;
	std::cout << "Target Square is: " << SQUARENAME[getTo()] << std::endl;
	std::cout << "Piece is: " << PIECENAMES[getPiece()] << std::endl;
	std::cout << "Capture is: " << PIECENAMES[getCapture()] << std::endl;
	std::cout << "Color is: " << (isWhitemove() ? "WHITE" : "BLACK") << std::endl;
	std::cout << "Promotion is: " << PIECENAMES[getProm()] << std::endl;
	std::cout << "Is castle? " << (isCastle() ? "YES" : "NO") << std::endl;
	std::cout << std::endl;
}
