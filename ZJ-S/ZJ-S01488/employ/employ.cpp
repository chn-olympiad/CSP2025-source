#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define R register
#define LL long long
using namespace std;
const int mod=998244353,N=5e2+10;
int n,m,c[N],a[N],p[N],cnt,ans;
bool vis[N];
string s;
inline void dfs(int dep){
	if(dep>n){
		for(R int i=1;i<=n;i++) p[i]=c[a[i]];
		int res=0,cnt=0;
		for(R int i=1;i<=n;i++){
			if(s[i-1]=='0'){
				cnt++;
				continue;	
			}
			if(p[i]<=cnt){
				cnt++;
				continue;
			}
			if(s[i-1]=='1') res++;
		}
		if(res>=m) ans++;
		ans%=mod;
		return;
	}
	for(R int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			a[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	bool f=1;
	for(R int i=0;i<s.size();i++)
		if(s[i]=='0'){
			f=0;
			break;
		}
	for(R int i=1;i<=n;i++) cin>>c[i];
	if(f){
		LL res=1;
		for(R int i=1;i<=n;i++) res=(res*i)%mod;
		cout<<res<<'\n';
		return 0;
	}else{
		if(m==n){
			cout<<0<<'\n';
			return 0;
		}
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
