#include <stdio.h>
#include <string.h>
#include <math.h>
//-----------Main functions-----------//
double root(double (*f)(double x), double (*g)(double x), double a, double b, int *count, double eps1){
    int convexity = ((f(a) - g(a) + f(b)- g(b))/2 > (f((a - b)/2) - g((a - b)/2)))? 1: -1; //Jensen's inequality
    int monotony = (f(a) - g(a) > f(b)- g(b))? -1: 1;
    double c = a - (f(a)- g(a))/((f(b) - g(b) - f(a) + g(a))/(b - a));  // a - F(a)/k; k = (F(b)-F(a))/(b - a)
    if(convexity * monotony == 1){
        while((f(c) - g(c))*(f(c + eps1) - g(c + eps1)) > 0) {
            *count += 1;
            a = c;
            c = a - (f(a)- g(a))/((f(b) - g(b) - f(a) + g(a))/(b - a));
        }
    }
    else{
        while((f(c) - g(c))*(f(c - eps1) - g(c - eps1)) > 0) {
            *count += 1;
            b = c;
            c = a - (f(a)- g(a))/((f(b) - g(b) - f(a) + g(a))/(b - a));
        }
    }
    return c;
}
double integral(double (*f)(double x), double a, double b, double eps2);
//-----------Assembly functions-----------//
double func1(double x);
double func2(double x);
double func3(double x);
//-----------Testing functions-----------//
void testr(void);
void testi(void);
//-----------Testing examples-----------//
double f1(double x){
    return x * x;
}
double f2(double x){
    return sqrt(2.0 * x);
}
double f3(double x){
    return 8.0 / x;
}

int main(void){
    char key[10];
    while(1) {
        int first_function, second_function;
        printf("Testing function \"root\" choose the first test function\n");
        printf("-1 - x^2\n");
        printf("-2 - sqrt(2x)\n");
        printf("-3 - 8/x\n");
        while(1) {
            gets(key);
            if (!strcmp(key, "-1")) {
                first_function = 1;
                break;
            } else if (!strcmp(key, "-2")) {
                first_function = 2;
                break;
            } else if (!strcmp(key, "-3")) {
                first_function = 3;
                break;
            } else {
                printf("Incorrect input\n");
            }
        }
        printf("Choose the second test function\n");
        while(1){
            gets(key);
            if(!strcmp(key, "-1")) {
                second_function = 1;
                if(second_function == first_function){
                    printf("Choose another function\n");
                    continue;
                }
                break;
            }
            else if(!strcmp(key, "-2")){
                second_function = 2;
                if(second_function == first_function){
                    printf("Choose another function\n");
                    continue;
                }
                break;
            }
            else if(!strcmp(key, "-3")){
                second_function = 3;
                if(second_function == first_function){
                    printf("Choose another function\n");
                    continue;
                }
                break;
            }
            else{
                printf("Incorrect input\n");
            }
        }
        printf("Enter accuracy of calculations(eps):\n");
        double eps;
        int num_culc = 0;
        scanf("%lf", &eps);
        double result;
        if(first_function == 1 || second_function == 1){
            if(first_function == 2 || second_function == 2){
                result = root(f1, f2, 1, 2, &num_culc, eps);
            }
            else{
                result = root(f1, f3, 2, 3, &num_culc, eps);
            }
        }
        else{
            result = root(f2, f3, 2, 4, &num_culc, eps);
        }
        printf("Result: %lf \n", result);
        printf("Number of calculation: %d \n", num_culc);
        printf("-continue - Continue testing\n");
        printf("-end - Stop testing\n");
        gets(key);
        while(1){
            gets(key);
            if(!strcmp(key, "-continue")) {
                printf("Continue testing\n");
                break;
            }
            else if(!strcmp(key, "-end")){
                printf("Stop testing\n");
                break;
            }
            else{
                printf("Incorrect input\n");
            }
        }
        if(!strcmp(key, "-end")){
            break;
        }
    }
    return 0;
}
