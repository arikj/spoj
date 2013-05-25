#include<stdio.h>

int main()
{
int i,j,n,s[101],t[101],x[101],y[101],z,paradox,done,temp[101],len;
char str[10];

scanf("%d",&n);

while(n!=0)
	{
	paradox=0;
	done=0;
	z=0;	
	for(i=1;i<=n;i++)
		{
		scanf("%d %s",&s[i],str);
		if(strcmp(str,"true")==0)
			t[i]=1;

		else
			t[i]=0;

		if(s[i]==i && t[i]==0)
			{
			z=1;
			break;
			}	
		}

	if(z==1)
		{
		printf("PARADOX\n");
		}

	else{
	for(i=1;i<=n;i++)
		{
		len=1;
		temp[len]=i;
		for(j=1;j<=n;j++)
			{
			x[j]=s[j]; y[j]=t[j];
			}
		done=0;
		while(paradox==0 && done==0)
			{
			for(j=1;j<=len;j++)
				{
				if(temp[j]==x[x[temp[len]]])
					{
					y[x[temp[len]]]=(y[x[temp[len]]]+1+y[temp[len]])%2;
					if(y[x[temp[len]]]==0)
						{paradox=1;break;}

					else
						{
						done=1;
						}
					}}
	
					
				if(done==0 && paradox==0){	
					
                                        temp[len+1]=x[temp[len]];}
					len++;
					
				}
			

		if(paradox==1)
			break;
		}
	if(paradox==1)
		printf("PARADOX\n");

	else	
		printf("NOT PARADOX\n");}
	scanf("%d",&n);
	}
return 0;
}
