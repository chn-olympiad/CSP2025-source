#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
int a[5010];
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i] ;
	}
	if(n==1&&n==2)  {
		cout<<0;
		return 0;
	}
	for(int i=2;i<n;i++) {
		ans+=i;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
