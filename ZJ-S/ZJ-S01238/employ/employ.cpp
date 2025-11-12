#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353;
const int N=22;
int n,m,a[N],p[N];
bool vis[N];
string s;
ll ans;
inline void dfs(int x){
	if(x==n+1){
		int cnt=0,kkk=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt>=p[i]) cnt++;
			else kkk++;
		}
		if(kkk>=m){
			ans++;
			ans%=mod;	
		}	
		return;
	}
	int la=p[x];
	for(int i=1;i<=n;i++)if(!vis[i]){
		p[x]=a[i];vis[i]=1;
		dfs(x+1);
		p[x]=la;vis[i]=0;
	}
}
int main(){	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	dfs(1);
	cout<<ans;
	return 0;
}
