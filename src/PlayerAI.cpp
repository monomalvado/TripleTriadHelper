//
// Created by teufel on 8/29/2019.
//

#include "PlayerAI.h"

PlayerAI::PlayerAI(std::string name) : Player(std::move(name)), recordDepth(-1), bestSpace(-1), bestCard(-1) {}

void PlayerAI::makeMove(Board& board) {
    auto startTime = std::chrono::high_resolution_clock::now();

    int depth = Board::NUM_LOCATIONS - board.mineInPlay() - board.oppInPlay();
    std::cout << "Doing depth " << depth << " search..." << std::endl;

    /* Perform the search */
    recordDepth = depth;
    bestCard = bestSpace = -1;
    int ret = alphaBeta(depth, PlayerAI::MIN_BOUND, PlayerAI::MAX_BOUND, board);

    /* Print results */
    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stopTime-startTime).count();
    std::cout << "" << duration << " ms" << std::endl
              << "Evaluation = " << ret << std::endl
              << "Playing card " << board.fromMyHand(bestCard) << " to spot "
              << (bestSpace+1) << std::endl;
    board.play(bestCard, bestSpace);
}

int PlayerAI::alphaBeta(int depth, int alpha, int beta, Board board) {
    /* Evaluate at leaf nodes */
    if ( depth == 0)
        return evaluate(board);

    /* Alpha-beta search over all child nodes */
    int numInHand = board.mineInHand();
    for ( int onCard = 0; onCard < numInHand; onCard++ ) {
        for ( int onSpace = 0; onSpace < Board::NUM_LOCATIONS; onSpace++ ) {
            // Skip occupied spaces.
            if (!board.isEmpty(onSpace))
                continue;

            // Play card, advance the turn, perform depth-1 search as Other player
            // go back a turn and undo board state changes.
            board.play(onCard, onSpace);
            board.invert();
            int ret = -alphaBeta(depth-1, -beta, -alpha, board);
            board.invert();
            board.undo();

            if (ret >= beta)
                return ret;
            if ( ret > alpha ) {
                alpha = ret;
                if ( depth == recordDepth ) {
                    bestCard = onCard;
                    bestSpace = onSpace;
                }
            }
        }
    }

    return alpha;
}

int PlayerAI::evaluate(Board& board) {
    int meHand = board.mineInHand();
    int oppHand = board.oppInHand();

    int ret = (board.mineInPlay() + meHand) * 1000;
    ret -= (board.oppInPlay() + oppHand) * 1000;

    for (int i = 0; i < meHand; i++)
        ret += board.fromMyHand(i).getEdgeSum();
    for (int i = 0; i < oppHand; i++)
        ret -= board.fromOppHand(i).getEdgeSum();

    return ret;
}
