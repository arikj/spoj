#include<stdio.h>

int main()
{
int s,p,t,i,j;
int n[100000],x=0;
int res_n=0,res_p=0;
int f_n=0,f_p=0;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	res_n=0;res_p=0;f_n=0;f_p=0;x=0;
	scanf("%d %d",&s,&p);
	for(j=0;j<s;j++)	
		scanf("%d",&n[j]);

	for(j=0;j<s;j++){
		if(res_p+n[j]<=p)
			{
			res_p+=n[j];
			res_n+=1;
			}

		else
			{
			while(res_p+n[j]>p)
				{
				res_p-=n[x];
				res_n-=1;
				x++;
				}
			res_p+=n[j];
			res_n+=1;	
			}

		if((f_n<res_n) || (f_n==res_n && f_p>res_p))
			{
			f_n = res_n;
			f_p = res_p;	
			}
		}

	printf("%d %d\n",f_p,f_n);
	}
return 0;
}
