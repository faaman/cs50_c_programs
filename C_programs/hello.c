#include <string.h>
#include <stdio.h>

int main(void)
{
    printf("hello, world\n");

    string answer = get_string("What is your name: ");

    printf("hello, %s", answer);
}