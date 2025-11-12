#include <bits/stdc++.h>

using namespace std;

#define int long long 

inline int read(){
	char c=getchar();
	int f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	int res=0;
	while(c<='9'&&c>='0'){
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*f;
}

const int N=530;
const int Mod=998244353;

int n,m;
string s;
int c[N];
bool vis[N];
int ans=0;

void dfs(int ord,int cnt){
	if(ord>n){
		if(n-cnt>=m){
			ans++;
			ans%=Mod;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		dfs(ord+1,cnt+((cnt>=c[i])||s[ord-1]=='0'));
		vis[i]=0;
	}
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
//暴力出奇迹?? 