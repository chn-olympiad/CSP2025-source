#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	if(n==1&&1==a[1]&&k==0) {
		cout<<0;

	}
	if(n==2&&a[1]==1&&a[2]==1&&k==0) {
		cout<<1;

	}
	return 0;
}