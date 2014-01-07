#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
if(a>b)
	return a;
else
	return b;
}
int lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];
   int i, j;
  
   /* Following steps build L[m+1][n+1] in bottom up fashion. Note 
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (i=0; i<=m; i++)
   {
     for (j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
    
   /* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] */
   return L[m][n];
}

int main()
{
int x,len1,len2;
char s[1000], t[1000];
scanf("%s",s);
while(strcmp(s,"#")!=0)
	{
	scanf("%s",t);
	len1 = strlen(s);
	len2 = strlen(t);
	x = lcs(s,t,len1,len2);
	x = (len1 - x)*15 + (len2 - x)*30;
	printf("%d\n",x);
	scanf("%s",s);
	}
return 0;
}
