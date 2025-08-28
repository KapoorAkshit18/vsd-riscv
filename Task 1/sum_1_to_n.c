#include<stdio.h>

int main() {
	 int i, sum=0, n=150;

	for (i=1; i<=n; ++i) {            

	sum+=i;       //equivalent to sum = sum + i
}
	printf("Sum of numbers from 1 to %d is %d\n",n, sum);
	
	return 0;
}
