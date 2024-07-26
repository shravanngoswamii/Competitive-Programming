include <stdio.h>

void main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", num1);

    printf("Enter the second number: ");
    scanf("%d", num2);

    // Check if the numbers are not integers
    if (num1 != (int)num1 || num2 != (int)num2) {
        printf("The numbers are not integers.\n");
    } else if (num1 == num2) {
        printf("The numbers are equal.\n");
    } else {
        printf("The numbers are not equal.\n");
    } // Exit successfully
}