#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,m,c[505],b[505],vis[505],ans,t,nw;
string s;
void dfs(int d){
	if(d>n){
		t=n;nw=0;
		for(int i=1;i<=n;i++){
			if(nw>=c[b[i]]||s[i-1]=='0'){
				nw++;
				t--;
			}
		}
		if(t>=m)ans++;
		return ;
	}else{
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				vis[i]=1;
				b[d]=i;
				dfs(d+1);
				vis[i]=0;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}

