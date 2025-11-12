#include<bits/stdc++.h>
#define int long long
#define pub push_back
#define pii pair<int,int>
#define mkp make_pair
using namespace std;
int n,m,jc[509],ans;
string s;
int c[509];
const int mod=998244353;
int use[509],pl[509];
bool check(){
	int fail=0,ok=0;
	for(int i=1;i<=n;i++){
		if(fail>=pl[i]){
			fail++;
			continue;
		}
		if(s[i]=='1') ok++;
		else fail++;
	}
	if(ok>=m) ans++;
}
void dfs(int x){
	if(x>n){
		check();
	}
	for(int i=1;i<=n;i++){
		if(!use[i]){
			use[i]=1;
			pl[x]=c[i];
			dfs(x+1);
			use[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
