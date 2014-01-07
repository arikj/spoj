#include<stdio.h>

int main()
{
int f,s,g,u,d;
int i,visited[1000001];
int stack[1000001],left=0,right=0,steps=0;
scanf("%d %d %d %d %d",&f,&s,&g,&u,&d);

if(s==g)
	printf("%d\n",0);

else{
for(i=1;i<=f;i++)
	visited[i]=-1;

stack[0]=s;
visited[s]=0;

while(left<=right)
	{
	if(stack[left]+u == g || stack[left]-d == g)
		{
		steps = visited[stack[left]]+1; 
		break;
		}

	if(stack[left]+u<=f && visited[stack[left]+u]==-1)
		{
		stack[right+1]=stack[left]+u;
		visited[stack[left]+u]=visited[stack[left]]+1;
		right++;
		}

	if(stack[left]-d>=1 && visited[stack[left]-d]==-1)
                {
                stack[right+1]=stack[left]-d;
		visited[stack[left]-d]=visited[stack[left]]+1;
                right++;
                }
	left++;
	}

if(steps>0)
	printf("%d\n",steps);

else
	printf("use the stairs\n");
}
return 0;
}
