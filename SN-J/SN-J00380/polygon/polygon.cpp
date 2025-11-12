#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int cnt=0;
int dfs(int len,int maxa,int sum,int id){
	id++;
	if(id==n){
		if(len>=3&&sum>2*maxa){
			cnt++;
			cout<<len<<" "<<maxa<<" "<<sum<<" "<<id<<endl;
			return 0;
		}else{
			return 0;
		}
	}
	dfs(len+1,max(maxa,a[id]),sum+a[id],id);
	dfs(len,maxa,sum,id);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-3;i++){
		dfs(0,a[i],a[i],0);
	}
	cout<<cnt%998244353;
	return 0;
}
