#include<stdio.h>                       // standard input output header which have printf scanf etc 
int main() {                            // function named main with a return type integer
  
	int i, sum=0, n=100;                     // initializing the variable for count, and addition and the range n

	for (i=1; i<=n; ++i) {                    // loop till sum of n nos. is achieved

	sum+=i;                                    // compound assignment or single step shortcut
}
	printf("Sum of numbers from 1 to %d is %d\n",n, sum);           
  
	return 0;                                    // program is finished OS
}
