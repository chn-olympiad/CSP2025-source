#include<bits/stdc++.h>
#define int long long
#define MAXN 20000
#define MAXM 2000000
using namespace std;
struct Town{
    int cost,weight[MAXN];
};
struct edge{
    int u,v,weight,t=0;
    bool operator<(edge x){
        return weight<x.weight;
    }
};
int n,m,k,choose[16],fa[MAXN];
Town town[16];
edge e[MAXM];
int find(int self){
    if(fa[self]==self){
        return self;
    }
    return fa[self]=find(fa[self]);
}
void merge(int x,int y){
    fa[find(x)]=find(y);
}
void init(){
    for(int i=1;i<=n+k;i++){
        fa[i]=i;
    }
}
int solve(int TownCount){
    init();
    int MST_size=1,MST=0,CostSum=0;
    for(int i=1;i<=m+n*k;i++){
        if(choose[e[i].t]){
            if(find(e[i].u)!=find(e[i].v)){
                MST_size++;
                MST+=e[i].weight;
                merge(e[i].u,e[i].v);
            }
        }
        if(MST_size==n+TownCount){
            for(int j=1;j<=k;j++){
                CostSum+=town[j].cost*choose[j];
            }
            return MST+CostSum;
        }
    }
    return LONG_LONG_MAX;
}
int dfs(int cur,int TownCount){
    if(cur==k+1){
        return solve(TownCount);
    }
    int x1,x2;
    x1=dfs(cur+1,TownCount);
    choose[cur]=1;
    x2=dfs(cur+1,TownCount+1);
    choose[cur]=0;
    return min(x1,x2);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].weight);
    }
    for(int i=1;i<=k;i++){
        cin>>town[i].cost;
        for(int j=1;j<=n;j++){
            scanf("%lld",&town[i].weight[j]);
            e[m+(i-1)*n+j]={n+i,j,town[i].weight[j],i};
        }
    }
    sort(&e[1],&e[m+n*k+1]);
    if(n==1){
        cout<<0;
    }else{
        choose[0]=1;
        cout<<dfs(1,0);
    }
    return 0;
}