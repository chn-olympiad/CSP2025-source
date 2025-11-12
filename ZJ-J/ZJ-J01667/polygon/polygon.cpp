#include<bits/stdc++.h>
using namespace std;
int n,ans;
int b[5005];
void dfs(int d,int f,int s,int mx,int x){
	if(d>n)return;
	if(x>n)return;
	if(f>=d){
		if(s>mx*2){
			ans++;
			if(ans==998244353)ans=0;
		}
		dfs(d+1,0,0,-1,0);
	}
	for(int i=x+1;i<=n;i++){
		dfs(d,f+1,s+b[i],max(mx,b[i]),i);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i];
	dfs(3,0,0,-1,0);
	cout<<ans;
	return 0;
}