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
double der_f1(double x){
    return 2 * x;
}
double der_f2(double x){
    return 1 / sqrt(2 * x);
}
double der_f3(double x){
    return - 8 / (x * x);
}

int main(int argc, char *argv[]){
    double eps1 = 0.0001, eps2 = 0.0001;
    int count = 0;
    double sum;
    double points[3];
    printf("Calculation started\n");
    // Calculating points of intersection
    points[0] = root(func1, func2, der_func1, der_func2, 1.7, 2.2, &count, eps1);
    printf("Point 1 calculated\n");
    points[1] = root(func2, func3, der_func2, der_func3, 0, 0.5, &count, eps1);
    printf("Point 2 calculated\n");
    points[2] = root(func3, func1, der_func3, der_func1, -0.26, 0.32, &count, eps1);
    printf("Point 3 calculated\n");
    printf("Points calculated\n");
    double integrals[3];
    // Calculating Riemann integrals on segments between points of intersection
    integrals[0] = integral(func1, points[0], points[2],  eps2);
    integrals[1] = integral(func2, points[0], points[1],  eps2);
    integrals[2] = integral(func3, points[1], points[2],  eps2);
    // Searching for a greatest integal, and calculate square ov curved triangle by substracting two another
    if(integrals[1] + integrals[2] <= integrals[0]) sum = integrals[0] - (integrals[1] + integrals[2]);
    else if(integrals[0] + integrals[2] <= integrals[1]) sum = integrals[1] - (integrals[0] + integrals[2]);
    else sum = integrals[2] - (integrals[0] + integrals[1]);
    printf("Square calculated\n");
    if(argc == 1){
        printf("Square of curved triangle: %lf\n", sum);    	
    }
    	for(int i = 1; i<argc; i++){
    	if(!strcmp(argv[i], "-help")){
    	    printf("-help       - Information about available commands\n");
    	    printf("-points     - List of intersection points\n");
    	    printf("-sqr        - Square of curved triangle\n");
    	    printf("-count      - Number of iterations to calculate each point of intersection\n");
    	    printf("-testr      - Test \"root\" function\n");
    	    printf("-testi      - Test \"integral\" function\n");
    	}
    	else if(!strcmp(argv[i], "-points")){
    	    printf("Point 1: x: %lf y: %lf\n", points[0], func1(points[0]));
    	    printf("Point 2: x: %lf y: %lf\n", points[1], func2(points[1]));
    	    printf("Point 3: x: %lf y: %lf\n", points[2], func3(points[2]));
    	}
    	else if(!strcmp(argv[i], "-count")){
    	    printf("Number of calculations: %d\n", count);
    	}
    	else if(!strcmp(argv[i], "-sqr")){
    	    printf("Square of curved triangle: %lf\n", sum);
    	}
    	else if(!strcmp(argv[i], "-testr")){
    	    testr();
    	}
    	else if(!strcmp(argv[i], "-testi")){
    	    testi();
    	}
    	else{
        	printf("No such command\n");
    	}
    }
    return 0;
}
