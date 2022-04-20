#include "trsqr.h"

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
    double eps1 = 0.001, eps2 = 0.001;
    int count = 0;
    double sum;
    double points[3];
    printf("Calculation started\n");
    points[0] = root(func1, func2, 1.7, 2.2, &count, eps1);
    printf("Point 1 calculated\n");
    points[1] = root(func2, func3, 0, 0.5, &count, eps1);
    printf("Point 2 calculated\n");
    points[2] = root(func3, func1, -0.26, 0.32, &count, eps1);
    printf("Point 3 calculated\n");
    printf("Points calculated\n");
    double integrals[3];
    integrals[0] = integral(func1, points[0], points[2],  eps2);
    integrals[1] = integral(func2, points[0], points[1],  eps2);
    integrals[2] = integral(func3, points[1], points[2],  eps2);
    if(integrals[1] + integrals[2] <= integrals[0]) sum = integrals[0] - (integrals[1] + integrals[2]);
    else if(integrals[0] + integrals[2] <= integrals[1]) sum = integrals[1] - (integrals[0] + integrals[2]);
    else sum = integrals[2] - (integrals[0] + integrals[1]);
    printf("Square calculated\n");
    printf("Write \"-help\" to get list of commands\n");
    char key[10];
    while(1){
        gets(key);
        if(!strcmp(key, "-help")){
            printf("-help - Information about available commands\n");
            printf("-points - List of intersection points\n");
            printf("-sqr - Square of curved triangle\n");
            printf("-count - Number of iterations to calculate each point of intersection\n");
            printf("-testr - Test \"root\" function\n");
            printf("-testi - Test \"integral\" function\n");
            printf("-exit - Terminate the program\n");
        }
        else if(!strcmp(key, "-exit")){
            break;
        }
        else if(!strcmp(key, "-points")){
            printf("Point 1: x: %lf y: %lf\n", points[0], func1(points[0]));
            printf("Point 2: x: %lf y: %lf\n", points[1], func2(points[1]));
            printf("Point 3: x: %lf y: %lf\n", points[2], func3(points[2]));
        }
        else if(!strcmp(key, "-count")){
            printf("Number of calculations: %d\n", count);
        }
        else if(!strcmp(key, "-sqr")){
            printf("Square of curved triangle: %lf\n", sum);
        }
        else if(!strcmp(key, "-testr")){
            testr();
            printf("Write \"-help\" to get list of commands\n");
        }
        else if(!strcmp(key, "-testi")){
            testi();
            printf("Write \"-help\" to get list of commands\n");
        }
        else{
            printf("No such command\n");
        }
    }
    return 0;
}
