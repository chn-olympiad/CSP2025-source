#include <bits/stdc++.h>
using namespace std;
int a[500000],b[500000];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	b[1]=a[1];
	for(int i=2; i<=n; i++) {
		b[i]=b[i-1]^a[i];
	}
	int cnt=0;
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(b[i]^k==b[j] && i!=j) {
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
