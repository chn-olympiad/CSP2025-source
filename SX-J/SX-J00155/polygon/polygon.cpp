#include<bits/stdc++.h>
using namespace std;
long long ans,n,a[50005],sum=0,mmax=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==3){
		mmax=max(a[1],max(a[2],a[3]));
		if((a[1]+a[2]+a[3])>mmax*2) ans++;
		cout<<ans;
		return 0;
	}
	return 0;
}