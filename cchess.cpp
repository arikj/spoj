#include <cstdio>
#include <queue>

using namespace std;

int visited[8][8][2];

struct P {
  int x, y;
  int c;
  int cost;
};

int bfs( P s, P t ) {
  queue< P > q;
  int min = 1000000000;
  q.push( s );
  while ( !q.empty() ) {
    s = q.front();
    q.pop();
    if ( s.x < 0 || s.x > 7 || s.y < 0 || s.y > 7 ) {
      continue;
    }


    if ( s.x == t.x && s.y == t.y ) {
	if(min>s.cost)
		min = s.cost;
	continue;  
    }

    if(visited[s.x][s.y][0]==1 && visited[s.x][s.y][1]<=s.cost)
                continue;
	
    visited[s.x][s.y][0] = 1;	
    visited[s.x][s.y][1] = s.cost;

    q.push( ( P ) { s.x + 1, s.y + 2, s.c + 1,s.cost+(s.x)*(s.x+1)+(s.y)*(s.y+2) } );
    q.push( ( P ) { s.x + 2, s.y + 1, s.c + 1,s.cost+(s.x)*(s.x+2)+(s.y)*(s.y+1) } );
    q.push( ( P ) { s.x + 2, s.y - 1, s.c + 1,s.cost+(s.x)*(s.x+2)+(s.y)*(s.y-1) } );
    q.push( ( P ) { s.x + 1, s.y - 2, s.c + 1,s.cost+(s.x)*(s.x+1)+(s.y)*(s.y-2) } );
    q.push( ( P ) { s.x - 1, s.y - 2, s.c + 1,s.cost+(s.x)*(s.x-1)+(s.y)*(s.y-2) } );
    q.push( ( P ) { s.x - 2, s.y - 1, s.c + 1,s.cost+(s.x)*(s.x-2)+(s.y)*(s.y-1) } );
    q.push( ( P ) { s.x - 2, s.y + 1, s.c + 1,s.cost+(s.x)*(s.x-2)+(s.y)*(s.y+1) } );
    q.push( ( P ) { s.x - 1, s.y + 2, s.c + 1,s.cost+(s.x)*(s.x-1)+(s.y)*(s.y+2) } );
  }
return min;
}

int main() {
  int a,b,c,d,i,j;

  while (scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF) {

  for(i=0;i<8;i++)
	for(j=0;j<8;j++)
		{
		visited[i][j][0] = 0;
		visited[i][j][1] = 0;
		}
	
    printf( "%d\n", bfs(
      ( P ) { a,b,0,0 },
      ( P ) { c,d,0,0 }
    ) );
  }

  return 0;
}
