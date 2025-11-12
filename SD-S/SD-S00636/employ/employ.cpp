#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501;
const int Mod=998244353;
int n,m,c[N];
int a[N],ans;
bool vis[N];
string s;
void dfs(int x){
	if(x==n+1){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=c[a[i]]) cnt++;
			else sum++;
		}
		if(sum>=m) ans=(ans+1)%Mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			a[x]=0;
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
