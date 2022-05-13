#ifndef TASK_6_TRSQR_H
#define TASK_6_TRSQR_H
#include <stdio.h>
#include <string.h>
#include <math.h>
//-----------Main functions-----------//
double root(double (*f)(double x), double (*g)(double x), double (*df)(double x), double (*dg)(double x), double a, double b, int *count, double eps1);
double integral(double (*f)(double x), double a, double b, double eps2);
//-----------Assembly functions-----------//
extern double func1(double x);
extern double func2(double x);
extern double func3(double x);
//-----------Assembly derivative functions--------//
extern double der_func1(double x);
extern double der_func2(double x);
extern double der_func3(double x);
//-----------Testing functions-----------//
void testr(void);
void testi(void);
//-----------Testing examples-----------//
double f1(double x);
double f2(double x);
double f3(double x);
double der_f1(double x);
double der_f2(double x);
double der_f3(double x);
#endif //TASK_6_TRSQR_H
