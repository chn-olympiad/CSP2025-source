#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,ans,a[5010];
void dfs(int dep,int cnt,int sum,int ma);
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void dfs(int dep,int cnt,int sum,int ma){
	if(dep==n+1){
		if(cnt<3) return;
		if(sum<=ma*2) return;
		ans++;
		ans%=mod;
		return;
	}
	dfs(dep+1,cnt+1,sum+a[dep],a[dep]);
	dfs(dep+1,cnt,sum,ma);
	return;
}