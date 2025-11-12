#include<bits/stdc++.h>
#define ll long long
#define N 505
#define mod 998244353
using namespace std;

int n,m,ans;
char s[N];
int c[N],a[N],vis[N];

void dfs(int x){
	if(x>n){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			int x=a[i];
			if(s[i]=='0'||cnt>=c[x])++cnt;
			else ++sum;
		}
		if(sum>=m)ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1,a[x]=i;
		dfs(x+1);
		a[x]=0,vis[i]=0;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>(s+1);
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
