#include<stdio.h>


long int gcd(long int a,long int b)
{
    if(b>a)
    return gcd(b,a);
    if(b==0)
    return a;
    return gcd(b,a%b);
}

long int lcm(long int a,long int b)
{
    long int k=gcd(a,b);
    a/=k;
    return a*b;
}



int main()
{
int k,i,t,len,j,left,flag,right,neg[5],x,y,z;
long int n,m,a,d,new[5],res,num,val;

scanf("%d",&t);

for(k=0;k<t;k++)
	{
	len=0;
	scanf("%ld %ld %ld %ld",&n,&m,&a,&d);
	new[0]=a;
	new[1]=new[0]+d;
	new[2]=new[1]+d;
	new[3]=new[2]+d;
	new[4]=new[3]+d;
	left=0;
	right=0;
	num=m-n+1;
	res=num;
	flag=0;
	for(i=0;i<5;i++)
                {
                if(new[i]==-1)
                        continue;

                for(j=i+1;j<5;j++)
                        {
                        if(new[j]!=-1 && new[j]%new[i]==0)
                                new[j]=-1;      
                        }               
                }

        
        for(i=0;i<5;i++)
                {
                if(new[i]!=-1)
                        {
                        len+=1;
                        if(right-left>0)
                                {
                                new[neg[left]]=new[i];
                                new[i]=-1;
                                left++; 
                                }               
                        }

                else    
                        {
                        right++;
                        neg[right-1]=i;
                        }
                        
                }

	for(i=1;i<=len;i++)
		{
		if(i==1)
			{
			for(j=0;j<len;j++)
				{res-=num/new[j];if(n%new[j]==0)res-=1; if(m%new[j]==0) {res-=1;}}
			}

		else if(i==2)
			{
			for(j=0;j<len-1;j++)
				{
				for(x=j+1;x<len;x++)
					{
				
					val = lcm(new[j],new[x]);	
					if(val>num)
                                continue;

					res+=num/val;
					if(n%val==0)res+=1;if( m%val==0) res+=1;
					}
    				}
			}

		else if(i==3)
			{
			for(j=0;j<len-2;j++)
				{
				for(x=j+1;x<len-1;x++)
					{
					for(y=x+1;y<len;y++)
						{
						val=new[j];
						if(val>num)
                                continue;

						val=lcm(val,new[x]);
						if(val>num)
                                continue;

						val=lcm(val,new[y]);
						if(val>num)
                                continue;

						res-=num/val;
						if(n%val==0)res-=1;if( m%val==0) res-=1;
						}
					}
				}
			}
	
		else if(i==4)
			{
			for(j=0;j<len-3;j++)
                                {
                                for(x=j+1;x<len-2;x++)
                                        {
                                        for(y=x+1;y<len-1;y++)
                                                {
						for(z=y+1;z<len;z++){
                                                val=new[z];
						if(val>num)
                                continue;

                                                val=lcm(val,new[y]);
						if(val>num)
                                continue;

                                                val=lcm(val,new[x]);
						if(val>num)
                                continue;

                                                val=lcm(val,new[j]);

						if(val>num)

		                                continue;

						if(n%val==0)res+=1;if( m%val==0) res+=1;
						}
                                                }
                                        }
                                }

			}
	
		else if(i==5)
			{
			val=new[4];
			if(val>num)
				continue;
                        val=lcm(val,new[3]);
			if(val>num)
                                continue;

                        val=lcm(val,new[2]);
			if(val>num)
                                continue;

                        val=lcm(val,new[1]);
			if(val>num)
                                continue;

			val=lcm(val,new[0]);
			if(val>num)
                                continue;

                        res-=num/val;
			if(n%val==0)res-=1;if( m%val==0) res-=1;
			}	
		}	
	printf("%ld\n",res);	
	}
return 0;
}
