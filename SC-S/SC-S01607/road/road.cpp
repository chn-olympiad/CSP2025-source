#include<bits/stdc++.h>
#define ll long long
#define pll pair< ll,ll > 
using namespace std;
ll n,m,k,dot,ans,a,b,c,head[10105],cnt,jini;
bool vis[10105];
struct node{
	ll ne,to,dis;
}edge[2000005<<1];
void jb(ll from,ll to,ll d){
	cnt++;
	edge[cnt].ne=head[from];
	edge[cnt].to=to;
	edge[cnt].dis=d;
	head[from]=cnt;
	return ;
}
void krulska(){
	priority_queue<pll,vector<pll>,greater<pll> >q;
	q.push(make_pair(0,0));
	q.push(make_pair(1,0));
	while(q.size()){
		ll hx=q.top().second,hd=q.top().first;
		q.pop();
		if(vis[hx]) continue;
		else{
			vis[hx]=1;
			if(hx>=1&&hx<=n)dot++;
		}
		ans+=hd;
		if(dot==n) break;
		for(int i=head[hx];i!=-1;i=edge[i].ne){
			ll y=edge[i].to,d=edge[i].dis;
			if(!vis[y]) q.push(make_pair(d,y));
		}
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		jb(a,b,c);
		jb(b,a,c);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&jini);
		jb(0,n+i,jini);
		for(int j=1;j<=n;j++){
			scanf("%lld",&c);
			jb(n+i,j,c);
		}
	}
	krulska();
	printf("%lld",ans);
	return 0;
}