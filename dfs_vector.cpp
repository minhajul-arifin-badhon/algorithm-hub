#include <iostream>
#include <cstdio>
#include <string.h>
#include <vector>
#define N 100010  //N will change based on your problem defination.

using namespace std;

void DFS(int s);

vector <int> v[N];
int n,e;
int color[N];
int dist[N];
int parent[N];


int main()
{
    scanf("%d %d",&n,&e);

    for(int i=1;i<=e;i++){
        int u,x;
        scanf("%d %d",&u,&x);
        v[u].push_back(x);
        v[x].push_back(u);
    }

    int source;
    scanf("%d",&source);


    memset(parent,-1,sizeof(parent));   // this will set -1 in every index of parent array.
    memset(color,0,sizeof(color));      // same type
    memset(dist,0,sizeof(dist));

    DFS(source);

    return 0;
}


void DFS(int s){

   cout<<s<<endl;   // this will print the sequence of visiting nodes.

   color[s]=1;
   int sz=v[s].size();

   for(int i=0;i<sz;i++){

      int x=v[s][i];

      if(color[x]==0){

         dist[x]=dist[s]+1;
         parent[x]=s;
         DFS(x);
      }
   }
}
