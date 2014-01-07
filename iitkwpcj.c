#include<stdio.h>
#include<string.h>

void repeat(char str[],int n,char *new)
	{
	int i,j,k,ind=0,flag;
	
	for(i=1;i<n;i++)
		{
		k=i;
		flag=0;
		for(j=0;j<=ind;j++)
			{
			if(str[j]!=str[k])
				{
				ind=i;
				flag=1;
				break;
				}
			k++;
			}

		if(flag==0)
			i=k-1;
				
		}

	for(i=0;i<=ind;i++)
		new[i]=str[i];

	new[i]='\0';
	}

int main()
	{
	int t,i,n1,n2;
	char str1[100001],str2[100001],rep1[100001],rep2[100001];

	scanf("%d",&t);

	for(i=0;i<t;i++)
		{
		scanf("%s",str1);
		scanf("%s",str2);
		n1=strlen(str1);
		n2=strlen(str2);

		repeat(str1,n1,rep1);
		repeat(str2,n2,rep2);

		if(strcmp(rep1,rep2)==0)
			printf("YES\n");

		else
			printf("NO\n");
		}
	return 0;
	}
