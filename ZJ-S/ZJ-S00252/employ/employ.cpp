#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans=0,n,m,mo=998244353,c[1001],b[1001],z;
bool f[1001];
char s[1001];
int dfs(int x){
	if(x>n){
		z=0;
		for(int i=1;i<=n;i++){
			//cout<<b[i]<<" ";
			if(s[i]=='0'||z>=c[b[i]]){
				z++;
			}
		}
		//cout<<"\n";
		if(n-z>=m)ans++;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			b[x]=i;
			dfs(x+1);
			f[i]=0;
		}
	}
	return 0;
}
signed main(){
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans%mo;
	return 0;
}
