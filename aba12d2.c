#include<stdio.h>
#include<math.h>

int p[1001]={0};

int prime(int n)
{
return p[n];
}

int main()
{
int t,k,j,ans=0,a,b;
float in;
int ini;

scanf("%d",&t);
p[2]=1;
p[3]=1;
p[4]=1;
p[5]=1;
p[8]=1;
p[17]=1;
p[27]=1;
p[41]=1;
p[49]=1;
p[59]=1;
p[64]=1;
p[71]=1;
p[89]=1;
p[101]=1;
p[125]=1;
p[131]=1;
p[167]=1;
p[169]=1;
p[173]=1;
p[256]=1;
p[289]=1;
p[293]=1;
p[383]=1;
p[512]=1;
p[529]=1;
p[677]=1;
p[701]=1;
p[729]=1;
p[743]=1;
p[761]=1;
p[773]=1;
p[827]=1;
p[839]=1;
p[841]=1;
p[857]=1;
p[911]=1;
for(k=0;k<t;k++)
	{
	scanf("%d %d",&a,&b);
	ans=0;
	in = sqrt(a);
	ini = sqrt(a);
	if(in!=ini)
		ini+=1;
	for(j=ini;j<=sqrt(b);j++)
		{
		ans+=prime(j);
		}
	if(a<=2)
		ans+=1;
	printf("%d\n",ans);
	}
return 0;
}
