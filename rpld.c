#include<stdio.h>
#include<stdlib.h>

int main()
{
int t,i,j,n,r,id,co,*st,temp,len,k,l,*ind,flag;
int **x;
scanf("%d",&t);

for(i=0;i<t;i++)
	{
	len=0;
	flag=0;
	scanf("%d %d",&n,&r);
	x=(int**)malloc(n*sizeof(int*));
	st=(int *)malloc(n*sizeof(int));
	ind=(int *)malloc(n*sizeof(int));

        scanf("%d %d",&id,&co);

	   x[len] = (int*)malloc(50000*sizeof(int));
           x[len][0]=co;
           ind[len]++;
       	st[len]=id;
           len++;
	
	
	for(j=0;j<r-1;j++)
		{
		scanf("%d %d",&id,&co);

		if(flag==1)
			continue;

		temp=0;
		for(k=0;k<len;k++)
			{
			if(st[k]==id)
				{
				
				for(l=0;l<ind[k];l++)
					{
					if(co==x[k][l])
						{
						printf("Scenario #%d: impossible\n",i+1);
						flag=1;
						break;
						}	
					}

				if(flag==1)
					break;

			
				else{
				x[k][ind[k]]=co;
				ind[k]++;
				temp=1;
				break;
				}
				}
			}

			if(flag==0 && temp==0)
				{
				x[len] = (int*)malloc(50000*sizeof(int));
				x[len][0]=co;
				ind[len]++;
				st[len]=id;				
				len++;
				}

			
//		for(k=0;k<len;k++)
//		for(l=0;l<ind[k];l++)
//		printf("%d ",x[k][l]);
				
		}
	if(flag==0)
		 printf("Scenario #%d: possible\n",i+1);
	
	for ( j = 0; j< n; j++) 
 	 free(x[j]);
	free(x);	
	}
return 0;
}
