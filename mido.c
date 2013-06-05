#include<stdio.h>


void print(int x)
{
if(x/10 == 0)
	printf("0%d",x);

else
	printf("%d",x);
}


int main()
{
int i,n,min,sec,st_min=0,st_sec=0,x,goal1=0,goal2=0,prevmin=0,prevsec=0,lead1min=0,lead1sec=0,lead2min=0,lead2sec=0;
char time[10];

scanf("%d",&n);

for(i=0;i<n;i++)
	{
	scanf("%d %s",&x,time);

	min = (time[0]-'0')*10 + time[1]-'0';
	sec = (time[3]-'0')*10 + time[4]-'0';

	st_min=min;
	st_sec=sec;
	if(sec<prevsec)
		{
		sec = 60+sec-prevsec;
		min=min-prevmin-1;
		}

	else
		{
		sec = sec-prevsec;
                min=min-prevmin;

		}
	if(goal2>goal1)
		{
		if(sec+lead2sec >=60)
			{
			lead2sec=sec+lead2sec-60;
			lead2min=min+lead2min+1;
			}	

		else
			{
			  lead2sec=sec+lead2sec;
                        lead2min=min+lead2min;
			}
		}

	if(goal1>goal2)
                {
                if(sec+lead1sec >=60)
                        {
                        lead1sec=sec+lead1sec-60;
                        lead1min=min+lead1min+1;
                        }
                
                else
                        {
                          lead1sec=sec+lead1sec;
                        lead1min=min+lead1min;
                        }
                }

	if(x==1)
		goal1++;

	else
		goal2++;
	
	prevsec = st_sec;
	prevmin = st_min;
		
	}

if(goal1!=goal2)
	{
	
         
	 sec = 60-prevsec;
	if(sec==60)
	{
         min=48-prevmin;
	sec=0;
	}

	else
		min = 47-prevmin;


        if(goal2>goal1)
                {
                if(sec+lead2sec >=60)
                        {
                        lead2sec=sec+lead2sec-60;
                        lead2min=min+lead2min+1;
                        }

                else
                        {
                          lead2sec=sec+lead2sec;
                        lead2min=min+lead2min;
                        }
                }


	if(goal1>goal2)
                {
                if(sec+lead1sec >=60)
                        {
                        lead1sec=sec+lead1sec-60;
                        lead1min=min+lead1min+1;
                        }

                else
                        {
                          lead1sec=sec+lead1sec;
                        lead1min=min+lead1min;
                        }
                }


	}

print(lead1min);
printf(":");
print(lead1sec);
printf("\n");
print(lead2min);
printf(":");
print(lead2sec);
printf("\n");
return 0;

}
