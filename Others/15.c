// Pointers practice

#include <stdio.h>

// Printing x
int f(int x) {
    return printf("%d\n", x);
}

// Changing value of value by address, so we have access to it's new value in main
int c(int *x) {
    printf("%d\n", *x);
    *x = 451;
    return *x;
}


int main() {

    char name[] = "Bill";
    char *p;
    int *q;

    p = name;

    // Printing a value stored by address in a memory(point to a pointer)
    printf("%c\n", *p);

    // Printing value, addressed by 'name' in memory (p = address to variable 'name')
    printf("%s\n", p);

    int n;
    n = 151;
    f(n);
    c(&n);  // in c func *x = &n; so *x is a pointer to address, where n lives
    printf("After C(): %d\n", n);
}
