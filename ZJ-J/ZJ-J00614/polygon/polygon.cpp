#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
bool vis[5005];
vector <int> p;
const int mod=998244353;
void dfs(int sum,int ma,int k,int len){
	if(sum>2*ma&&len>=3){
		ans++;
		ans%=mod;
	}
	for(int i=k+1;i<=n;i++){
		ma=max(ma,a[i]);
		dfs(sum+a[i],ma,i,len+1);
	}
} 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}
