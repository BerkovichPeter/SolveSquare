//! @file main.c
//!
//! @mainpage
//!
//! - main.c

#include <stdio.h>
#include <math.h>
#include <assert.h>

#define NOROOTS -1
#define INF 8
//! int ComparisonTo0(a, b , accuracity)
//! \param[in] a
//! \param[in] b
//! \param[in] accuracity
//! \return accuracity

const double accuracity = 0.0001;

char Comparison(double a, double b, double accuracity){
    if (fabs (a-b) < accuracity)
        return 1;
    return 0;

}

//! int Solution (double a, double b, double c, double* x1, double* x2)
//!
//! \param[in] a - A * x^2
//! \param[in] b - B * x
//! \param[in] c - C
//! \param[out] x1 - root #1
//! \param[out] x2 - root #2
//! \return - num of roots
//! \Note : return 8 - infinity, return -1 - 0 roots, return 1 - 1 root, return 2 - 2 roots

int Solution (double a, double b, double c, double* x1, double* x2) {
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x2 != x1);
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));


    if (Comparison(a,0,accuracity)) {
        if (Comparison(b,0,accuracity)) {
            if (Comparison(c,0,accuracity)) {
                return INF;
            } else {
                return NOROOTS;
            }
        } else {
            *x1 = -b / (2 * a);
            return 1;
        }
    } else {
        double d;
        d = (b * b - 4 * a * c);
        if (d < 0) {
            return NOROOTS;
        } else {
            d = sqrt(d);
            if ( Comparison(d,0,accuracity)) {
                *x1 = -b / (2 * a);
                return 1;
            } else {
                *x1 = (-b + d) / (2 * a);
                *x2 = (-b - d) / (2 * a);
                return 2;
            }
        }
    }
}

//! main()
//! Solution  of quadratic equation
//! Gain 3 koef. of equation : A, B, C
//! Give out number of roots and their value

int main(){
    double a = 0, b = 0, c = 0;
    double x1;
    double x2;
    int result;


    scanf("%lg %lg %lg", &a, &b, &c);

    result = Solution(a, b, c, &x1, &x2);
    switch (result){
        case INF:
            printf("infinity");
            break;
        case NOROOTS:
            printf("nope");
            break;
        case 1:
            printf("x = %lg", x1);
            break;
        case 2:
            printf("x1 = %lg , x2 = %lg", x1, x2);
            break;
        default:
            return 1;
    }
    return 0;
}