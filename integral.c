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