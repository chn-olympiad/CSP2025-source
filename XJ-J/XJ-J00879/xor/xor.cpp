//只考虑substr1 3的情况 expect 10pts
#include<bits/stdc++.h>
#define int long long
const int N =1E3+10;
using namespace std;
int n,k,z;
int a[N];
int clac(int l,int r) {
	if(l==r) {
		return a[l];
	}
	int f=0;
	if(l-r==1){
		return (a[l]^a[r]);
	}
	for(int i=l; i<r; i++) {
		f^=a[i]^a[i+1];
	}
	return f;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==0){
			z++;
		} 
	}
	if(k==0) {
		if(n==1) {
			cout<<0;
			return 0;
		}
		if(n==2) {
			cout<<1;
			return 0;
		}
		if(n%2==0) {
			cout<<n/2;
			return 0;
		} else {
			cout<<0;
			return 0;
		}

	}//显然的，对于特殊性质A(全是1) &&K==0
	cout<<z;
	return 0;
}
