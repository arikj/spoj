#include<stdio.h>
#include<string.h>
#include<math.h>


int main()
{
int len,n=1009;
char str[101];
scanf("%s",str);

len= strlen(str);
int size=len;
int indx=0,ans=0;

ans=(ans+ (int)((str[0]-'a')*pow(25,len-1)))%n;
indx++;
len--;
int flag=0;
while(indx<size && flag==0)
{
		

	if(str[indx-1]-'a' >= str[indx]-'a')
		ans = (ans+(int)((str[indx]-'a')*pow(25,len-1)))%n;

	else
		ans = (ans+(int)((str[indx]-'a' - 1)*pow(25,len-1)))%n;	
		
	if(str[indx-1] == str[indx])
		flag=1;
	
	indx++;
	len--;
	}

if(flag==0)
	ans=ans+1;
printf("%d\n",ans);
return 0;
}
