#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(ll &x){
	ll f=1;x=0;char s=getchar();
	while (s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while (s>='0'&&s<='9'){x=(x<<1)+(x<<3)+s-'0';s=getchar();}
	x*=f;
}
string s;
const ll mod=998244353;
ll n,m,ans;
bool t[505];
ll a[505],at[505];
bool flag=true;
bool flaga[505];
void init(){
	at[1]=1;
	for (ll i=2;i<505;i++) at[i]=(at[i-1]*i)%mod;
}
void work(){
	printf("%lld",at[n]%mod);
}
void dfs(ll da,ll cn,ll exi){
	if (cn==m){
		ans=(ans+max(1ll,at[n-da+1]))%mod;
		return;
	}
	if (da>n) return;
	for (ll i=1;i<=n;i++){
		if (!flaga[i]){
			flaga[i]=true;
			if (exi>=a[i] || t[da]==false) dfs(da+1,cn,exi+1);
			else dfs(da+1,cn+1,exi);
			flaga[i]=false;
		}
	} 
}
int main(){
	init();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n);read(m);
	cin>>s;
	for (ll i=1;i<=n;i++){
		if (s[i-1]=='1') t[i]=true;
		else t[i]=false;
		flag=flag&&t[i];
	}
	for (ll i=1;i<=n;i++) read(a[i]);
	if (flag){
		work();
		return 0;
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0;
}

