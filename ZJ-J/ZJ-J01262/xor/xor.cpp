#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],c[N],dp[N],d[1<<20];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)c[i]=(c[i-1]^a[i]);
	for(int i=0;i<(1<<20);i++)
		d[i]=-1e9;
	d[0]=0;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		dp[i]=max(dp[i-1],d[k^c[i]]+1);
		d[c[i]]=max(d[c[i]],dp[i]);
	}
	cout<<dp[n];
	return 0;
}