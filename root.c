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