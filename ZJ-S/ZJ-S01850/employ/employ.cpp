#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,c[1001],ans,pp[1001],maxn,minn=600,tong[1001];
char s[1001],p[1001];
bool f,vis[1001];
ll solve(){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!(s[i]-'0'))pp[i]++;
	for(int i=2;i<=n;i++)
		pp[i]+=pp[i-1];
	for(int i=1;i<=n;i++){
		if(pp[i]!=pp[i-1])vis[i]=1;
		if(!vis[i]&&pp[i]>=c[i]){
			for(int j=i+1;j<=n;j++)
				pp[j]++;
		} 
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
		if(!vis[i])sum++;
	return sum;
}
void bfs(int ct){
	if(ct==n){
		if(solve()>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=501;i++){
		if(tong[i]){
			tong[i]--;
			c[++ct]=i;
			bfs(ct);
			tong[i]++;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	srand(time(0));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(!(s[i]-'0'))f=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		maxn=max(maxn,c[i]);
		minn=min(minn,c[i]);
	}
	if(!f){
		ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%mod; 
		}cout<<ans;
		return 0;
	}else{
		for(int i=1;i<=n;i++)tong[c[i]]++;
		bfs(0);
		cout<<ans+1; 
	} 
	return 0;
}

