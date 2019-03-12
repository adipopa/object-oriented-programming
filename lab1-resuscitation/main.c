#include <stdio.h>

int main() {
    // Read a message from the console and print it back to the user.
    char messageToQuarters[128];
    printf("Message to quarters: ");
    scanf("%[^\n]s", messageToQuarters);
    printf("%s", messageToQuarters);
    return 0;
}