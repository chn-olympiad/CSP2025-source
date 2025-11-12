#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,m,k,ci[N],c[15],cnt;
long long ans;
struct node{
    int f,t;
    long long w;
}r[N];
bool cmp(node x,node y){
    return x.w<y.w;
}
int find(int x){
    if(ci[x]==x)return x;
    ci[x]=find(ci[x]);
    return ci[x];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1,x,y,v;i<=m;i++){
        scanf("%d%d%d",&x,&y,&v);
        r[i].f=x;
        r[i].t=y;
        r[i].w=v;
    }
    cnt=m;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1,v;j<=n;j++){
            scanf("%d",&v);
            r[++cnt].f=i+n;
            r[cnt].t=j;
            r[cnt].w=v;
        }
    }
    sort(r+1,r+1+cnt,cmp);
    for(int i=1;i<=n+k;i++){
        ci[i]=i;
    }
    for (int i = 1; i <=cnt; i++){
        int a=find(r[i].f),b=find(r[i].t);
        if(a!=b){
            ans+=r[i].w;
            //cout<<r[i].f<<" "<<r[i].t<<endl;
            ci[a]=b;
        }
    }
    cout<<ans;
    return 0;
}
