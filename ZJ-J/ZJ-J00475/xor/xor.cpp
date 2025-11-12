#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,k,c,ans=0;
ll a[N],b[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	if(n<=2&&k==0) {
		cout<<0;
	} else if(k==0) {
		for(int i=0; i<n; i++) {
			if(a[i]==0) {
				ans++;
			}
		}
		cout<<ans;
	} else if(k==1) {
		for(int i=0; i<n; i++) {
			if(a[i]==1) {
				ans+=1;
			}
		}
		cout<<ans;
	}
	return 0;
}
