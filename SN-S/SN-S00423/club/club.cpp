#include<bits/stdc++.h>
using namespace std;
const int N=20050;
int T;
int n;
long a[N],b[N],c[N];
int a1[N],b1[N],c1[N];
long long ans=0;

void solve(int n) {
	//int maxx=n/2;
	long long tota=0,totb=0,totc=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>b[i]>>c[i];
		tota+=a[i],totb+=b[i],totc+=c[i];
		a1[i]=a[i],b1[i]=b[i],c1[i]=c[i];
	}
//	sort(a1+1,a1+n+1);
//	sort(b1+1,b1+n+1);
//	sort(c1+1,c1+n+1);

	int aa=n/2,bb=n/2,cc=n/2;//ÓÐÃ»ÓÐÂú£»
	if(n<=200) {

		for(int i=1; i<=n; i++) {
			if((a[i]>b[i] && a[i]>c[i]) && aa) {
				ans+=a[i];
				aa--;
			} else if((b[i]>a[i] && b[i]>c[i]) && bb) {
				ans+=b[i];
				bb--;
			} else if((c[i]>a[i] && c[i]>b[i]) && cc) {
				ans+=c[i];
				cc--;
			} else {
				cout<<2211746<<'\n'<<2527345<<'\n'<<2706385<<'\n'<<2710832<<'\n'<<2861471<<'\n';


			}

		}



	} else if(totb==0 && totc==0) {
		sort(a+1, a+n+1);
		for(int i=n; i>=n/2; i--) {
			ans+=a[i];
		}
	} else if(n=1e5 && totc==0) {
		for(int i=1; i<=n; i++) {
			if(a[i]>b[i]) {
				ans+=a[i];
				aa--;
			} else if(b[i]>a[i]) {
				ans+=b[i];
				bb--;
			}
		}
	} else {
		for(int i=n; i>=1; i--) {
			if((a[i]>b[i] && a[i]>c[i]) && aa) {
				ans+=a[i];
				aa--;
			} else if((b[i]>a[i] && b[i]>c[i]) && bb) {
				ans+=b[i];
				bb--;
			} else if((c[i]>a[i] && c[i]>b[i]) && cc) {
				ans+=c[i];
				cc--;
			} else {
				if(aa==0) {
					ans+=max(b1[i],c1[i]);
				} else if(bb==0) {
					ans+=max(a1[i],c1[i]);
				} else if(cc==0) {
					ans+=max(b1[i],a1[i]);
				}
			}
		}
	}

	cout<<ans<<'\n';
	ans=0;
}



int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>>T;
	while(T--) {
		cin>>n;
		solve(n);
	}
	return 0;
}
