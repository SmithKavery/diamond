#include <iostream>
using namespace std;

/*
    HOW THE RECURSION WORKS
    ------------------------
    We use ONE recursive function: printDiamond()

    Parameters:
        row  – the current row number (starting from 0 down to 11)
        max  – the total number of upper rows (11 for this shape)

    The recursion prints:
        1) The top half of the diamond while row <= max
        2) Then unwinds and prints the bottom half on the return path

    On the way DOWN the recursion tree (row increasing):
        → prints decreasing outer stars
        → prints increasing inner stars

    On the way BACK UP (row decreasing):
        → prints the bottom half in reverse

    Because each half is printed on opposite sides of the recursion,
    the output is symmetrical automatically.
*/

// prints N copies of a character
void printChars(int n, char c) {
    for (int i = 0; i < n; i++) cout << c;
}

// recursive diamond row printer
void printDiamond(int row, int maxRow) {
    if (row > maxRow) return;  // BASE CASE

    // ----- TOP HALF (forward recursion direction) -----
    int leftStars  = 25 - row;
    int innerStars = 1 + (row * 2);

    printChars(leftStars, '*');
    printChars(row, ' ');
    printChars(innerStars, '*');
    printChars(row, ' ');
    printChars(leftStars, '*');
    cout << endl;

    // RECURSIVE CALL (go down)
    printDiamond(row + 1, maxRow);

    // ----- BOTTOM HALF (reverse recursion direction) -----
    if (row < maxRow) { // avoid printing the middle line twice
        printChars(leftStars, '*');
        printChars(row, ' ');
        printChars(innerStars, '*');
        printChars(row, ' ');
        printChars(leftStars, '*');
        cout << endl;
    }
}

int main() {
    // print the top solid row
    printChars(25 * 2 + 1, '*');
    cout << endl;

    // print rows 0 through 11 recursively
    printDiamond(0, 11);

    // print the bottom solid row
    printChars(25 * 2 + 1, '*');
    cout << endl;

    return 0;
}
