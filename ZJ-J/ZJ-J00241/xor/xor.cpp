#include<bits/stdc++.h>
using namespace std;
set<long long> x[1048600];
long long a[500050],s[500050],pre[500050],dp[500050],maxx[500050],n,k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long A=pow(2,20);
	cin>>n>>k;
	long long i;
	for(i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		x[s[i]].insert(i);
	}
	for(i=1;i<=A;i++) x[i].insert(-2);
	x[0].insert(0);
	for(i=1;i<=n;i++) pre[i]=*prev(x[s[i]^k].lower_bound(i))+1;
	for(i=1;i<=n;i++){
		if(pre[i]>0) dp[i]=maxx[pre[i]-1]+1;
		maxx[i]=max(maxx[i-1],dp[i]);
	}
	cout<<maxx[n];
	return 0;
}