#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500+10,inf=0x3f3f3f3f3f3f3f3f;
int n,m,c[N],ans,p[N];
string s;
bool vis[N];
bool check(){
	int cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		if(c[p[i]]<=cnt){
			cnt++; continue;
		}
		if(s[i]=='0'){
			cnt++; continue;
		}
		sum++;
	}
	return sum>=m;
}
void dfs(int t){
	if(t>n){
		if(check()) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		p[t]=i; vis[i]=1;
		dfs(t+1);
		p[t]=0; vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=18){
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}
