#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m;
int a[514],c[514],num[514];
bool vis[514];
int ans=0;
bool check(){
	int cnt=0,cntf=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cntf++;
			continue;
		}
		if(cntf>=c[num[i]]){
			cntf++;
			continue;
		}
		cnt++;
	}
	return cnt>=m;
}
void dfs(int d){
	if(d==n+1){
		ans+=(check()?1:0);
		return;
	} 
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		num[d]=i;
		dfs(d+1);
		vis[i]=false;
	}
} 
main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		a[i]=ch-'0';
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
// give me 10 pts plz! qwq!
