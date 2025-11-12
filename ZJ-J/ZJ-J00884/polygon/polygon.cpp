#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5050],cnt,p[5050],k;
bool vis[5050];
void dfs(int x,int ma,int ans){
	if(ans>ma*2){
		cnt++;
		cnt%=mod;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,a[i],ans+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<cnt;
}
