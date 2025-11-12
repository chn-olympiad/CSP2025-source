#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD=998244353;
const int N=505;
int n,m,ans;
bool a[N];
string x;
void dfs(int num,int cnt){
	if(num==n&&cnt==m){
		ans=(ans+1)%MOD;
		return;
	}
	for(int i=1;i<=n;i++){
		if(cnt==m&&num<n&&a[i]==0){
			a[i]=1;
			dfs(++num,cnt);
			a[i]=0;
		}
		if(x[num-1]=='0'&&a[i]==0&&num<n){
			a[i]=1;
			dfs(++num,cnt);
			a[i]=0;
		}
		else if(x[num-1]=='1'&&a[i]==0&&cnt<m&&num<n){
			a[i]=1;
			dfs(++num,++cnt);
			a[i]=0;
			a[i]=1;
			dfs(++num,cnt);
			a[i]=0;
		}
	}
	return;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i]=1;
		if(x[0]=='0'){
			dfs(1,0);
		}
		else{
			dfs(1,1);
		}
		a[i]=0;
	}
	cout<<ans%MOD;
	return 0;
}