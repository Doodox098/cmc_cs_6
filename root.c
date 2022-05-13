double root(double (*f)(double x), double (*g)(double x), double (*df)(double x), double (*dg)(double x), double a, double b, int *count, double eps1){
    #if RT == 1 //If during preprocessing RT = 1, we use the chord method (default)
    *count += 1;
    int convexity = ((f(a) - g(a) + f(b)- g(b))/2 > (f((a - b)/2) - g((a - b)/2)))? 1: -1; //Jensen's inequality
    int monotony = (f(a) - g(a) > f(b)- g(b))? -1: 1;//Compairing the ends of segment
    double c = a - (f(a)- g(a))/((f(b) - g(b) - f(a) + g(a))/(b - a));  // a - F(a)/k; k = (F(b)-F(a))/(b - a)
    if(convexity * monotony == 1){
        while((f(c) - g(c))*(f(c + eps1) - g(c + eps1)) > 0) { //Searching answer by going from left to right
            *count += 1;
            a = c;
            c = a - (f(a)- g(a))/((f(b) - g(b) - f(a) + g(a))/(b - a));
        }
    }
    else{
        while((f(c) - g(c))*(f(c - eps1) - g(c - eps1)) > 0) { //Searching answer by going from right to left
            *count += 1;
            b = c;
            c = a - (f(a)- g(a))/((f(b) - g(b) - f(a) + g(a))/(b - a));
        }
    }
    return c;
}
    #else //If during preprocessing RT = 0, we use tangent method
    *count += 1;
    int convexity = ((f(a) - g(a) + f(b)- g(b))/2 > (f((a - b)/2) - g((a - b)/2)))? 1: -1; //Jensen's inequality
    int monotony = (f(a) - g(a) > f(b)- g(b))? -1: 1;//Compairing the ends of segment
    if(convexity * monotony == 1){
        while((f(b) - g(b))*(f(b + eps1) - g(b + eps1)) > 0) { //Searching answer by going from left to right
            *count += 1;
            b = b - (f(b) - g(b))/(df(b) - dg(b));
        }
        return b;
    }
    else{
        while((f(a) - g(a))*(f(a - eps1) - g(a - eps1)) > 0) { //Searching answer by going from right to left
            *count += 1;
            a = a - (f(a) - g(a))/(df(a) - dg(a));
        }
        return a;
    }
}
    #endif
