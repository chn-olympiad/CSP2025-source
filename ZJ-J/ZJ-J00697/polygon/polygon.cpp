#include<bits/stdc++.h>
using namespace std;

int a[500010],cnt=0;
int n;

void dfs(int step,int sum,int maxn,int k){
	if(step>n){
		if(k>=3 && sum>maxn*2) cnt++;
		cnt%=998244353;
		return;
	}
	dfs(step+1,sum,maxn,k);
	dfs(step+1,sum+a[step],max(a[step],maxn),k+1);
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20) dfs(1,0,0,0);
	else{
		cnt=1;
		for(int i=4;i<=n;i++){
			cnt*=2;
			cnt%=998244353;
		}
	}
	cout<<cnt;
	return 0;
}

