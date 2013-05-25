#include<stdio.h>

int w[9000];

int check(int n,int e)
{
int i;

for(i=0;i<n;i++)
	{
	if(w[i]!=e)
		return 0;
	}
return 1;

}

int main()
{
int i,j,n,sum,each,res,ch;
float left[9000],right[9000];

scanf("%d",&n);

while(n!=-1)
	{
	sum=0;
	for(i=0;i<n;i++)
		{
		scanf("%d",&w[i]);
		sum+=w[i];		
		}
	
	if(sum%n!=0)
		printf("-1\n");

	else
		{
		each = sum/n;
		res=0;
		ch=0;		
		while(ch==0)
			{
				right[0]=0;
                                left[n-1]=0;
                                for(i=1;i<n;i++)
                                        {
                                         right[i]=right[i-1]+w[i-1];
                                        }

                                for(i=n-2;i>=0;i--)
                                        {
                                        left[i]=left[i+1]+w[i+1];
                                        }

                                for(i=1;i<n;i++)
                                        {
                                        right[i]=right[i]/i;
                                        }

                                for(i=0;i<n-1;i++)
                                        {
                                        left[i]=left[i]/(n-1-i);
                                        }
                                ch = check(n,each);
                                if(ch==1)
					break;

				for(j=0;j<n;j++){
				if(j==0)
					{
					if(left[j]<each)
						{
						w[j]-=1;
						w[j+1]+=1;
						}
					}

				else if(j==n-1)
					{
					if(right[j]<each)
                                                {
                                                w[j]-=1;
                                                w[j+1]+=1;
                                                }
                                       

					}

				else
					{
					if(left[j]<each)
						{
						w[j]-=1;
						w[j+1]+=1;
						}

					if(right[j]<each)
						{
						w[j]-=1;
						w[j-1]+=1;
						}

					}

				}

			res++;
			}
		printf("%d\n",res);

		}
		scanf("%d",&n);
	}
return 0;
}
