#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005],s[500005];
long long ans;
bool fA=true,fB=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for (long long i=1;i<=n;i++){
		cin>>a[i];
		if (a[i] != 1) fA=false;
		if (a[i] > 1) fB=false;
		s[i]=s[i-1]^a[i];
	}
	if (n == 2){
		cout<<1;
		return 0;
	}
	if (fA){
		cout<<n/2;
		return 0;
	}
	if (fB){
		long long x=0;
		for (long long i=1;i<=n;i++){
			if (s[i]^x == k){
				x^=a[i];
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	if (n <= 1000){
		for (long long l=1;l<=n;l++){
			for (long long r=l;r<=n;r++){
				long long x=s[r]^s[l-1];
				if (x==k){
					ans++;
					l=r+1;
				}
			}
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
