#include <bits/stdc++.h>
using namespace std;

int n,k,a[500005],num[500005],l[500005],dp[500005];
vector<int>v[(1<<21)];

void change(int x,int d){
	for(int i=x;i<=n;i+=(i&(-i)))dp[i]=max(dp[i],d);
	return;
}

int query(int x){
	int ans=0;
	for(int i=x;i;i-=(i&(-i)))ans=max(ans,dp[i]);
	return ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	num[0]=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		num[i]=num[i-1]^a[i];
		v[num[i]].push_back(i);
	}
	for(int i=0;i<n;i++){
		int p=num[i]^k,sum=-1;
		int t=v[p].size();
		if(t==0||v[p][t-1]<=i)continue;
		for(int j=20;j>=0;j--){
			if(sum+(1<<j)>=t)continue;
			if(v[p][sum+(1<<j)]<=i)sum+=(1<<j);
		}
		sum++;
		l[i+1]=v[p][sum];
	}
	
	for(int i=1;i<=n;i++){
		if(l[i]==0)continue;
		else{
			change(l[i],query(i-1)+1);
		}
	}
	cout<<query(n);
	return 0;
}
