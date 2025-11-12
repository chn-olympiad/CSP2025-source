#include <bits/stdc++.h>
using namespace std;
int n,m,a[501],p[501],ans,ans1;
bool b[501],vis[501];
long long cnt=0;
string s;
bool c(){
	ans=0;
	ans1=0;
	for(int i=1;i<=n;i++){
//		cout<<p[i]<<" ";
		if(b[i]&&ans<a[p[i]]) ans1++;
		else ans++;
	}
//	cout<<endl;
//	cout<<ans<<" "<<ans1<<endl;
	return ans1>=m;
}
void dfs(int k){
	if(k>n){
		if(c()){
			cnt++;
			cnt%=998244353;
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0') b[i]=0;
		else b[i]=1;
	}
	dfs(1);
	cout<<cnt%998244353;
	return 0;
}
//std::ios::sync_with_stdio(false);
//cin.tie(0);
//cout.tie(0);

