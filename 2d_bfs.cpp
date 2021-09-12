#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <string.h>
#include <math.h>
#include <stack>
#include <sstream>
#include <queue>
#include <time.h>
#define qu queue <int>
#define vc vector <int>
#define pii pair <string,int>
#define mcc map <string,string>
#define mcc map <string,string>
#define fin freopen("in.txt","r",stdin)
#define fout freopen("out.txt","w",stdout)
#define mm(o,oo) memset(o,oo,sizeof(o))
#define at int tt; scanf("%d",&tt); for(int t=1;t<=tt;t++)
#define    rep(i,L,R) 	     for (int i = L; i <= R; i++)
#define    repop(i,L,R) 	     for (int i = L; i >= R; i--)
#define    get1(a) 	         scanf("%d", &a)
#define    get2(a,b) 	     scanf("%d%d", &a, &b)
#define    get3(a,b,c)       scanf("%d%d%d", &a, &b, &c)
#define    get4(a,b,c,d)     scanf("%d%d%d%d", &a, &b, &c ,&d)
#define    getL(a)           scanf("%I64d",&a)
#define    getLL(a,b)        scanf("%I64d%I64d",&a,&b)
#define    getLLL(a,b,c)     scanf("%I64d%I64d%I64d",&a,&b,&c)
#define    getC(n)           scanf("%c",&n)
#define    getF(n)           scanf("%lf",&n)
#define    getS(n)           scanf("%s",n)
#define LL long long
#define MD 10000007

using namespace std;

struct cor
{
    int x;
    int y;
    int dist;
};

void BFS();

int c[110][110];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
cor a, b;

int main()
{
//    fin;

    at
    {
        get2(a.x, a.y);
        get2(b.x, b.y);

        mm(c, 0);

        BFS();

        cout<<b.dist<<endl;
    }

    return 0;
}

void BFS()
{
    a.dist=0;
    queue <cor> q;
    q.push(a);
    c[a.x][a.y]=1;

    while(!q.empty())
    {
        cor h,w;
        h=q.front();

        if(h.x==b.x && h.y==b.y)
        {
            b.dist=h.dist;
            break;
        }

        for(int i=0;i<4;i++)
        {
            int X=h.x+dx[i];
            int Y=h.y+dy[i];

            if(X>0 && X<=1000 && Y>0 && Y<=1000 && c[X][Y]==0)
            {
                c[X][Y]=1;
                w.x=X;
                w.y=Y;
                w.dist = h.dist + 1;
                q.push(w);
            }
        }

        q.pop();
    }
}

