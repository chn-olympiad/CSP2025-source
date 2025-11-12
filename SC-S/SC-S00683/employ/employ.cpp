#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
char a[505];
int jc[505],c[505],n,m,ans;
bool f[505];
vector<int>q;
void dfs(int x,int sum,int fq){
	if(x>n){
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!f[i]){
			f[i]=1;
			if(a[x]=='1'&&fq<c[i]) dfs(x+1,sum+1,fq);
			else dfs(x+1,sum,fq+1);
			f[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i;
	cin>>n>>m;
	bool flag=1;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='1') q.push_back(i);
		else flag=0;
	}
	for(i=1;i<=n;i++) cin>>c[i];
	sort(c+1,c+n+1);
	if(m==1){
		jc[0]=1;
		for(i=1;i<=n;i++) jc[i]=(jc[i-1]*i)%mod;
		for(i=0;i<q.size();i++){
			int xb=lower_bound(c+1,c+n+1,xb-1)-c;
			if(xb>n) continue;
			ans=(ans+(n-xb)*(jc[n-1])%mod)%mod;
		}
		cout<<ans;
		return 0;
	}
	if(m==n){
		if(!flag) cout<<"0\n";
		else cout<<"1\n";
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}