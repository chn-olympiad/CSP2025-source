#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,k,a[N],b[N];
int m=0;
int ans;
bool f1=true;
bool f2=true;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) f1=false;
		if(a[i]!=1&&a[i]!=0) f2=false;
		b[i]=(b[i-1]^a[i]);
	}
	if(f1==true) {
		cout<<n/2<<"\n";
	}
	else if(f2==true) {
		int cnt=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==1) cnt++;
		}
		if(k==1) {
			cout<<cnt<<"\n";
		}
		else if(k==0) {
			cout<<cnt/2<<"\n";
		}
	}
	else {
		for(int i=1;i<=n;i++) {
			if(i<=m) continue;
			for(int j=i;j<=n;j++) {
				if((b[j]^b[i-1])==k) {
					m=j;
					ans++;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
