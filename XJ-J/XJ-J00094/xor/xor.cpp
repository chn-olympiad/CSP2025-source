#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,k;
int a[N],T[N];
int ans=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==k)ans++,T[i]=1;
	}
	for(int l=1; l<=n; l++) {
		for(int r=l+1; r<=n; r++) {
			int sum=0;
			for(int i=l; i<=r; i++) {
				if(T[i]==1) {
					sum=-1;
					break;
				}
				sum=sum xor a[i];
			}
			if(sum==k) {
				for(int i=l; i<=r; i++) {
					T[i]=1;
				}
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
