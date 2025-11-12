#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k;
ll ans=0,ans1=0,ans2=0;
ll a[500005];
ll f[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	ll sum=0,ma=0;
	for(int k=1; k<=n; k++) {
		sum=0;
		for(int i=k; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				f[j-i+1]=f[j-i]^a[j];
				if(f[j-i+1]==k) {
					i=j;
					sum++;
					break;
				}
			}
		}
		ma=max(ma,sum);
	}
	cout<<ma<<"\n";
	return 0;
}

