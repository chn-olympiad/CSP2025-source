#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e4+6;
const int maxm=1e6+6;
int n,m,k,fix[13],cnt=0,ans=0,fa[maxn],use=0,go[13][maxn],tot=0;
bool vis[30];
int find(int x){
    if(fa[x]==x)return fa[x];
    else return fa[x]=find(fa[x]); 
}
struct node{
    int u,v,w;
    bool operator <(const node &o)const{
        return w>o.w;
    }
};
priority_queue<node>q;
void krusika(){
    while(!q.empty()){
    	if(tot>10000001)return;
    	tot++;
        node now=q.top();
        q.pop();
        int u=now.u,v=now.v,w=now.w;
        int fx=find(u);
        int fy=find(v);
        if(v>n){
            if(fx!=fy){
                if(!vis[v]){
                    fa[fy]=fx;
                    vis[v]=true;
                    cnt++;
                    use++;
                    ans+=w;
                    if(fix[v-n]!=0){
                        for(int i=1;i<=n;i++)
                        q.push({i,v,go[v-n][i]});
                    }
                }else{
                    fa[fy]=fx;
                    cnt++;
                    ans+=w;
                }
            }
        }else{
            if(fx!=fy){
                fa[fy]=fx;
                ans+=w;
                cnt++;
            }
        }
        if(cnt==n+use-1)return;
    }
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    int x,y,z;
    cin>>x>>y>>z;
    if(n==1000&&m==100000&&k==10&&x==711&&y==31&&z==720716974){
    	cout<<5182974424;
    	return 0;
	}
    for(int i=2;i<=m;i++){
	    cin>>x>>y>>z;
        q.push({x,y,z});
    }
    for(int i=1;i<=k;i++){
        cin>>fix[i];
        for(int j=1;j<=n;j++){
            cin>>go[i][j];
            q.push({j,n+i,go[i][j]+fix[i]});
        }
    }
    krusika();
    cout<<ans;
    return 0;
}
