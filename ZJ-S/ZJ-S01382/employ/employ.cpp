#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 998244353
int n,m;
string s;
int c[114514];
int a[114514];
bool vis[114514];
int ans;
bool check(){
	int x=0,sum=0;
	for(int i=1;i<=n;i++)
		if(s[i-1]=='0')	x++;
		else if(x>=c[a[i]])	x++;
		else sum++;	
	return sum>=m;
}
void dfs(int pos){
	if(pos==n+1){
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])	continue;
		vis[i]=true,a[pos]=i,dfs(pos+1),vis[i]=false;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n>18){
		ans=1;
		for(int i=1;i<=n;i++)
			ans*=i,ans%=MOD;
		cout<<ans%MOD;
		return 0;
	}
	cin>>s;
	for(int i=1;i<=n;i++)	cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
//60+48+40=148pts.
