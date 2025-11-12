#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],flag=1,cnt;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1&&a[i]==0)flag=0;
	}
	if(flag==1) {
		if(k==0) {
			cout<<n;
		}
	} else if(flag==0) {
		if(k==0) {
			for(int i=1; i<=n; i++) {
				if(a[i]==1)cnt++;
			}
			cout<<cnt;
		}
	}
	return 0;
}
