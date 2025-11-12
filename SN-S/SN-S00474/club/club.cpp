#include<bits/stdc++.h>
using namespace std;
int n,tt;
struct node{int v,id,p;};
node c[300010];
bool vis[100010];
int x[100010],y[100010],z[100010];
int cnt[10];
bool cmp(node u,node v){return u.v>v.v;}
void dfs(int i,int s){
	if(i>n){tt=max(tt,s);return;}
	if(cnt[1]<n/2)cnt[1]++,dfs(i+1,s+x[i]),cnt[1]--;
	if(cnt[2]<n/2)cnt[2]++,dfs(i+1,s+y[i]),cnt[2]--;
	if(cnt[3]<n/2)cnt[3]++,dfs(i+1,s+z[i]),cnt[3]--;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		vis[i]=0;
	cnt[1]=0,cnt[2]=0,cnt[3]=0;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>z[i];
		c[(i-1)*3+1]={x[i],i,1};
		c[(i-1)*3+2]={y[i],i,2};
		c[(i-1)*3+3]={z[i],i,3};
	}
	if(n<=10){
		tt=0;dfs(1,0);
		cout<<tt<<'\n';
		return;
	}
	sort(c+1,c+n*3+1,cmp);
	int ans=0;
	for(int i=1;i<=n*3;i++){
		int v=c[i].v,id=c[i].id,p=c[i].p;
		if(vis[id]||cnt[p]>=n/2)continue;
		vis[id]=1;cnt[p]++;ans+=v;
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;cin>>t;
	while(t--)solve(); 
	return 0;
}
