#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
using namespace std;
mt19937_64 rd(time(0));
const ll N=1e5+5,mod=998244353;
ll n,bo[N],ans,jie[N],m,c[N],a[N];
void dfs(ll x,ll now){
	if(x-now-1>=m){
		ans=(ans+jie[n-x+1])%mod; return ;
	}
	if(n-now<m)return ;
	if(x>n){return ;}
	for(int i=1;i<=n;i++){
		if(!bo[i]){
			bo[i]=1;
			ll p=now;
			if(now>=c[i]||!a[x])p++;
			dfs(x+1,p);
			bo[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	jie[0]=1;
	for(int i=1;i<=n;i++){
		jie[i]=(jie[i-1]*i)%mod;
	}
	ll sum=0;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;a[i]=x-'0';if(!a[i])sum++;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(m==n&&sum){
		cout<<0;
		return 0;
	}
	//if(n<=10){
		dfs(1,0);
		cout<<ans;
	//}
	
	return 0;
}
//Ren5Jie4Di4Ling5%

