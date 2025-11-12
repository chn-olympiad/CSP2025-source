#include<bits/stdc++.h>
using namespace std;
int n,k,a[200100];
void solve2() {
	int res=0;
	for(int i=1; i<n; i++) {
		if(abs(a[i]-a[i+1])==1 and a[i]>=0 and a[i+1]>=0) {
			a[i]=-1;
			a[i+1]=-1;
			res++;
		}
		if(a[i]==1)res++;
	}
	cout<<res+(a[n]==1);
	return;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(k==0)cout<<n/2;
	else if(k==1)solve2();
	return 0;
}
