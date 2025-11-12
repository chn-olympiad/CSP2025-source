#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,cnt,ans;
int a[5005];
void dfs(int st,int mx){
	if(cnt>a[mx]){
		ans=(ans+1)%mod;
	}for(int i=st;i<mx;i++){
		cnt+=a[i];
		dfs(i+1,mx);
		cnt-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=3;i<=n;i++){
		cnt=0;
		dfs(1,i);
	}cout<<ans%mod;
	return 0;
}
