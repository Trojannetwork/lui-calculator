calculator.c

#include <stdio.h>

// Function to perform calculation
// Returns result, sets *error to 1 if error (e.g., invalid op or divide by zero), 0 otherwise
// error: 0 = OK, 1 = invalid op, 2 = divide by zero

double calculate(double num1, double num2, char op, int *error) {
    *error = 0;
    switch(op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0) {
                return num1 / num2;
            } else {
                *error = 2;
                return 0;
            }
        default:
            *error = 1;
            return 0;
    }
}

// Function to print result or error
void print_result(double result, int error) {
    if (error == 0) {
        printf("Result: %.2lf\n", result);
    } else if (error == 1) {
        printf("Invalid Operator\n");
    } else if (error == 2) {
        printf("Error: Cannot divide by zero.\n");
    }
}

int main(int argc, char *argv[]) {
    double num1, num2, result;
    char op;
    int error = 0;

    if (argc == 4) {
        // Command-line mode: ./calculator num1 op num2
        sscanf(argv[1], "%lf", &num1);
        op = argv[2][0];
        sscanf(argv[3], "%lf", &num2);
        result = calculate(num1, num2, op, &error);
        if (error == 0) {
            printf("%.2lf\n", result);
        } else if (error == 1) {
            printf("Invalid Operator\n");
        } else if (error == 2) {
            printf("Error: Cannot divide by zero.\n");
        }
        return 0;
    }

    int again = 1;
    char cont;

    while (again) {
        // INPUT
        printf("Enter NUM1: ");
        scanf("%lf", &num1);

        printf("Enter Operator (+, -, /, *): ");
        scanf(" %c", &op);

        printf("Enter NUM2: ");
        scanf("%lf", &num2);

        result = calculate(num1, num2, op, &error);
        print_result(result, error);

        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &cont);
        if (cont != 'y' && cont != 'Y') {
            again = 0;
        }
    }

    return 0;
}
