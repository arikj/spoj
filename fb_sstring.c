#include<stdio.h>
#include<string.h>
#include<math.h>

int n = 1009;

int main()
{
int len,ans=0,indx=0;
char str[101];
scanf("%s",str);

len = strlen(str);

ans = ans + ((int)(str[0]-'a')*(int)(pow(25,len-1)))%n;

while(indx<len)
	{
	printf("%d\n",indx);
	if(str[indx-1] == str[indx] && indx>0)
		{
		ans-=1;
                break;
		}
	len--;
	if(str[indx]-'a' >= str[indx+1]-'a')
		ans = ans +  ((int)(str[indx+1]-'a')*(int)(pow(25,len-1)))%n;
		
	else
		ans = ans +  (((int)(str[indx+1]-'a')-1)*(int)(pow(25,len-1)))%n;

	ans = ans%n;
	indx++;
	}
printf("%d\n",(ans+1)%n);

return 0;
}
