#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
char s[1010];
int sum[1010];
ll c[1010];
const ll md=998244353;
int p[1010];
bool vis[1001];
ll ans=0;
ll cnt=0;
void dfs(int dep){
	if(n-cnt<m){
		return ;
	}
	if(dep==n+1){
	/*	for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				cnt++;
			}else if(cnt>=c[p[i]]){
				cnt++;
			}
		}*/
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			p[dep]=i;
			bool f=0;
			if(s[dep]=='0'){
				cnt++;
				f=1;
			}else if(cnt>=c[p[dep]]){
				cnt++;
				f=1;
			}
			dfs(dep+1);
			cnt-=f;
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
