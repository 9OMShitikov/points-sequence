#include <iostream>
#include <stdio.h>
#include "points_sequence.h"

int main() {
    points_sequence seq;
    seq.read_points();
    seq.minimize_length();
    printf("%f\n", seq.get_length());
    return 0;
}