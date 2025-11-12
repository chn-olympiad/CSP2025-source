#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void init();void Solve();
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;init();
//	cin>>T;
	while(T--) Solve();
	return 0;
}
void init(){
}
int n,m,c[1005],a[1005],led[1005],ans;
string s;
void dfs(int id){
	if(id==n+1){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0')
				sum++;
			else{
				if(c[a[i]]<=sum) sum++;
				else cnt++;
			}
		}
		if(cnt>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(led[i]) continue;
		a[id]=i;
		led[i]=1;
		dfs(id+1);
		led[i]=0;
	}
}
void Solve(){
	cin>>n>>m>>s;
	s="#"+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans%998244353<<endl;
}

