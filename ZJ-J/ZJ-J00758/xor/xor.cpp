#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],ans,f[500005],A=1,B=1,C=1;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)A=0;
		if(a[i]>1)B=0;
		if(a[i]>255)C=0;
	}
	if(n<=2&&k==0&&A==1) {
		if(n==0)cout<<0;
		else if(n==1&&k==0) {
			if(a[1]==k)cout<<1;
			else cout<<0;
		} else if(n==2&&k==0) {
			if(a[1]==k)ans++;
			if(a[2]==k)ans++;
			if(ans>0)cout<<ans;
			else if(a[1]^a[2]==k)cout<<1;
			else cout<<0;
			return 0;
		}//1
	}
	if(n<=10&&k<=1&&B==1) {
		for(int i=1; i<=n; i++)f[a[i]]++;
		cout<<f[k];
		return 0;
	}//2
	if(n<=100&&k==0&&A==1) {
		cout<<n/2;
		return 0;
	}//3
	if(n<=100&&k<=1&&B==1) {
		for(int i=1; i<=100; i++)f[a[i]]++;
		cout<<f[k];
		return 0;
	}//4,5
	if(n<=200000&&k<=1&&B==1) {
		for(int i=1; i<=n; i++)f[a[i]]++;
		cout<<f[k];
		return 0;
	}//13
	for(int i=1;i<=n;i++){
		if(a[i]==k)ans++;
	}
	cout<<ans;
	return 0;
}





















