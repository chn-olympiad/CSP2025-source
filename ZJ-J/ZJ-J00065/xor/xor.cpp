#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int l,r;
}a[10005];
int n,k,ans=0,b[10005],fd[10005][10005],t,r[10005];
vector<int> f[10005];
int spfa(int x){
	int sum=0,dis[10005],vis[10005];
	queue<int>q;
	q.push(x);
	memset(dis,-127,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=1;
	vis[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<f[u].size();i++){
			int y=f[u][i];
			if(dis[y]<dis[u]+1){
				dis[y]=dis[u]+1;
				if(vis[y]==0){
					vis[y]=1;
					q.push(y);
				}
			}
		}
		vis[u]=0;
	}
	for(int i=1;i<=t;i++)
		sum=max(sum,dis[t]);
	return sum;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>b[i],fd[i][i]=b[i];
		if(fd[i][i]==k){
			a[++t].l=i;
			a[t].r=i;
		}
	}
	for(int i=1;i<n;i++)
	for(int j=i+1;j<=n;j++){
		fd[i][j]=fd[i][j-1]^b[j];
		if(fd[i][j]==k){
			a[++t].l=i;
			a[t].r=j;
		}
	}
//	cout<<t<<" ";
	for(int i=1;i<t;i++){
		for(int j=i+1;j<=t;j++){
			int ll=a[i].l,rr=a[i].r,lll=a[j].l,rrr=a[j].r;
			if(rrr<ll) f[j].push_back(i),r[i]++;
			if(rr<lll) f[i].push_back(j),r[j]++;
		}
	}
	for(int i=1;i<=t;i++){
		if(r[i]==0)
			ans=max(ans,spfa(i));
	}
	cout<<ans;
}
