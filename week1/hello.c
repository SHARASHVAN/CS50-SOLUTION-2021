#include <stdio.h>
#include <cs50.h> //To declare the identifier
int main(void)
{
    string name = get_string("What's your name? "); //To ask the name of user
    printf("hello, %s\n", name); // To say hello to the user
}