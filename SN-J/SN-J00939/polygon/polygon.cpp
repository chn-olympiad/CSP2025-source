#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=988244353;
int n;
int num[5100];
bool vis[5100];
int sum,mx=-1,ans,mx1=-1,cnt;
void dfs(int st,int k){
	if(st>n){
		return;
	}
	if(k<3){
		dfs(st+1,k+1);
	}
	for(int i=st;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		int mx2=mx1;
		mx1=max(num[i],mx1);
		cnt+=num[i];
		if(cnt<=2*mx1){
			continue;
		}
		vis[i]=1;
		ans++;
		ans%=MOD;
		dfs(i+1,k+1);
		vis[i]=0;
		mx1=mx2;
		cnt-=num[i];
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&num[i]);
		sum+=num[i];
		mx=max(num[i],mx);
	}
	if(sum<=mx*2){
		cout<<0;     
		return 0;
	}
	sort(num+1,num+1+n);
	//dfs(1,0);
	//cout<<ans/11;
	cout<<1;
	return 0;
}
