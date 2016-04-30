/* Version 0.0
** From "Wayne's Little DSA Library" (DSA == Data Structures and
** Algorithms) Feel free to change, modify, or burn these sources, but if
** you modify them please don't distribute your changes without a clear
** indication that you've done so.  If you think your change is spiffy,
** send it to me and maybe I'll include it in the next release.
**
** Wayne Hayes, wayne@csri.utoronto.ca (preffered), or wayne@csri.toronto.edu
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <memory.h>
#include <sys/time.h>   /*getrusage doesn't seem to work.*/
#include <sys/resource.h>
#include <unistd.h>
/*#include <../ucbinclude/sys/rusage.h>*/

#include "misc.h"

const foint ABSTRACT_ERROR = {(1 << (8*sizeof(void*)-1))};

static FILE *tty;

void Warning(const char *fmt, ...)
{
    va_list ap;
    fflush(stdout);
    fprintf(stderr, "Warning: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fprintf(stderr, "\n");
#if 0
    if(!isatty(fileno(stderr)))
    {
	if(!tty)
	    if(!(tty = fopen("/dev/tty", "w")))
		return;
	fprintf(tty, "Warning: ");
	va_start(ap, fmt);
	vfprintf(tty, fmt, ap);
	va_end(ap);
	fprintf(tty, "\n");
    }
#endif
}

void Apology(const char *fmt, ...)
{
    va_list ap;
    fflush(stdout);
    fprintf(stderr, "Sorry, fatal limitation: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    if(!isatty(fileno(stderr)))
    {
	if(!tty)
	    tty = fopen("/dev/tty", "w");
	fprintf(tty, "Sorry, fatal limitation: ");
	va_start(ap, fmt);
	vfprintf(tty, fmt, ap);
	va_end(ap);
	fprintf(tty, "\n");
    }
    assert(false);
    exit(1);
}

void Fatal(const char *fmt, ...)
{
    va_list ap;
    fflush(stdout);
    fprintf(stderr, "Fatal Error: ");
    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    if(!isatty(fileno(stderr)))
    {
	if(!tty)
	    tty = fopen("/dev/tty", "w");
	fprintf(tty, "Fatal Error: ");
	va_start(ap, fmt);
	vfprintf(tty, fmt, ap);
	va_end(ap);
	fprintf(tty, "\n");
    }
    fflush(stdout);
    fflush(stderr);
    fflush(tty);
//    getchar();
    assert(false);
    exit(1);
}

/* A malloc that exits if system calloc fails.
*/
void *Malloc(int n)
{
    void *p;
    assert(n>=0);
    p = (void*)malloc(n);
    if(!p && n)
	Fatal("malloc failed");
    return p;
}
void *Calloc(int n, int m)
{
    void *p;
    assert(n>=0 && m>=0);
    p = (void*)calloc(n, m);
    if(!p && n && m)
	Fatal("calloc failed");
    return p;
}

void *Realloc(void *ptr, int newSize)
{
    void *p;
    assert(newSize>=0);
    p = (void*) realloc(ptr, newSize);
    if(!p)
	Fatal("realloc failed");
    return p;
}

void *Memdup(void *v, int n)
{
    void *r = Malloc(n);
    memcpy(r, v, n);
    return r;
}


/* return current user time used in seconds */
double uTime(void)
{
#if 1
	struct rusage rUsage;
	getrusage(RUSAGE_SELF, &rUsage);
	return rUsage.ru_utime.tv_sec + 1e-6*rUsage.ru_utime.tv_usec;
#else
	return -1;
#endif
}

char *Int2BitString(char word[33], unsigned i)
{
    int b, k = 0;
    assert(sizeof(unsigned) == 4);
    for(b=31; b >= 0; b--)
	word[k++] = '0' + !!(i & (1<<b));
    word[k] = '\0';
    return word;
}


void PrintArray(FILE *fp, int n, int *array)
{
    int i;
    if(!n)
	return;
    for(i=0; i<n; i++)
	fprintf(fp, "%d ", array[i]);
    fprintf(fp, "\n");
}

long long IIntPow(int a, int n)
{
    long long result;
    assert(n >= 0);
    if(n == 1)
	return a;
    if(n == 0)
	return a == 0 ? 0/0 : 1;

    result = IIntPow(a, n/2);
    if(n & 1)
	return a * result * result;
    else
	return result * result;
}


double IntPow(double a, int n)
{
    double result;
    if(n == 1)
	return a;
    if(n == 0)
	return a == 0.0 ? 0/0 : 1;
    if(n < 0)
	return 1/IntPow(a,-n);

    result = IntPow(a, n/2);
    if(n & 1)
	return a * result * result;
    else
	return result * result;
}


int Log2(int n)
{
    int log2 = 0;
    assert(n != 0);
    while((n /= 2))
	++log2;
    return log2;
}


/* Greatest Common Divisor */
int gcd(int a, int b)
{
    assert(a>=0 && b>=0);
    until(b==0)
    {
	int t = a%b;
	a=b;
	b=t;
    }
    return a;
}


int IsPrime(long long n)
{
    int s=sqrt(n)+1, i;
    if(n<2) return 0;
    if(n==2 || ((n&1) && n<9)) return 1;
    if(n % 2 == 0) return 0;
    for(i=3; i<=s; i+=2)
	if(n%i==0)
	    return 0;
    return 1;
}

int PrimeFactors(int N, int count[])
{
    int n=N, p, s=n/2, total=0, prod=1;
    if(IsPrime(n))
	return 1;
    for(p=0; p<=s; p++)
    {
	count[p] = 0;
	if(IsPrime(p))
	{
	    while(n%p==0)
	    {
		prod *= p;
		total++;
		count[p]++;
		n /= p;
	    }
	}
    }
    assert(prod == N);
    return total;
}
