#include "generator.h"
#include <iostream>
#include <perft.h>
#include <makemove.h>
 
int perft(int ply, int depth) {
 
       // Raw node count, up to depth, doing a full tree search.
       // perft is very similar to the search algorithm - instead of evaluating the leaves, we count them.
       //
       // Be carefull when calling this function with depths > 7, because it can take a very long
       // time before the result is returned: the average branching factor in chess is 35, so every
       // increment in depth will require 35x more computer time.
       //
       // perft is a good way of verifying correctness of the movegenerator and (un)makeMove,
       // because you can compare the results with published results for certain test positions.
       //
       // perft is also used to measure the performance of the move generator and (un)makeMove in terms
       // of speed, and to compare different implementations of generating, storing and (un)making moves.
 
       int retVal = 0;     
 
       // count this node
       if (depth == 0) {
            return 1;
       }
 

       // generate moves from this position
	   int temp = board.moveBufLen[ply];
       board.moveBufLen[ply + 1] = generateMoves(temp);
 
       // loop over moves:
       for (int i = board.moveBufLen[ply]; i < board.moveBufLen[ply+1]; i++) {
              makeMove(board.moveBuf[i]);
              {
                     if (!isKingAttacked(board.moveBuf[i]))
                     {
                           // recursively call perft
                           retVal += perft(ply + 1, depth - 1);
 
                           if (depth == 1)
                           {
                                  if (board.moveBuf[i].isCapture()) ICAPT++;
                                  if (board.moveBuf[i].isEnpassant()) IEP++;
                                  if (board.moveBuf[i].isPromotion()) IPROM++;
                                  if (board.moveBuf[i].isCastle()) ICASTLE++;
                           }
                     }
              }
              unmakeMove(board.moveBuf[i]);
       }
       return retVal;
}
