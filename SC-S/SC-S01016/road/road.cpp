#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=1e4+5,M=1.2e6+5,K=15,MXED=1.1e5+5;
struct edge{
    int u,v,w;
    bool operator < (edge o)const{return w<o.w;}
}e[M],ne[N],vi[K][N];
int mx[N],f[N],tot[K];
int n,m,k;
int find(int i){
    return f[i]==i?i:f[i]=find(f[i]);
}
int c[K];
int calc(int x){
    memset(tot,0,sizeof(tot));
    for(int i=1;i<=n+k;i++)f[i]=i;
    int ans=0;
    int num=0,lst=1,tx=n;
    priority_queue<pii,vector<pii>,greater<pii> >Q;
    Q.push({ne[1].w,0});
    for(int i=0;i<k;i++)if(x&(1<<i)){
    	tx++;
        Q.push({vi[i+1][1].w,i+1});
        tot[i+1]=1;
    }
    int cnt=tx;
    while(!Q.empty()){
        auto t=Q.top();int y=t.second;Q.pop();
        if(y==0){
        	int u=ne[lst].u,v=ne[lst].v,w=ne[lst].w;
        	int ra=find(u),rb=find(v);
        	if(ra!=rb)f[ra]=rb,ans+=w,cnt--;
        	lst++;
            if(lst<n)Q.push({ne[lst].w,0});
        }else{
        	int u=vi[y][tot[y]].u,v=vi[y][tot[y]].v,w=vi[y][tot[y]].w;
        	int ra=find(u),rb=find(v);
        	if(ra!=rb)f[ra]=rb,ans+=w,cnt--;
            tot[y]++;
            if(tot[y]<=n)Q.push({vi[y][tot[y]].w,y});
        }
        if(cnt==1)return ans;
    }
    return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            int x;cin>>x;
            vi[i][j]={i+n,j,x};
        }
        sort(vi[i]+1,vi[i]+n+1);
    }
    sort(e+1,e+m+1);
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v,w=e[i].w;
        int ra=find(u),rb=find(v);
        if(ra==rb)continue;
        f[ra]=rb,ans+=w;
        ne[++cnt]={u,v,w};
    }
    for(int i=1;i<(1<<k);i++){
        int tot=calc(i);
        for(int j=0;j<k;j++)if(i&(1<<j))tot+=c[j+1];
        ans=min(ans,tot);
    }
    cout<<ans<<'\n';
    return 0;
}/*

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/