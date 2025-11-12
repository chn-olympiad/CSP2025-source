/*
没有k个城市修建就是纯粹的MST
然后发现k很小，大不了暴力枚举那些点需要建设，那这样的话发现如果是prim算法nlogn
1e8左右，感觉跑过去了
但是我发现我不会prim，只能手搓一个nlogm的最小生成树算法
时间跑满大概是2e8？
猜他跑不满
神了
有个结论是一张图的MST可以拆成两部分边分别做MST，然后再把他们和起来
再看这题，发现其实因为要修改的点数不多，所以我们可以暴力存下来枚举点后选了哪些边，这样子就是稳定的nlogn了
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+15,maxe=1e6+5,inf=1e18;
int n,m,k,cnt,v[1030][maxn+10],fa[maxn+10],c[20],cntedge,tmp[maxn+10],cot[1030],ans=inf;
queue<int>q[maxn+10];
vector<int>E[maxn+10];
struct Edge{
    int x,y,w,id;
}e[maxe<<1],edge[maxe];
int rd(){
    int res=0,y=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') y=-y;ch=getchar();}
    while(isdigit(ch)) res=(res<<1)+(res<<3)+(ch&15),ch=getchar();
    return res*y;
}
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
bool cmp(Edge x,Edge y){return x.w<y.w;}
void Mst(int N,int s,int add){
    int nowres=0,now=0;
    for(int i=1;i<=n+k;i++) fa[i]=i;
    sort(edge+1,edge+1+cntedge,cmp);
    for(int i=1;i<=cntedge;i++){
        int x=edge[i].x,y=edge[i].y;
        // printf("%lld %lld\n",edge[i].x,edge[i].y,edge[i].w);
        x=get(x);y=get(y);
        if(x==y) continue;
        nowres+=edge[i].w;
        tmp[++now]=edge[i].id;
        fa[x]=y;
        if(now==N-1) break;
    }
    ans=min(ans,nowres+add);
    cot[s]=now;
    // puts("test:");
    for(int i=1;i<=now;i++) v[s][i]=tmp[i];//,printf("%lld ",tmp[i]);puts("");
    // printf("check:%lld %lld %lld %lld\n\n",s,N,now,nowres+add);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=rd();m=rd();k=rd();
    for(int i=1;i<=m;i++){
        cnt++;
        e[cnt].id=cnt;e[cnt].x=rd();e[cnt].y=rd();e[cnt].w=rd();
    }
    for(int i=1;i<=k;i++){
        c[i]=rd();
        for(int j=1;j<=n;j++){
            int w=rd();cnt++;
            e[cnt].id=cnt;e[cnt].x=n+i;e[cnt].y=j;e[cnt].w=w;
            E[i].push_back(cnt);
        }
    }
    for(int i=1;i<=m;i++) edge[++cntedge]=e[i];
    Mst(n,0,0);
    for(int s=1;s<(1<<k);s++){
        int pos=k,num=__builtin_popcount(s),sum=0;
        for(int i=k-1;i>=0;i--)
          if((s>>i)&1){pos=i;break;}
        for(int i=0;i<k;i++)
          if((s>>i)&1) sum+=c[i+1];
        cntedge=0;
        // printf("test:%lld %lld %lld\n",s,pos,(s^(1<<pos)));
        for(int i=cot[s^(1<<pos)];i;i--) edge[++cntedge]=e[v[s^(1<<pos)][i]];//,printf("%lld ",v[s^(1<<pos)][i]);
        for(int i:E[pos+1]) edge[++cntedge]=e[i];//,printf("%lld ",i);puts("");
        Mst(n+num,s,sum);
    }
    printf("%lld\n",ans);
    // printf("%.5lf\n",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}