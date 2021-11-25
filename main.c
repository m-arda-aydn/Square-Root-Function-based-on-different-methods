#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double a; // The number of which we want to square root, will be entered by user

// function_value calculates x^2-a value for given x and "a" parameters
double function_value( double x, double a){

    return x * x - a;

}

/* Newton_Raphson_Function calculates x_(i+1) using Newton-Raphson method, for f(x)=x^2-a and
   f'(x)=2*x, x_(i+1) = ((x_(i))^2+a)/(2*x_(i))*/
double Newton_Raphson_Function( double x, double a){

    return (x * x + a)/(2 * x);

}

// Interval_Search_Method implements Interval Search Method for given "a"
double Interval_Search_Method( double a )
{

    double step_size=a; // is the increment x value of f(x) after one loop
    double x1=0; // initial value of x on the interval
    double x2=a; // final value of x on the interval

    if( a < 0 ){
        // due to the definition of square root function, printing an error when user enters negative number
        printf("the value of a cannot be a negative number");
    }

    // if a>=0
    else{
        // if the difference between x1 and x2 are greater than or equal 0.0001, then while loop works
        while((x2-x1) >= 0.0001){
            // iterate 10 times because we have 10 sections
            for(int i=0; i<10; i++ ){
                step_size = (x2 - x1) / 10; // divide interval into 10 equal size sections

                /* test whether the sign of function value changes or not, using method below:
                   if the multiplication of consecutive x values is lesser than zero, then square root
                   of "a" lies between this consecutive range */
                if( function_value(x1,a) * function_value((x1+step_size),a) < 0 ){
                    x2 = x1 + step_size; /* final value of the range becomes (x1 + stepsize) because
                                            the sign of function value changes */
                    break; // breaks the loop

                    }
                x1 += step_size; // if the sign of function value does not change, then x1 increases by stepsize

            }

        }

        return x1; // returns x1 value as a square root of "a"


    }

}

// Newton_Raphson_Method implements Newton-Raphson Method for given "a"
double Newton_Raphson_Method( double a ){

    double temp,x2; // temp and final value of x on the interval
    double x1 = a; // initial value of x on the interval

    // due to the definition of square root function, printing an error when user enters negative number
    if( a < 0 ){
        printf("the value of a cannot be a negative number");
    }

    else{
        /* if the absolute value of (x1-temp) is greater than or equals 0.0001, then while loop works
           we use absolute value because temp value can be greater or lesser than x1 due to the nature
           of Newton-Raphson formula */
        while((x1-temp)>=0.0001 || (x1-temp)<-0.0001){

            temp = x1; // assigns x1 value to temp
            x2 = Newton_Raphson_Function(x1,a); // x2 value obtained by Newton-Raphson formula
            x1 = x2; // new x1 value equals x2

        }
        return x1; // returns x1 value as a square root of "a"

    }



}

// Calculates the square root of the first 100000 integer numbers, using two methods determined by given "c" character
void Calculate_sqrt_for_first_100000( char c ){

    if ( c == 'I'){
        // if letter is 'I', then calculation is based on Interval Search Method
        for(int i=1; i<100001; i++){
            Interval_Search_Method(i);

         }
    }
    else if ( c == 'N'){
        // if letter is 'N', then calculation is based on Newton-Raphson Method
        for( int i=1; i<100001; i++){

            Newton_Raphson_Method(i);
         }

    }
}


int main(){

    printf("Please enter a positive number: ");
    scanf("%lf", &a); // user enters the value of "a"

    // Part 1:
    printf("Square root of a is (by using Interval Search Method): %lf\n", Interval_Search_Method(a));

    // Part 2:
    printf("Square root of a is (by using Newton-Raphson Method): %lf\n", Newton_Raphson_Method(a));

    // Part 3:
    clock_t t1,t2; // t1 and t2 are defined

    int executionTime; // we will use this parameter to compare these two methods

    t1 = clock();
    Calculate_sqrt_for_first_100000('I'); /* Calculates the square root of the first 100000 integer numbers using
                                             Interval Search Method */
    t2 = clock();

    executionTime = (int)(t2-t1); // the result is casted to integer
    printf("Execution time for interval search method: %d \n", executionTime);

    t1 = clock();
    Calculate_sqrt_for_first_100000('N'); /* Calculates the square root of the first 100000 integer numbers using
                                             Newton-Raphson Method */
    t2 = clock();

    executionTime = (int)(t2-t1); // the result is casted to integer
    printf("Execution time for Newton-Raphson method: %d ", executionTime);

  return 0;
}

