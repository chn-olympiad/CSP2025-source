#include<bits/stdc++.h>
using namespace std;
long long n,s,a[5005],b[5005],k=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;b[1]=1;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (n==3){
		sort(a+1,a+4);
		if (a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for (int i=2;i<=n;i++) b[i]=(b[i-1]*i)%k;
	for (int i=3;i<n;i++) s=(s+b[n]/(b[i]*b[n-i]))%k;
	cout<<s+1;
}