#include<iostream>
#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],c[N],path[N],ans;
bool st[N];
inline bool check(){
	int cnt=0;
//	for(int i=1;i<=n;i++)
//		cout<<path[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=n;i++)
		if(a[i]==0||c[path[i]]<=cnt)
			cnt++;
	return cnt<=n-m;
}
inline void dfs(int u){
	if(u>n){
		if(check())
			ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!st[i]){
			st[i]=true,path[u]=i;
			dfs(u+1);
			st[i]=false;
		}
	}
}
signed main(){
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=c-'0';
		if(!a[i])
			flag=false;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(flag){
		int res=1;
		for(int i=1;i<=n;i++)
			res=res*i%mod;
		cout<<res<<endl;
	}
	else if(m==n)
		cout<<0<<endl;
	else{
		dfs(1);
		cout<<ans<<endl;
	}
}
