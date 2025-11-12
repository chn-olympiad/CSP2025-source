#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=500;
int n,m,ans;
int c[maxn],a[maxn],b[maxn];
string s;
void dfs(int x){
	if(x==n+1){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(c[a[i]]<=sum){
				sum++;
				continue;
			}
			if(s[i]=='0')sum++;
		}
		if(n-sum>=m)ans++,ans%=mod;
//		for(int i=1;i<=n;i++)cout<<a[i]<<' ';
//		cout<<'\n';
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			a[x]=i;
			dfs(x+1);
			b[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s; 
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}