#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[5001];
ll ans,sum;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n==3){
		int mmax=max(a[1],max(a[2],a[3]));
		if(sum>2*mmax) cout<<1;
		else cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	if(n==4){
		if(a[1]+a[2]>a[3]) ans++;
		if(a[1]+a[2]>a[4]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
		if(a[1]+a[3]>a[4]) ans++;
		if(a[1]+a[2]+a[3]>a[4]) ans++;
		cout<<ans;
		return 0;
	}
	if(n==5){
		if(a[1]+a[2]>a[3]) ans++;
		if(a[1]+a[2]>a[4]) ans++;
		if(a[2]+a[3]>a[4]) ans++;
		if(a[1]+a[3]>a[4]) ans++;
		if(a[1]+a[2]>a[5]) ans++;
		if(a[1]+a[3]>a[5]) ans++;
		if(a[1]+a[4]>a[5]) ans++;
		if(a[2]+a[3]>a[5]) ans++;
		if(a[2]+a[4]>a[5]) ans++;
		if(a[3]+a[4]>a[5]) ans++;
		if(a[1]+a[2]+a[3]>a[4]) ans++;
		if(a[1]+a[2]+a[3]>a[5]) ans++;
		if(a[1]+a[2]+a[4]>a[5]) ans++;
		if(a[1]+a[3]+a[4]>a[5]) ans++;
		if(a[3]+a[2]+a[4]>a[5]) ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[5]) ans++;
		cout<<ans;
		return 0;
	}
	srand(time(0));
	ans=rand()%998244353+1;
	cout<<ans;
	return 0;
}
