# include <stdio.h>

int main(){
   long int i, num, j;
   num = 20;
   j = num;

   for (i=1; j > 1; j = j -1) {
         i=i*j;
   }

   printf("The factorial of %ld is %ld\n",num,i);
}
