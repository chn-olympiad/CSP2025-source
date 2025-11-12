#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,a[5010],ans;
void dfs(int st,int be,int sum,int x){
	if (st==x){
		for(int i=be+1;i<=n;i++){
			if (a[i]*2<sum+a[i]) ans++,ans%=mod;
			else break;
		}
		return;
	}
	for(int i=be+1;i<=n;i++){
		dfs(st+1,i,sum+a[i],x);
	}
	return;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n);
	if (n==3){
		if(a[n]*2<sum){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		dfs(1,0,0,i);
	}
	cout<<ans;
	return 0;
}
