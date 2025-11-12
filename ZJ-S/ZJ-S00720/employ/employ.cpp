#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=505;
const int mod=998244353;
int n,m,ans=0;
int s[maxn],c[maxn],id[maxn];
bool vis[maxn];
void dfs(int now){
	if(now==n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[id[i]]||s[i]==0){
				cnt++;
			}
		}
		if(n-cnt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			id[now+1]=i;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool p=1;
	for(int i=1;i<=n;i++){
		char ch;
		cin>>ch;
		s[i]=ch-'0';
		p&=s[i];
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			id[1]=i;
			dfs(1);
			vis[i]=0;
		}
		cout<<ans<<"\n";
		return 0;
	}
	return 0;
}
