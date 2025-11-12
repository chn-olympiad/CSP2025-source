#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=515;
const ll M=998244353;
ll n,m,c[N],anss;
string s;
bool f[N];
void dfs(int t,int num,int ans){
	if(t==n+1){
		if(ans>=m)anss++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==1)continue;
		if(num>=c[i]||c[t]=='0')dfs(t+1,num+1,ans);
		dfs(t+1,num,ans+1);
	}
}
int main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	ll len=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<anss;
	return 0;
}