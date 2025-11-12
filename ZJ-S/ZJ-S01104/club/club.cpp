#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[100010][4],v[4],ans;
void dfs(int st,int sum){
	if (st>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if (v[i]>=n/2) continue;
		v[i]++;
		dfs(st+1,sum+a[st][i]);
		v[i]--;
	}
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while (T--){
		v[1]=v[2]=v[3]=0;
		ans=-2e9;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}