#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
#define N 100

using namespace std;

void pathPrint(int s);
void bfs(int s);

int n,e,adj[N][N];
int color[N];
int dist[N];
int parent[N];

int main()
{

//    freopen("in.txt","r",stdin);

    scanf("%d %d",&n,&e);

    memset(adj,0,sizeof(adj));

    for(int i=1;i<=e;i++){

        int u,x;
        scanf("%d %d",&u,&x);
        adj[u][x]=1;
        adj[x][u]=1;
    }

    int source;
    scanf("%d",&source);

    bfs(source);

    cout<<"Distance of nodes from source: "<<endl;

    for(int i=1;i<=n;i++){

       cout<<endl;
       cout<<"distance of "<<i<<" from "<<source<<"  : "<<dist[i]<<endl;
       cout<<"Shortest Path: ";
       pathPrint(i);
       cout<<endl;
    }

    return 0;
}


void bfs(int s){

    memset(parent,-1,sizeof(parent));
    memset(color,0,sizeof(color));
    memset(dist,0,sizeof(dist));

    color[s]=1;
    queue <int> q;
    q.push(s);

    while(!q.empty()){

        int x=q.front();
        q.pop();

        for(int i=1;i<=n;i++){

           if(adj[x][i]==1 && color[i]==0){

              color[i]=1;
              dist[i]=dist[x]+1;
              parent[i]=x;

              q.push(i);
           }
        }
    }
}


void pathPrint(int s){

   if(parent[s]==-1){
      cout<<s<<" ";
      return;
   }

   pathPrint(parent[s]);

   cout<<s<<" ";
}
