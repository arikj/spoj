#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
int t,i,j,k;
char str[10001],match[10001];
int count;
char *list[10001];
int len,flag;
scanf("%d",&t);
getc(stdin);
for(i=0;i<t;i++)
	{
	j=0;
	count=0;
	//scanf(" %[^\n]s",str);
	gets(str);
	while(j<strlen(str))
		{
		len=0;
		flag=0;
		while(str[j]!=' ' && j<strlen(str))
			{
			match[len]=str[j];
			j++;
			len++;
			}
		match[len]='\0';
		if(len>0)
			{
			for(k=0;k<count;k++)
				{
				if(strcmp(match,list[k])==0)
					{
					flag=1;
					break;
					}
				}

			if(flag==0)
				{
				list[count]=malloc(sizeof(char)*(len+1));
				strcpy(list[count],match);
				count++;
				}		
			}
		j++;
		}
	printf("%d\n",count);
	}

return 0;
}
