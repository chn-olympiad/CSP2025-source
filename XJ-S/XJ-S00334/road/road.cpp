#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e6+16;
int fa[MAXN],n,k,m,ans;
int find(int x){
    if(x!=fa[x])return fa[x]=find(fa[x]);
    else return x;
}
struct node{
    int a,b,c;
}d[MAXN],q[MAXN];
int t,h,xz[MAXN],f[MAXN],size[MAXN];
void sovle(){
    for(int i=1;;i++){
        node tmp={0,0,MAXN};
        bool flag=1;
        int w;
        for(int i=1;i<=t;i++){
            if(i>m&&q[i].c+xz[q[i].a]<tmp.c&&f[i]==0)
            {
                tmp=q[i];
                w=i;
                flag=0;
            }
            else if(i<=m&&q[i].c<tmp.c&&f[i]==0)
            {
                tmp=q[i];
                w=i;
            }
        }
        tmp=q[i];
        if(tmp.c==MAXN)break;
        f[w]=1;
        int x=find(tmp.a),y=find(tmp.b);
        if(x!=y){
            fa[x]=y;
            size[x]+=size[y],size[y]=size[x];
            ans+=tmp.c;
            if(flag==0)ans+=xz[tmp.a],xz[tmp.a]=0;
            if(size[x]==n)break;
        }
    }
    cout<<ans;
    return ;
}
int main(){
    freopen("road.in","r",stdin); 
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    for(int i=1;i<=n;i++)size[i]=1;
    for(int i=1;i<=m;i++){
        cin>>d[i].a>>d[i].b>>d[i].c;
        q[++t]=d[i];
    }
    for(int i=m+1,idx;i<=k+m;i++){
        cin>>xz[i];
        for(int j=1,x;j<=n;j++){
            cin>>x;
            q[++t]={i,j,x};
        }
    }
    sovle();
    return 0;
}