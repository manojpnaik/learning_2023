#include <stdio.h> 

int main()
{
 int i, j, k, m;
 for(i=5; i>=1; i--)
 {
  for(j=1; j<=i; j++){
   printf("%d",j);
  }
  for(k=i; k<5; k++){
   printf("  ");
  }
  for(m=i; m>=1; m--){
   printf("%d",m);
  }
  printf("\n");
 }
 return 0;
}
