#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long ans;
int n,m;
string s;
int c[505],a[12];
inline void dfs(int k,int now,int qi){
	if(k==n+1){
		if(now>=m)ans++,ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]=1;
			if(s[k-1]=='0' || qi>=c[i])dfs(k+1,now,qi+1);
			else dfs(k+1,now+1,qi);
			a[i]=0;
		}
	}
}
signed main(){
   freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
   ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	int fl=0,ret=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0')fl=1;
		else ret++;
	}
	if(ret<m){
		cout<<0;
		return 0;
	}
   return 0;
}

