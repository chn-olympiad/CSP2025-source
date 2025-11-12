#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,k,c[505],sum0[505],ans;
bool v[505];
string s;
void dfs(int id,int p,int f){
	if(s[f-1]=='1'&&c[id]<=sum0[f]){
		return;
	}
	if(p==m){
		ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(s[f]=='0') dfs(i,p,f+1);
			else dfs(i,p+1,f+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0) k++;
	}
	sort(c+1,c+n+1);
	for(int i=0;i<n;i++){
		sum0[i+1]=sum0[i]+(s[i]=='0');
	}
	if(sum0[n]==0){
		int cnt=1;
		for(int i=2;i<k;i++){
			cnt=cnt*i%mod;
		}
		cout<<cnt<<endl;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		if(c[i]!=0){
			v[i]=1;
			dfs(i,1,1);
			memset(v,0,sizeof v);
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}