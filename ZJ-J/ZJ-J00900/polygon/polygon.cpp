#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
int n;
int cntl;
int mod=988244353;
int vis[N];
int ans;
void dfs(int step,int cnt){
	if(step>n){
		int sum=0,maxl=0;
		for(int i=1;i<=n;i++){
			sum+=vis[i]*a[i];
			maxl=max(maxl,vis[i]*a[i]);
		}
		if(cnt<3){
			return;
		}
		if(sum<=maxl*2){
			return;
		}
		ans++;
		ans%=mod;
		return;
	}
	if(n-step+1<3&&cnt<3){
		vis[step]=1;
		dfs(step+1,cnt+1);
		return;
	}
	for(int i=1;i>=0;i--){
		vis[step]=i;
		cnt+=i;
		dfs(step+1,cnt);
	}
	return;
}
bool num[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
