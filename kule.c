#include<stdio.h>
#include<string.h>

int l1,l2,r1,r2,k,sign;


void printans(int n)
{
fflush(stdout);
if(sign==1)
	{
	printf("ANSWER %d\n",n);
	}

else
	printf("ANSWER -%d\n",n);
fflush(stdout);
}


void print()
{
int i;
fflush(stdout);
printf("WEIGHT %d ",k);
for(i=l1;i<=r1;i++)
    printf("%d ",i);

for(i=l2;i<r2;i++)
	printf("%d ",i);	
       
printf("%d\n",r2);
fflush(stdout);
}

int main()
{
int n,i,done=0,left,right;
char str[10];
sign = -1;
scanf("%d",&n);
fflush(stdout);
left=1;right=n;
k=n;

while(done==0)
	{

	if(n==2)
		{
		if(left>=2)
			{
			left-=1;
			}

		else
			{
			right+=1;
			}

		n=3;
		continue;
		}

	k = n/3;
	l1 = left;
	r1 = left + k-1;
	l2 = left + k;
	r2 = left + 2*k-1;

	print();

	scanf("%s",str);
	fflush(stdout);
	if(strcmp(str,"LEFT")==0)
		{
		if(sign==-1){
		l2 = left + 2*k;
		r2 = left + 3*k-1;
		print();
		scanf("%s",str);	
		fflush(stdout);
		if(strcmp(str,"LEFT")==0)
			{
			sign=1;
			right = r1;
			}

        	else
                	{
			sign=0;
			right = left + 2*k-1;
			left = left + k;
                	}
		}

		else if(sign==1)
			{
			left=l1;right=r1;
		
			}	

		else
			{
			left=l2;right=r2;
			}
			
		}

	else if(strcmp(str,"RIGHT")==0)
		{
		if(sign==-1){
		l1 = left + k;
		r1 = left + 2*k-1;
                l2 = left + 2*k;
                r2 = left + 3*k-1;
                print();
                scanf("%s",str);
		fflush(stdout);
              	if(strcmp(str,"LEFT")==0)
                        {
                        sign=1;
			left = l1;
                        right = r1;
                        }

                else
                        {
                        sign=0;
          
                        right = left + k-1;
                        }
		}

		else if(sign==1)
			{
			left=l2;right=r2;	
			}

		else
			{
			left=l1;right=r1;
			}
		
		}

	else
		{
                l2 = left + 2*k;
                r2 = left + 3*k-1;
                print();
                scanf("%s",str);
		fflush(stdout);
		if(strcmp(str,"LEFT")==0)
			{
			sign=0;
			left = l2;
			right= r2;
			
			}

		else if(strcmp(str,"RIGHT")==0)
			{
			sign=1;
			left=l2;
			right=r2;
			}

		else
			{
			if(n%3==1)
				{
				l1 = left;
				r1 = left;
				l2 = r2+1;
				r2= l2;
				print();
				scanf("%s",str);fflush(stdout);
	                	if(strcmp(str,"LEFT")==0)
        	                	{
					sign=0;
					printans(l2);
        	                	}
	
                		else if(strcmp(str,"RIGHT")==0)
                        		{
					sign=1;
					printans(l2);
                        		}

				done=1; 
				}


			else if(n%3==2)
				{
				left = r2;
				right = r2 + 2;	
				n = 9;
				}	
			}	
		}
	if(left == right)
		{
		printans(left);
		done=1;
		}
	n = n/3;	
	
	}
return 0;
}
