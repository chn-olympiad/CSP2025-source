#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],b[5005],cnt;
int jc(int t){
	int ans=1;
	for(int i=2;i<=t;i++) ans=ans*i%998244353;
	return ans;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(b[n]>a[n]*2) cout<<1;
		return 0;
	}
	for(int i=3;i<n;i++){
		cnt+=jc(n)/(jc(i)*jc(n-i)%998244353);
	}
	cnt++;
	cout<<cnt;
	return 0;
}
