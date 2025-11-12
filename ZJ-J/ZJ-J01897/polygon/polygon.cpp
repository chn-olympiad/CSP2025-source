#include<bits/stdc++.h>
using namespace std;
int n,a[5001],t;
void dfs(int st,int li,int l,int mxl){
	if(l>mxl*2&&st>=3){
		t++;
		t=t%998244353;
	}
	for(int i=li+1;i<=n;i++){
		dfs(st+1,i,l+a[i],max(mxl,a[i]));
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))) cout<<1;
		else cout<<0;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<t;
}
