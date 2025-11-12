#include<bits/stdc++.h>
using namespace std;
const int N=1e4+4,M=11,K=1.1e6+6;
struct Edge{
    int u,v,w;
    bool operator<(Edge b){
        return w<b.w;
    }
}e[K];
int c[M],a[M][N];
int n,m,k;
int fa[N];
int getroot(int x){
    return fa[x]==x?fa[x]:fa[x]=getroot(fa[x]);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    for(int i=1;i<=n;i++)fa[i]=i;
    if(k==0){
        sort(e+1,e+m+1);
        int sum=0;
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(getroot(u)==getroot(v))continue;
            fa[getroot(u)]=getroot(v);
            sum+=w;
        }
        cout<<sum<<endl;
        return 0;
    }
    bool A=true;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i])A=false;
        bool flag=false;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0)flag=true;
        }
        if(!flag)A=false;
    }
    if(A){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                if(a[i][j]==0){
                    for(int l=1;l<=n;l++){
                        e[++m]={j,l,a[i][l]};
                    }
                }
            }
        }
        sort(e+1,e+m+1);
        int sum=0;
        for(int i=1;i<=m;i++){
            int u=e[i].u,v=e[i].v,w=e[i].w;
            if(getroot(u)==getroot(v))continue;
            fa[getroot(u)]=getroot(v);
            sum+=w;
        }
        cout<<sum<<endl;
        return 0;
    }
}