#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define DEBUG 1

int euclidean(unsigned int a, unsigned int b)
{
	/* Return the GCD of a,b using the Euclidean division algorithm */
	/* printf("DEBUG: a=%12d, b=%12d\n", a, b); */

	if(b == 0)
		return a;
	else if (a < b)
		return euclidean(b,a);
	else
		return euclidean(a-(a/b)*b,b);

}

double my_sqrt(double x)
{
	/* Use Newton-Raphson, because why not? */
	/* x_{n+1} = x_n - (x_n^2-x)/2x_n */
	/* x_0 = x (the radius of convergence is infinite on (0,infty), I think) */
	/* Aiming for a precision of 10**-12 */

	double y0, y1, precision=1E-10;

	y0 = 0;
	y1 =x;

	do {
		y0 = y1;
		y1 = y0 - (y0*y0 - x)/(2*y0);
	} while(fabs(y1-y0) > precision);

	return(y1);
}

int main(void)
{
	int i;
	unsigned int a,b;
	time_t t;
	int n = 0, iter = INT_MAX;
	double ratio;

	srand((unsigned) time(&t));
	for (i = 0; i < iter; i++)
	{
		a = rand(), b = rand();
		if(euclidean(a,b) == 1)
		{
			/* a,b are coprime - increment our counter */
			n++;
		}

#if DEBUG
		if((i+1)%(1<<20) == 0)
		{
			ratio = n/(double)(i+1);
			printf("MARK: %12d: %12d\n", i+1, n);
			printf("6/pi^2 ~= %lf\t pi^2 ~= %lf\t pi ~= %lf\n\n", ratio, 6.0/ratio, sqrt(6.0/ratio));
		}
#endif
	}
	ratio = n/(double)iter;

	printf("Total iterations: %12d\t Coprime pairs: %12d \n", iter, n);
	printf("Estimate of 6/pi^2: %lf\n", ratio);
	printf("Estimate of pi^2: %lf\n", 6/ratio);
	printf("Estimate of pi: %lf\n", sqrt(6/ratio));
	return EXIT_SUCCESS;
}
