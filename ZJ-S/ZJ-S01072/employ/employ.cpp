#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int n,m,a[505],s[505],sum;
bool vis[505];
void dfs(int k,int ans1,int ans2) {
	if(k==n+1) {
		if(ans1>=m){
			sum++;
			sum %= mod;
		}
		return;
	}
	for(int i = 1; i<=n; i++) {
		if(vis[i]) continue;
		vis[i] = 1;
		if(ans2>=a[i]||s[k]==0) dfs(k+1,ans1,ans2+1);
		else dfs(k+1,ans1+1,ans2);
		vis[i] = 0;
	}
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int rp = 0,pp = 0;
	for(int i = 1; i<=n; i++) {
		char l;
		cin>>l;
		s[i] = l-'0';
		if(s[i]==1) {
			rp++;
		}
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			pp++;
		}
	}
	if(rp<m||n-pp<m){
		cout<<0;
	}
	else if(rp==n||pp==0){
		sum = 1;
		for(int i = 2;i<=n;i++){
			sum *= i;
			sum %= 2;
		}
		cout<<sum;
	}
	else {
		dfs(1,0,0);	
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

