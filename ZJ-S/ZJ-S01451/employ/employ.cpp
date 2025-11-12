#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=510,mod=998244353;

int n,m,a[N],p[N],c[N],ans=0;
bool st[N];
char s[N];

void solve(){
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<"\n";
	int sum=0,tot=0/* Ê§°ÜµÄman */;
	for(int i=1;i<=n;i++){
		if(c[a[i]]<=tot){ tot++; continue; }
		if(s[i]=='1') sum++;
		else tot++;
	}
	if(sum>=m) ans=(ans+1)%mod;
	return;
}

void dfs(int x){
	if(x==n+1){
		solve();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(st[i]==0){
			st[i]=1;
			a[x]=p[i];
			dfs(x+1);
			st[i]=0;
		}
	}
	return;
}

int js_c(int a,int b){
	int sum_a=1;
	for(int i=a;i>=a-b+1;i--) sum_a=(sum_a*i)%mod;
	for(int i=1;i<=b;i++) sum_a=sum_a/i;
	return sum_a;
}

void js(){
	for(int i=m;i<=n;i++) ans=(ans+js_c(n,i))%mod;
	cout<<ans<<"\n";
	return;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin); freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++) p[i]=i;
	cin>>s+1;
	for(int i=1;i<=n;i++) { cin>>c[i]; if(c[i]!=1) flag=1; }
	if(flag==0) { js(); return 0;}
	dfs(1);
	cout<<ans%mod<<"\n";
	return 0;
}
