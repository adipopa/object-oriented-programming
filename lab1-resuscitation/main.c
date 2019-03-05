#include <stdio.h>

int main() {
    char messageToQuarters[128];
    printf("Your message to quarters: ");
    scanf("%[^\n]s", messageToQuarters);
    printf("%s", messageToQuarters);
    return 0;
}