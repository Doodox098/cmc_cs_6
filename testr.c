#include "trsqr.h"

void testr(void){
    char key[10];
    while(1) {
        int first_function, second_function;
        printf("Testing function \"root\" choose the first test function\n");
        printf("-1 - x^2\n");
        printf("-2 - sqrt(2x)\n");
        printf("-3 - 8/x\n");
        while(1) {
            scanf("%s", key);
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
            scanf("%s", key);
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
                result = root(f1, f2, der_f1, der_f2, 1, 2, &num_culc, eps);
            }
            else{
                result = root(f1, f3,der_f1, der_f3, 2, 3, &num_culc, eps);
            }
        }
        else{
            result = root(f2, f3, der_f2, der_f3, 2, 4, &num_culc, eps);
        }
        printf("Result: %lf \n", result);
        printf("Number of calculation: %d \n", num_culc);
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
