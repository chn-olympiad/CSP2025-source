#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
#define int long long

const int N=500+10;
const int MOD=998244353;
int n,m,c[N],a[N],sum[N],vis[N],ans;
string s;
void dfs(int step){
	if(step>n){
		int tlq=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]!='0'&&c[a[i]]>sum[i]){
				tlq++;
			}
		}
		if(tlq>=m){ 
//			for(int i=1;i<=n;i++){
//				cerr<<a[i]<<' ';
//				cerr<<c[a[i]]<<' ';
//				cerr<<sum[i]<<' ';
//			}
//			cerr<<'\n';
			ans++;
			ans%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		sum[i+1]=sum[i]+(!(s[i]-'0'));
//		cerr<<sum[i+1]<<' ';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
//	cerr<<'\n';
	dfs(1);
	cout<<ans;

	return 0;
}

