#include<stdio.h>
#include<string.h>

int main()
{
int t,i,j;
char s[100000];
int count=0,onetime=1;;
char t[100000];
int len=1,k,nlen=0;
int done=0;

scanf("%d",&t);

for(i=0;i<t;i++)
	{
	count=0;
	scanf("%s",s);
	t[0]=s[0];	
	for(j=1;j<strlen(s);j++)
		{
		nlen=0;
		done=0;
		for(k=0;k<len;k++)
			{

			if(nlen==len)
				break;

			t[k+len]=s[j];
			if((s[j]!=t[k] || s[j+len]!=t[k]) && onetime==0)
				{
				done=1;
				break;
				}

			else if(s[j]!=t[k] && onetime==1)
				{
				done=1;
				break;
				}

			else
				{
				j++;	
				}
			nlen++;
			}

		if(done!=1)
			{
			count+=2;	
			}

		else
			len+=nlen;			
		}
	}
}
