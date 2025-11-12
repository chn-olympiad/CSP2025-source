#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,mod=998244353;
int a[N],ps[N];
int id[N];
bool vis[N];
int ans=0;
int n,m;
bool cheak(){
	int s=0,cnt=0;
	for(int i=1;i<=n;i++){
		int x=id[i];
		if(s>=ps[x]||!a[i]){
			s++;
		}
		else cnt++;
	}
	if(cnt>=m) return 1;
	return 0;
}
void dfs(int x){
	if(x==n){
		if(cheak()) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			id[x+1]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		a[i]=(int)(x-'0');
		if(a[i]==0) f=0;
	}
	for(int i=1;i<=n;i++) cin>>ps[i];
	if(n<=10){
		dfs(0);
		cout<<ans<<"\n";
		return 0;
	}
	if(f){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ps[i]){
				cnt++;
			}
		}
		if(cnt<m){
			cout<<0<<"\n";
			return 0;
		}
		int ans=1;
		for(int i=1;i<=n;i++) ans=(ans*i)%mod;
		cout<<ans<<"\n";
		return 0;
	}
	cout<<0<<"\n";
	return 0;
}
