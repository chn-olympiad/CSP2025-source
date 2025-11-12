#include<bits/stdc++.h>
#define int long long
#define FREOPEN(x) freopen(x ".in","r",stdin),freopen(x ".out","w",stdout);
using namespace std;
int a[500005];
signed main() {
	FREOPEN("xor")
	int n,k,flag=1,cnt1=0,cnt0=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) {
			flag=0;
		} else {
			cnt1++;
		} if(!a[i]) {
			cnt0++;
		}
	} if(k==1) {
		cout<<cnt1;
		return 0;
	} else {
		int ans=0;
		for(int i=1;i<=n;) {
			int cnt1jd=0;
			while(a[i]==1) {
				i++;
				cnt1jd++;
			} ans+=cnt1jd/2+(i>n?0:1);
			i++;
		} cout<<ans;
	} return 0;
}