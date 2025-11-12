#include <bits/stdc++.h>
using namespace std;
long long t,n,ans,cnt1,cnt2,cnt3,ans2;
struct u {
	long long o,tw,th,lll,rrr,ppp;
} a[100010];
int cmp(u x,u y) {
	return x.lll>y.lll;
}
int solve() {
	cin>>n;
	ans=0,cnt1=0,cnt2=0,cnt3=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i].o>>a[i].tw>>a[i].th;
	}
	for(int i=1; i<=n; i++) {
		a[i].lll=max(a[i].o,max(a[i].th,a[i].tw));
		a[i].rrr=min(a[i].o,min(a[i].th,a[i].tw));
		a[i].ppp=a[i].o+a[i].th+a[i].tw-a[i].lll-a[i].rrr;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<=n; i++) {
		if(a[i].lll-a[i].ppp<a[i+1].lll&&a[i+1].lll-a[i+1].ppp>a[i].lll-a[i].ppp) {
			if(cnt1==n/2-1&&a[i].lll==a[i].o||cnt2==n/2-1&&a[i].lll==a[i].tw||cnt3==n/2-1&&a[i].lll==a[i].th) {
				a[i].lll=a[i].ppp;
			}
		}
		if(a[i].lll==a[i].o&&cnt1<n/2) {
			cnt1++;
			ans+=a[i].o;
			continue;

		}
		if(a[i].lll==a[i].tw&&cnt2<n/2) {
			cnt2++;
			ans+=a[i].tw;
			continue;

		}
		if(a[i].lll==a[i].th&&cnt3<n/2) {
			cnt3++;
			ans+=a[i].th;
			continue;
		}
		if(a[i].lll==a[i].o&&cnt1>=n/2) {
			if(a[i].th>a[i].tw) {
				cnt3++;
				ans+=a[i].th;
				continue;

			}
			if(a[i].th<=a[i].tw) {
				cnt2++;
				ans+=a[i].tw;
				continue;

			}
		}
		if(a[i].lll==a[i].tw&&cnt2>=n/2) {
			if(a[i].th>a[i].o) {
				cnt3++;
				ans+=a[i].th;
				continue;

			}
			if(a[i].th<=a[i].o) {
				cnt1++;
				ans+=a[i].o;
				continue;

			}
		}
		if(a[i].lll==a[i].th&&cnt3>=n/2) {
			if(a[i].o>a[i].tw) {
				cnt1++;
				ans+=a[i].o;
				continue;

			}
			if(a[i].o<=a[i].tw) {
				cnt2++;
				ans+=a[i].tw;
				continue;

			}
		}
	}
	return ans;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--) {
		cout<<solve()<<endl;
	}
	return 0;
}
//cout<<i<<" "<<1<<" ";

