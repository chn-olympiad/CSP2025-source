#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e3+7,mod=998244353;
int n,ans,sum;
int a[N];
void dfs(int dp,int n1,int k1,int maxx,int s){
	if(n1==k1){
		if(s>a[maxx])sum++;
		return;
	}for(int i=dp;i<=maxx-(k1-n1);i++){
		dfs(i+1,n1+1,k1,maxx,s+a[i]);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		for(int j=n;j>=i;j--){
			sum=0;
			dfs(1,0,i-1,j,0);
			ans+=sum;
			ans%=mod; 
		}
	}
	cout<<ans;
	return 0;
}
