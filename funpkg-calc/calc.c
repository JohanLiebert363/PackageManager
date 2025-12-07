#include <stdio.h>

int main() {
    double a, b;
    char op;

    printf("Calculator package\n");
    printf("Usage: number operator number\n");

    printf("> ");
    scanf("%lf %c %lf", &a, &op, &b);

    double result;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/':
            if (b == 0) {
                printf("Error: division by zero!\n");
                return 1;
            }
            result = a / b;
            break;
        default:
            printf("Unknown operator.\n");
            return 1;
    }

    printf("Result: %.2f\n", result);
    return 0;
}
