#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long,long long>
const int N=1e5+10;
int a[4][N];
bool vis[N];
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--) {
		priority_queue<pii,vector<pii>,greater<pii>> q12,q13,q23,q21,q31,q32;
		int n,cnt1=0,cnt2=0,cnt3=0,ans=0;
		scanf("%lld",&n);
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld%lld",&a[1][i],&a[2][i],&a[3][i]);
			ans+=max(a[1][i],max(a[2][i],a[3][i]));
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]) {
				cnt1++;
				q12.push({a[1][i]-a[2][i],i});
				q13.push({a[1][i]-a[3][i],i});
			} else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]) {
				q23.push({a[2][i]-a[3][i],i});
				q21.push({a[2][i]-a[1][i],i});
				cnt2++;
			} else {
				q31.push({a[3][i]-a[1][i],i});
				q32.push({a[3][i]-a[2][i],i});
				cnt3++;
			}
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) {
			printf("%lld\n",ans);
			continue;
		}
		while(cnt1>n/2) {
			pii t12=q12.top();
			while(vis[t12.second]==1) {
				q12.pop();
				t12=q12.top();
			}
			pii t13=q13.top();
			while(vis[t13.second]==1) {
				q13.pop();
				t13=q13.top();
			}
			if(t12.first>=t13.first||cnt2>=n/2&&cnt3<n/2) {
				ans-=t13.first;
				vis[t13.second]=1;
				q13.pop();
				cnt3++;
				cnt1--;
			}
			if(t12.first<=t13.first||cnt3>=n/2&&cnt2<n/2) {
				ans-=t12.first;
				vis[t12.second]=1;
				q12.pop();
				cnt2++;
				cnt1--;
			}
		}
		while(cnt2>n/2) {
			pii t21=q21.top();
			while(vis[t21.second]==1) {
				q21.pop();
				t21=q21.top();
			}
			pii t23=q23.top();
			while(vis[t23.second]==1) {
				q23.pop();
				t23=q23.top();
			}
			if(t21.first>=t23.first||cnt1>=n/2&&cnt3<n/2) {
				ans-=t23.first;
				vis[t23.second]=1;
				q23.pop();
				cnt3++;
				cnt2--;
			}
			if(t21.first<=t23.first||cnt3>=n/2&&cnt1<n/2) {
				ans-=t21.first;
				vis[t21.second]=1;
				q21.pop();
				cnt1++;
				cnt2--;
			}
		}
		while(cnt3>n/2) {
			pii t31=q31.top();
			while(vis[t31.second]==1) {
				q31.pop();
				t31=q32.top();
			}
			pii t32=q32.top();
			while(vis[t32.second]==1) {
				q32.pop();
				t32=q32.top();
			}
			if(t31.first>=t32.first||cnt1>=n/2&&cnt2<n/2) {
				ans-=t32.first;
				vis[t32.second]=1;
				q32.pop();
				cnt2++;
				cnt3--;
			}
			if(t31.first<=t32.first||cnt2>=n/2&&cnt1<n/2) {
				ans-=t31.first;
				vis[t31.second]=1;
				q31.pop();
				cnt1++;
				cnt3--;
			}
		}
		printf("%lld\n",ans);
		for(int i=1; i<=n; i++)
			vis[i]=0;
	}
	return 0;
}

