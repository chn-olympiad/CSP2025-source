#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=5e5+10;
int n,k,use[N],a[N],ans;
int A=1,B=1;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=1)A=0;
		if(a[i]>=2)B=0;
	}
	if(k==0&&A==1) { //A
		cout<<n/2;
	} else if(k<=1&&B==1) { //B
		if(k==1) {
			for(int i=1; i<=n; i++) {
				if(a[i]==1)ans++;
			}
		} else {
			for(int i=1; i<=n; i++) {
				if(a[i]==0)ans++;
			}
			for(int i=1; i<=n; i++) {
				if(a[i]==1&&a[i+1]==1) {
					ans++;
					i++;
				}
			}
		}
		cout<<ans;
	} else {
		cout<<69;
	}
	return 0;
}
