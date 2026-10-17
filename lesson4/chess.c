#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMPTY '.'

char board[8][8] = {
    {'r','n','b','q','k','b','n','r'},
    {'p','p','p','p','p','p','p','p'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'.','.','.','.','.','.','.','.'},
    {'P','P','P','P','P','P','P','P'},
    {'R','N','B','Q','K','B','N','R'}
};

int whiteTurn = 1;

void printBoard(void) {
    int r, c;

    printf("\n    a b c d e f g h\n");
    printf("  +-----------------+\n");

    for (r = 0; r < 8; r++) {
        printf("%d | ", 8 - r);

        for (c = 0; c < 8; c++) {
            printf("%c ", board[r][c]);
        }

        printf("| %d\n", 8 - r);
    }

    printf("  +-----------------+\n");
    printf("    a b c d e f g h\n\n");
}

int isWhite(char p) {
    return p >= 'A' && p <= 'Z';
}

int isBlack(char p) {
    return p >= 'a' && p <= 'z';
}

int sameColor(char a, char b) {
    if (a == EMPTY || b == EMPTY)
        return 0;

    return (isWhite(a) && isWhite(b)) ||
           (isBlack(a) && isBlack(b));
}

int inside(int r, int c) {
    return r >= 0 && r < 8 && c >= 0 && c < 8;
}

int pathClear(int r1, int c1, int r2, int c2) {
    int dr = 0, dc = 0;
    int r, c;

    if (r2 > r1) dr = 1;
    if (r2 < r1) dr = -1;
    if (c2 > c1) dc = 1;
    if (c2 < c1) dc = -1;

    r = r1 + dr;
    c = c1 + dc;

    while (r != r2 || c != c2) {
        if (board[r][c] != EMPTY)
            return 0;

        r += dr;
        c += dc;
    }

    return 1;
}

int validMove(int r1, int c1, int r2, int c2) {
    char p;
    int dr, dc, adr, adc;

    if (!inside(r1,c1) || !inside(r2,c2))
        return 0;

    p = board[r1][c1];

    if (p == EMPTY)
        return 0;

    if (sameColor(board[r1][c1], board[r2][c2]))
        return 0;

    dr = r2 - r1;
    dc = c2 - c1;
    adr = abs(dr);
    adc = abs(dc);

    /* Pawn */
    if (p == 'P') {
        if (dc == 0 && dr == -1 && board[r2][c2] == EMPTY)
            return 1;

        if (dc == 0 && dr == -2 && r1 == 6 &&
            board[5][c1] == EMPTY &&
            board[4][c1] == EMPTY)
            return 1;

        if (adr == 1 && dr == -1 && board[r2][c2] != EMPTY &&
            isBlack(board[r2][c2]))
            return 1;

        return 0;
    }

    if (p == 'p') {
        if (dc == 0 && dr == 1 && board[r2][c2] == EMPTY)
            return 1;

        if (dc == 0 && dr == 2 && r1 == 1 &&
            board[2][c1] == EMPTY &&
            board[3][c1] == EMPTY)
            return 1;

        if (adc == 1 && dr == 1 && board[r2][c2] != EMPTY &&
            isWhite(board[r2][c2]))
            return 1;

        return 0;
    }

    /* Knight */
    if (p == 'N' || p == 'n') {
        return (adr == 2 && adc == 1) ||
               (adr == 1 && adc == 2);
    }

    /* Bishop */
    if (p == 'B' || p == 'b') {
        if (adr != adc)
            return 0;

        return pathClear(r1,c1,r2,c2);
    }

    /* Rook */
    if (p == 'R' || p == 'r') {
        if (dr != 0 && dc != 0)
            return 0;

        return pathClear(r1,c1,r2,c2);
    }

    /* Queen */
    if (p == 'Q' || p == 'q') {
        if (dr == 0 || dc == 0 || adr == adc)
            return pathClear(r1,c1,r2,c2);

        return 0;
    }

    /* King */
    if (p == 'K' || p == 'k') {
        return adr <= 1 && adc <= 1;
    }

    return 0;
}

void promotePawn(int r, int c) {
    char choice;

    if (board[r][c] == 'P' && r == 0) {
        printf("White pawn promotion (Q/R/B/N): ");
        scanf(" %c", &choice);
        choice = (char)toupper(choice);

        if (choice != 'Q' && choice != 'R' &&
            choice != 'B' && choice != 'N')
            choice = 'Q';

        board[r][c] = choice;
    }

    if (board[r][c] == 'p' && r == 7) {
        printf("Black pawn promotion (q/r/b/n): ");
        scanf(" %c", &choice);
        choice = (char)tolower(choice);

        if (choice != 'q' && choice != 'r' &&
            choice != 'b' && choice != 'n')
            choice = 'q';

        board[r][c] = choice;
    }
}

int findKing(int white, int *kr, int *kc) {
    int r, c;
    char king = white ? 'K' : 'k';

    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) {
            if (board[r][c] == king) {
                *kr = r;
                *kc = c;
                return 1;
            }
        }
    }

    return 0;
}

int isInCheck(int white) {
    int kr, kc;
    int r, c;

    if (!findKing(white, &kr, &kc))
        return 1;

    for (r = 0; r < 8; r++) {
        for (c = 0; c < 8; c++) {
            char p = board[r][c];

            if (p == EMPTY)
                continue;

            if (white && isBlack(p)) {
                if (validMove(r,c,kr,kc))
                    return 1;
            }

            if (!white && isWhite(p)) {
                if (validMove(r,c,kr,kc))
                    return 1;
            }
        }
    }

    return 0;
}

void makeMove(int r1, int c1, int r2, int c2) {
    board[r2][c2] = board[r1][c1];
    board[r1][c1] = EMPTY;

    promotePawn(r2,c2);
}

void undoMove(int r1, int c1, int r2, int c2, char captured) {
    board[r1][c1] = board[r2][c2];
    board[r2][c2] = captured;
}

int legalMove(int r1, int c1, int r2, int c2, int white) {
    char captured;

    if (!validMove(r1,c1,r2,c2))
        return 0;

    if (white && !isWhite(board[r1][c1]))
        return 0;

    if (!white && !isBlack(board[r1][c1]))
        return 0;

    captured = board[r2][c2];

    makeMove(r1,c1,r2,c2);

    if (isInCheck(white)) {
        undoMove(r1,c1,r2,c2,captured);
        return 0;
    }

    undoMove(r1,c1,r2,c2,captured);

    return 1;
}

int hasLegalMove(int white) {
    int r1,c1,r2,c2;

    for (r1 = 0; r1 < 8; r1++) {
        for (c1 = 0; c1 < 8; c1++) {

            if (board[r1][c1] == EMPTY)
                continue;

            if (white && !isWhite(board[r1][c1]))
                continue;

            if (!white && !isBlack(board[r1][c1]))
                continue;

            for (r2 = 0; r2 < 8; r2++) {
                for (c2 = 0; c2 < 8; c2++) {

                    if (legalMove(r1,c1,r2,c2,white))
                        return 1;
                }
            }
        }
    }

    return 0;
}

int parseSquare(char file, char rank, int *r, int *c) {
    file = (char)tolower(file);

    if (file < 'a' || file > 'h')
        return 0;

    if (rank < '1' || rank > '8')
        return 0;

    *c = file - 'a';
    *r = 8 - (rank - '0');

    return 1;
}

int main(void) {
    char input[100];
    int r1,c1,r2,c2;

    printf("=================================\n");
    printf("          MINI C CHESS\n");
    printf("=================================\n");
    printf("White: A-Z   Black: a-z\n");
    printf("Example move: e2 e4\n");
    printf("Type 'quit' to exit.\n");

    while (1) {
        printBoard();

        if (isInCheck(whiteTurn)) {
            printf("CHECK! ");
        }

        printf("%s turn: ",
               whiteTurn ? "White" : "Black");

        if (!fgets(input, sizeof(input), stdin))
            break;

        if (strncmp(input, "quit", 4) == 0)
            break;

        if (strlen(input) < 5) {
            printf("Invalid input! Example: e2 e4\n");
            continue;
        }

        if (!parseSquare(input[0], input[1], &r1, &c1) ||
            !parseSquare(input[3], input[4], &r2, &c2)) {

            printf("Invalid move format! Example: e2 e4\n");
            continue;
        }

        if (!legalMove(r1,c1,r2,c2,whiteTurn)) {
            printf("Illegal move!\n");
            continue;
        }

        makeMove(r1,c1,r2,c2);

        whiteTurn = !whiteTurn;

        if (!hasLegalMove(whiteTurn)) {
            printBoard();

            if (isInCheck(whiteTurn)) {
                printf("CHECKMATE! %s wins!\n",
                       whiteTurn ? "Black" : "White");
            } else {
                printf("STALEMATE! Draw.\n");
            }

            break;
        }
    }

    printf("Game over.\n");

    return 0;
}