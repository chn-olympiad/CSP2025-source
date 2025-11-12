#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
const int N=5e3+10;
int n;
int a[N];
int ans;
void dfs(int x,int mx,int sum,int num){
	if(num>=3&&sum>2*mx){
		ans++;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,a[i],sum+a[i],num+1);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n-2;i++){
		dfs(i,a[i],a[i],1);
	}
	cout<<ans%Mod;
	return 0;
} 
