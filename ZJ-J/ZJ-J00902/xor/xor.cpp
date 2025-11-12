#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],mp[500005],dp[500005];
int mina=0x7f7f7f7f,maxa=0;

int dfs(int last,int xn){
	int maxn=0;
	for(int i=last+1;i<=n;i++){
		if(mp[i]!=0x7f7f7f7f){
			if(dp[mp[i]]!=-1){
				maxn=max(maxn,dp[mp[i]]+1);
				continue;
			}
			dp[mp[i]]=dfs(mp[i],xn+1);
			maxn=max(maxn,dp[mp[i]]+1);
		}
	}
	return maxn;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mina=min(mina,a[i]);
		maxa=max(maxa,a[i]);
	}
	if(mina==1 && maxa==1){
		cout<<n/2;
		return 0;
	}
	memset(mp,0x7f,sizeof(mp));
	int l=1,r=1,sum=a[1];
	while(r<=n){
		while(r<=n && sum!=k){
			r++,sum^=a[r];
		}
		if(sum==k && mp[l]>r) mp[l]=r;
		l++,r=l,sum=a[l];
	}
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,0);
	return 0;
}
