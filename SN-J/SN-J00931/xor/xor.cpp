#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,k,x=0;
	cin>>n>>k;
	int a[500005]= {},a2[500005];
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) {
			x++;
		}
	}
	if(k==0) {
		cout<<x/2;
	} else {
		cout<<x;
	}
	return 0;
}
