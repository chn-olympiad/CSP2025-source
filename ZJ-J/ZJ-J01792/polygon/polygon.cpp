#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,a[5010],b[5010],j,sum[5010*5010],ans,mod=998244353,qwq[5010*5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)b[i]=a[i]+b[i-1];
	sum[0]=1;
	for(i=1;i<=n;i++){
		ans+=(qwq[b[i]-a[i]]-qwq[a[i]]+mod),ans%=mod;
		for(int j=b[i];j>=a[i];j--)sum[j]+=sum[j-a[i]],sum[j]%=mod;
		for(int j=a[i];j<=b[i];j++)qwq[j]=qwq[j-1]+sum[j],qwq[j]%=mod;
	}
	cout<<ans;
}
/*
5
1 2 3 4 5
5
2 2 3 8 10
*/
