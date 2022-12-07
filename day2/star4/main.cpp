#include <stdlib.h>
#include <stdio.h>

int abc2point(char letter) { return (int)letter - (int)'`'; }
int xyz2point(char letter) { return (int)letter - (int)'w'; }

int gamePoints(char move1, char move2) {
    int num1 = abc2point(move1);
    int num2 = xyz2point(move2);
    int winningPoints = 0;
    if ( num1 == 1 && num2 == 3 ) { winningPoints = 0; }
    else if ( num1 == 3 && num2 == 1 ) { winningPoints = 6; }
    else if ( num1 < num2 ) {
        winningPoints = 6;
    } else if ( num1 == num2 ) { winningPoints = 3; }
    return winningPoints + num2;
}

char getPointsFromResult(char move1, char result) {

    switch(result) {
        // you lose
        case('x'): {
            int movenum = abc2point(move1);
            if ( movenum == 1 ) { return 3; }
            return movenum - 1;
            break;
        }
        // you draw
        case('y'): {
            return 3 + abc2point(move1);
            break;
        }
        // you win
        case('z'): {
            int movenum = abc2point(move1);
            if ( movenum == 3 ) { return 6+1; }
            return 6+movenum+1;
            break;
        }
        default: {
            return 0;
            break;
        }
    }

}

char lower(char c) {
    if ( (int)c < 91 && (int)c > 64 ) { return (char)((int)c + 32); }
    return c;
}

int main() {
    FILE * fptr = fopen("input.txt", "r");
    if ( fptr == NULL ) { return -1; }
    int total_points = 0;
    while ( !feof(fptr) ) {
        char strbuf[6];
        fgets(strbuf, sizeof(strbuf), fptr);
        total_points += getPointsFromResult(lower(strbuf[0]), lower(strbuf[2]));
    }
    printf("%i", total_points);
    return 0;
}