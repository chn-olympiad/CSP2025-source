#include<bits/stdc++.h>
using namespace std;
int cnt;
short a[5050],n;
const int mod=998244353;
void dfs(short c,short mx,int sum,short bf){
	if(c>=3&&sum>mx*2){
		cnt++;
		cnt%=mod;
	}
	for(int i=bf+1;i<=n;i++){
		mx=max(mx,a[i]);
		dfs(c+1,mx,sum+a[i],i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,-1,0,0);
	cout<<cnt;
	return 0;
}