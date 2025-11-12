#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int kMaxN=105;
const int M=998244353;
int n,m,a[kMaxN],b[kMaxN];
ll ans;
bool used[kMaxN];
char c[kMaxN];
inline bool check(){
	int cnt=0,res=0;
	for(int i=1;i<=n;++i){
		if(cnt<b[i]&&c[i]=='1') ++res;
		else ++cnt;
	}return res>=m;
}
inline void dfs(int dep){
	if(dep>n){
		if(check())
			++ans;
		return;
	}
	for(int i=1;i<=n;++i){
		if(used[i]) continue;
		b[dep]=a[i];
		used[i]=true;
		dfs(dep+1);
		used[i]=false;
	}return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int i;
	cin>>n>>m;
	cin>>(c+1);
	for(i=1;i<=n;++i) cin>>a[i];
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
