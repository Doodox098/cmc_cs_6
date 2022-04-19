#include <stdio.h>
#include <string.h>
#include <math.h>
//-----------Main functions-----------//
double root(double (*f)(double x), double (*g)(double x), double a, double b, int *count, double eps1);
double integral(double (*f)(double x), double a, double b, double eps2){
    if(a > b){
        a += b;
        b = a - b;
        a -= b;
    }
    double integral_sum_n;
    double integral_sum_2n = 0;
    double step = (b - a);
    do{
        integral_sum_n = integral_sum_2n;
        integral_sum_2n = 0;
        for(double i = a; i < b; i += step){
            integral_sum_2n = integral_sum_2n + f(i + step / 2) * step;
        }
        step = step / 2;
    }while(integral_sum_2n - integral_sum_n > eps2);
    return integral_sum_2n;
}
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
    return sqrt(2 * x);
}
double f3(double x){
    return 8 / x;
}

int main(void){
    char key[10];
    while(1) {
        int function;
        printf("Testing function \"integral\" choose the first test function\n");
        printf("-1 - x^2\n");
        printf("-2 - sqrt(2x)\n");
        printf("-3 - 8/x\n");
        while(1) {
            gets(key);
            if (!strcmp(key, "-1")) {
                function = 1;
                break;
            } else if (!strcmp(key, "-2")) {
                function = 2;
                break;
            } else if (!strcmp(key, "-3")) {
                function = 3;
                break;
            } else {
                printf("Incorrect input\n");
            }
        }
        printf("Enter the ends of the segment:\n");
        double a, b;
        scanf("%lf%lf", &a, &b);
        printf("Enter accuracy of calculations(eps):\n");
        double eps;
        scanf("%lf", &eps);
        double result;
        if(function == 1)result = integral(f1, a, b, eps);
        else if(function == 2)result = integral(f2, a, b, eps);
        else result = integral(f3, a, b, eps);
        printf("Result: %f \n", result);
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