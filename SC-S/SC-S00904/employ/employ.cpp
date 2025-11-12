#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=998244353;
int n,m;
ll ans;
string s;
int a[505],v[505];
void dfs(int u,int f){
	if(u==n+1){
		if(n-f==m) {
			ans=(ans+1)%M;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			if(f>=a[i]||s[u-1]=='0')
				dfs(u+1,f+1);
			else dfs(u+1,f);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}