double integral(double (*f)(double x), double a, double b, double eps2){
// Searching for approximate value of Riemann integral using rectangle method
    if(a > b){
    	// Make sure that upper limit is greater than lower or swap them in another case
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
            // Calculating next integral sum with step devided by 2
            integral_sum_2n = integral_sum_2n + f(i + step / 2) * step;
        }
        step = step / 2; // Devide step by 2
    }while(integral_sum_2n - integral_sum_n > eps2);
    return integral_sum_2n;
}
