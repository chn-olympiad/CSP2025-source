#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int P=998244353;
int n,m;
bool d[N];
int c[N];
bool vis[N];
int pre[N];
ll ans=0;
bool check(){
	int sum=0,dis=0;
	for(int i=1;i<=n;i++){
		if(c[pre[i]]<=dis){
			dis++;continue;
		}
		if(!d[i]){
			dis++;continue;
		}
		sum++;
	}
	return sum>=m;
}
void dfs(int u){
	if(u>n){
		if(check()) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			pre[u]=i;
			dfs(u+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool t=1;
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		if(ch=='1') d[i]=1;
		else t=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18) dfs(1);
	cout<<ans;
	return 0;
}