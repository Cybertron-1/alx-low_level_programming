#include <stdio.h>

void first(void);

/**
 * pre_main - prints a sentence before the main function is executed
 */
void pre_main(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}

int main(void)
{
    pre_main(); // Call the function manually before the main function
    // Rest of the main function
    return 0;
}
