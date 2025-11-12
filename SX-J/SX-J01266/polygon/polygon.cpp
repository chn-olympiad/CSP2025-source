#include<bits/stdc++.h>
using namespace std;
long long n,a[50100],ans=0,mx=LLONG_MIN,s=0,v[50010],f=0;
void dfs(long long k){
	if(k>n)return;
	for(int i=k;i<=n;i++){
		if(a[i]>mx)f=mx,mx=a[i];
		s+=a[i];
		if(s>2*mx)ans++;
		dfs(i+1);
		s-=a[i];
		mx=min(mx,f);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
