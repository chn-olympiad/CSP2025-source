#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[5050]={};
bool r[5050]={};
int qzh[5050]={};
int ans=0;
void dfs(int q,int qh){
	for(int i=q+1;i<n;i++){
		r[i]=true;
		if(qh>a[i]) ans=(ans+1)%998244353;
		dfs(i,qh+a[i]);
		r[i]=false;
	}
	return;
}
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		r[i]=false;
		if(i!=0) qzh[i]=qzh[i-1]+a[i];
		else qzh[i]=a[i];
	}
	sort(a,a+n,cmp);
	dfs(-1,0);
	cout<<ans<<endl;
	return 0;
}
