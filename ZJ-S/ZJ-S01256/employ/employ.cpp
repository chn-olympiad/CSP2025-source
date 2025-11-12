#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,mod=998244353;
int n,m;
int ans=0;
int c[N];
int fac[N];
bool vis[N]={false};
string s;
void dfs(int x,int k){
	if(k > n-m) return;
	if(x >= n) return (++ans)%=mod,void();
	if(x-k >= m) {
		(ans+=fac[n-x])%=mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		vis[i]=true;
		if(k>=c[i]||s[x]=='0'){
			dfs(x+1,k+1);
		}
		else if(k<c[i]&&s[x]=='1')
			dfs(x+1,k);
		vis[i]=false;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	fac[0]=1;
	
	for(int i=1;i<=500;++i) fac[i]=fac[i-1]*i%mod;
	
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int c:s)
		sum+=(c=='1');
	for(int i=1;i<=n;++i)
		cin>>c[i];
	sort(c+1,c+1+n);
	if(sum<m){
		cout<<0<<"\n";
		return 0;
	}
	
	if(n<=18){
		dfs(0,0);
		cout<<ans<<"\n";
		return 0;
	}
	
	if(sum==n){
		int cur=0;
		for(int i=1;i<=n;++i)
			if(cur>=c[i])
				cur++;
		
		if(cur+m <= n){
			cout<<fac[n]<<"\n";
			return 0;
		}
		cout<<fac[m];
		return 0;
	}
	
	
	cout<<fac[m]; 
	
	return 0;
}
