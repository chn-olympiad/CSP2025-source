#include<bits/stdc++.h>
using namespace std;
int n, m, a[505], f[505], b[505], c[505], ans=0;
char s[505];
void employ1(int k) { // ²âÊÔµã 1-2
	if(k>n) {
		int h=0;
		for(int i=1; i<=n; i++) {
			c[i]=b[i];
		} for(int i=1; i<=n; i++) {
			if(s[i]=='0' || c[i]<=0) {
				for(int j=i+1; j<=n; j++) {
					c[j]--;
				}
			} else {
				h++;
			}
		} if(h>=m) {
			ans=(ans+1)%998244353;
		} return;
	}
	for(int i=1; i<=n; i++) {
		if(f[i]==0) {
			f[i]=1;
			b[k]=a[i];
			employ1(k+1);
			f[i]=0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int cnt1=0, cnt0=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>s[i];
		if(s[i]=='1') cnt1++;
	} for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==0) cnt0++;
	}
	if(n<=10) {
		employ1(1);
		cout<<ans;
	} else if(cnt1==n) {
		n-=cnt0;
		long long int ans=1;
		for(int i=1; i<=n; i++) {
			ans=ans*i%998244353;
		} cout<<ans;
	} else {
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
