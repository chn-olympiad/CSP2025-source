#include<bits/stdc++.h>
using namespace std;

int s[1010],a[1010];
int vis[1010],z[1010],ans=0;
int n,m;

void dfs(int step){
	if(step>n){
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=a[z[i]]) cnt++;
			else if(s[i]==0) cnt++;
			else sum++;
		}
		if(sum>=m) ans++;
		ans%=998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		z[step]=i;
		dfs(step+1);
		z[step]=0;
		vis[i]=0;
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string t;
	cin>>t;
	int sum=0,cnt=0;
	for(int i=0;i<n;i++){
		s[i+1]=t[i]-'0';
		sum+=s[i+1];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt+=(a[i]==0);
	}
	if(n<=18){
		dfs(1);
	}
	else if(sum==n){
		if(n-cnt<m) ans=0;
		else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans*=2;
				ans%=998244353;
			}
		}
	}
	else ans=0;
	cout<<ans;
	return 0;
}
