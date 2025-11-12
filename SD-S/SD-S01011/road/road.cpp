#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int cnt,head[2200010];
int vis[50000];
struct A{
	int to,next,w;
};
A a[20000];
int dp[30000];
void add(int u,int v,int w){
	cnt++;
	a[cnt].next=head[u];
	a[cnt].to=v;
	a[cnt].w=w;
	head[u]=cnt;
}
queue<int> q;
void S(int st){
	q.push(st);
	while(!q.empty()){
		int rt=q.front();
		q.pop();
		vis[rt]=0;
		for(int i=head[rt];i;i=a[i].next){
			int r=a[i].to;
			if(dp[i]>dp[r]+a[r].w){
				dp[i]=dp[r]+a[r].w;
				if(!vis[r]) q.push(r),vis[r]=1;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		add(u,v,w);
		add(v,u,w);
	}
	int e=0;
	int re=0;
	for(int i=1;i<=k;i++){
		int c1;
		cin>>c1;
		for(int j=1;j<=n;j++){
			int c;
			cin>>c;
			add(n+i,j,c1+c);
			add(j,n+i,c1+c);
			if(c1+c==0) e++;
		}
		if(e==n) k=1;
	}
	if(k==1) cout<<0<<endl;
	memset(dp,10000000,sizeof(dp));
	for(int i=1;i<=m;i++){
		dp[a[i].to]=min(dp[a[i].to],a[i].w);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i];
	}
	cout<<ans;
	return 0;
} 
