#include "trsqr.h"

void testi(void){
    char key[10];
    while(1) {
        int function;
        printf("Testing function \"integral\" choose the first test function\n");
        printf("-1 - x^2\n");
        printf("-2 - sqrt(2x)\n");
        printf("-3 - 8/x\n");
        while(1) {
            scanf("%s", key);
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
        while(1){
            scanf("%s", key);
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
}
