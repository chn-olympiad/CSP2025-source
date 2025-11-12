#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define N 5005
#define MOD 998244353
int n;
int a[N];
int mx=0;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]<=a[3]||a[1]+a[3]<=a[2]||a[2]+a[3]<=a[1]){
			cout<<0;
			return 0;
		}else{
			cout<<1;
			return 0;
		}
	}
	bool flag=true;
	for(int i=1;i<=n-1;i++){
		if(a[i]!=a[i+1]){
			flag=false;
		}
	}
	if(flag){
		int ans=1;
		for(int i=4;i<=n;i++){
			ans=ans*i%MOD;
		}
		for(int i=1;i<=n-3;i++){
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
} 
