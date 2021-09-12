#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <sstream>
#define qu queue <int>
#define vc vector <int>
#define mci map <string,int>
#define mm(o) memset(o,0,sizeof(o))
#define op freopen("in.txt","r",stdin)
#define op1 freopen("out.txt","w",stdout)
#define N 10010

using namespace std;

void BFS(int s);


int n,e;
int d[N],c[N],p[N];

vector <int> v[N];

int main()
{

//    op;

    for(int i=0;i<=N;i++)
        v[i].clear();

    scanf("%d %d",&n,&e);

    for(int i=1;i<=e;i++)
      {
         int u,vv;
         scanf("%d %d",&u,&vv);

         v[u].push_back(vv);
         v[vv].push_back(u);
      }

     int source;
     scanf("%d",&source);

     BFS(source);

     for(int i=1;i<=n;i++)
     {
        printf("distance of %d from source %d is-- %d\n",i,source,d[i]);
     }

     return 0;
}

void BFS(int s)
{
    queue <int> q;

    memset(d,0,sizeof(d));
    memset(c,0,sizeof(c));
    memset(p,-1,sizeof(p));

    q.push(s);
    c[s]=1;

    while(!q.empty())
    {
       int x=q.front();
       int sz=v[x].size();

       for(int i=0;i<sz;i++)
       {
          int y=v[x][i];

          if(c[y]==0)
           {
               c[y] = 1;
               d[y]=d[x]+1;
               p[y]=x;

               q.push(y);
           }
       }
       q.pop();
    }
}
