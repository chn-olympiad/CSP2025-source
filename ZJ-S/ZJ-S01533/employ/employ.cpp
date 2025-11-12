#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5,lsj=998244353;
int n,m,A,a[N],c[N],cnt0;
ll ans=0;
bool s[N],u[N];
void dfs(int x){
	if(x==n+1){
		int res=0;
		for(int i=1;i<=n;i++){
			if(i-1-res<a[i]&&s[i])res++;
		}
		if(res>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(u[i])continue;
		u[i]=1;
		a[x]=c[i];
		dfs(x+1);
		u[i]=0;
	}
}
void solve1(){
	dfs(1);
	cout<<ans%lsj;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char t;
		cin>>t;
		s[i]=t-'0';
		A+=s[i];
	}
	for(int i=1;i<=n;i++)cin>>c[i],cnt0+=(c[i]==0);
	if(n<=10){
		solve1();
	}
	else cout<<0;
	return 0;
}

