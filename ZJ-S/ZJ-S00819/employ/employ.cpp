#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define eb emplace_back
const int N=5e2+10,mod=998244353;
int n,m,ans;
char s[N];
int a[N],jc[N],pre[N];
bool fl[N];
int cnt,fa;
void dfs(int pos){
	if((double)clock()/CLOCKS_PER_SEC>0.95) return;
	if(cnt>=m){
		ans+=jc[n-pos+1];
		return ;
	}
	if(cnt+pre[n]-pre[pos-1]<m) return;
	if(pos==n+1) return ans+=(cnt>=m),void();
	for(int i=1;i<=n;i++) if(!fl[i]){
		fl[i]=1;
		int cntt=cnt,ffa=fa;
		if((s[pos]&1)&&fa<a[i]) cnt++;
		else fa++;
		dfs(pos+1);
		cnt=cntt,fa=ffa;
		fl[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s+1;
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=1ll*jc[i-1]*i%mod,pre[i]=pre[i-1]+(s[i]&1);
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1);cout <<ans<<"\n";
	return 0;
}
/*
18 5
110111101101110011
6 0 4 2 1 2 5 4 3 3 1 7 4 0 1 7

*/
