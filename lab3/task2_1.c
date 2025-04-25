#include <stdio.h>
#include <stdlib.h>

union MyUnion {
    int i;
    float f;
};

int main() {
    union MyUnion *u;

    u->i = 5;
    printf("int: %d\n", u->i);
    u->f = 3.5;
    printf("float: %f\n", u->f);

    return EXIT_SUCCESS;
}