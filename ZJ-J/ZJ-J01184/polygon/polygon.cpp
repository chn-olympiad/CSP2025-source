#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n,a[5005],ans=0,mm=998244353;
void dfs(int i,int s,int m,int t){
	if(s>2*m&&t>=3){
		ans=(ans+1)%mm;
		if(i!=n)dfs(i+1,s+a[i],a[i],t+1);
		return;
	}
	if(i==n){
		return;
	}
	dfs(i+1,s,m,t);
	dfs(i+1,s+a[i],a[i],t+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,0,0,0);
	cout<<ans<<endl;	
	return 0;
}
