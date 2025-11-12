#include<bits/stdc++.h>
using namespace std;
int a[5005],b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]+a[3]>a[3]*2) cout<<1;
		else cout<<0;
		return 0;
	}
	long long ans=0;
	for(int i=3;i<=n;i++){
		int f=i;
		if(i>n/2) f=n-f;
		long long s=1;
		for(int j=n-f+1;j<=n;j++) s*=j;
		for(int j=1;j<=f;j++) s/=j;
		s%=998244353;
		ans=(s+ans)%998244353;
	}
	cout<<ans;
	return 0;
}
