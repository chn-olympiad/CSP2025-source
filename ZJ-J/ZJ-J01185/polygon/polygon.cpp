#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5001],b=1,ans,res,sum,t;
void dfs(int x,int y,int z){
	if(x>y){
		if(sum>res*2) ans++;
		return;
	}
	for(int i=z;i<=n;i++){
		t=sum,sum+=a[i],res=a[i];
		dfs(x+1,y,i+1);
		sum-=a[i];
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=a[i-1]) b=0;
	}
	if(b) cout<<b-2;
	else{
		sort(a+1,a+1+n);
		for(int i=3;i<=n;i++) dfs(1,i,1);
		cout<<ans%998244353;
	}
	return 0;
}