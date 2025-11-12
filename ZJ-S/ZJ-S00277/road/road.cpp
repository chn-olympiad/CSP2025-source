#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,ans=1e9,K,C[11],c[11][100050];
struct node{
	ll nxt,s,e,len,pre;
}l[1100050];
ll head[100050],cnt;
void add(ll s,ll e,ll len){
	cnt++;
	l[cnt].nxt=head[s];
	l[head[s]].pre=cnt;
	l[cnt].e=e;
	l[cnt].s=s;
	l[cnt].len=len;
	head[s]=cnt;
}
void pop(){
	head[l[cnt].s]=l[cnt].pre;
	cnt--;
}
void calc(ll k){
	ll vis[110050]={0},d[110050]={0,0};
	queue<ll> q;
	q.push(1);        
	ll i;
	for(i=2;i<=n+K;i++) d[i]=1e9;
	while(q.size()){
		ll x=q.front();
		q.pop();
		vis[x]=0;
		for(i=head[x];i!=0;i=l[i].nxt){
			if(d[l[i].e]>d[x]+l[i].len){
				d[l[i].e]=d[x]+l[i].len;
				if(vis[l[i].e]==0){
					vis[l[i].e]=1;
					q.push(l[i].e);
				}
			}
		}
	}
	ll x,an=k;
	for(x=1;x<=n+K;x++){
		for(i=head[x];i!=0;i=l[i].nxt){
			if(d[l[i].e]==d[x]+l[i].len){
				an+=l[i].len;
			}
		}
	}
	ans=min(an,ans);
}
void dfs(ll d,ll k){
	if(d==K){
		calc(k);
		return;
	}
	dfs(d+1,k);
	ll i;
	for(i=1;i<=n;i++){
		add(n+d+1,i,c[d+1][i]);
		add(i,n+d+1,c[d+1][i]);
	}
	dfs(d+1,k+C[d+1]);
	for(i=1;i<=n*2;i++) pop();
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>K;
	while(m--){
		ll a,b,len;
		cin>>a>>b>>len;
		add(a,b,len);
		add(b,a,len);
	}
	ll i,j;
	for(i=1;i<=K;i++){
		cin>>C[i];
		for(j=1;j<=n;j++)
			cin>>c[i][j];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}