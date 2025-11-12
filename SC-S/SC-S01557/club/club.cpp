#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=100005;
int t,n,sum1_a=0,sum1_b=0,sum1_c=0,sum1=0,sum2=0;

int s[5];

int a[INF];
int b[INF];
int c[INF];

int max_a[INF];
int max_b[INF];
int max_c[INF];

signed main() {
	freopen("club.in","l",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int j=1; j<=t; j++) {

		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]) {
				sum1_a++;
				max_a[sum1_a]=a[i];
			}
			if(b[i]>a[i]&&b[i]>c[i]) {
				sum1_b++;
				max_b[sum1_b]=b[i];
			}
			if(c[i]>b[i]&&c[i]>a[i]) {
				sum1_c++;
				max_c[sum1_c]=c[i];
			}
		}
		sort(max_a+1,max_a+1+sum1_a);
		sort(max_b+1,max_b+1+sum1_b);
		sort(max_c+1,max_c+1+sum1_c);
		if((sum1_a<=(n/2))&&(sum1_b<=(n/2))&&(sum1_c<=(n/2))) {
			for(int i=1; i<=sum1_a; i++) sum1+=max_a[i];
			for(int i=1; i<=sum1_b; i++) sum1+=max_b[i];
			for(int i=1; i<=sum1_c; i++) sum1+=max_c[i];
			cout<<sum1;
			continue;
		} else if(sum1_a>(n/2)) {
			for(int i=1; i<=(sum1_a-(n/2)); i++) {
				for(int k=1; k<=n; k++) {
					if(max_a[i]==sum1_a[k]) {
						s[1]=sum1_a[k];
						s[2]=sum1_b[k];
						s[3]=sum1_c[k];
						break;
					}
				}
				sort(s+1,s+4);
				for(int i=1; i<=n; i++) {
					if(s[2]==b[i]) {
						sum2=i;
						max_a[sum2]=0
					} else if(s[2]==c[i]) {
						sum2=i;
						sum1_a[sum2]=0
					}
				}
			}
			for(int i=1; i<=sum1_a; i++) sum1+=max_a[i];
			for(int i=1; i<=sum1_b; i++) sum1+=max_b[i];
			for(int i=1; i<=sum1_c; i++) sum1+=max_c[i];
			cout<<sum1;
		} else if(sum1_b>(n/2)) {
			for(int i=1; i<=(sum1_b-(n/2)); i++) {
				for(int k=1; k<=n; k++) {
					if(max_b[i]==sum1_b[k]) {
						s[1]=sum1_a[k];
						s[2]=sum1_b[k];
						s[3]=sum1_c[k];
						break;
					}
				}
				sort(s+1,s+4);
				for(int i=1; i<=n; i++) {
					if(s[2]==a[i]) {
						sum2=i;
						max_b[sum2]=0
					} else if(s[2]==c[i]) {
						sum2=i;
						sum1_b[sum2]=0
					}
				}
			}
			for(int i=1; i<=sum1_a; i++) sum1+=max_a[i];
			for(int i=1; i<=sum1_b; i++) sum1+=max_b[i];
			for(int i=1; i<=sum1_c; i++) sum1+=max_c[i];
			cout<<sum1;
		} else if(sum1_c>(n/2)) {
			for(int i=1; i<=(sum1_c-(n/2)); i++) {
				for(int k=1; k<=n; k++) {
					if(max_c[i]==sum1_c[k]) {
						s[1]=sum1_a[k];
						s[2]=sum1_b[k];
						s[3]=sum1_c[k];
						break;
					}
				}
				sort(s+1,s+4);
				for(int i=1; i<=n; i++) {
					if(s[2]==b[i]) {
						sum2=i;
						max_c[sum2]=0
					} else if(s[2]==a[i]) {
						sum2=i;
						sum1_c[sum2]=0
					}
				}
			}
			for(int i=1; i<=sum1_a; i++) sum1+=max_a[i];
			for(int i=1; i<=sum1_b; i++) sum1+=max_b[i];
			for(int i=1; i<=sum1_c; i++) sum1+=max_c[i];
			cout<<sum1;
		}
	}
	return 0;
}//1 4 0 0 1 1 0 0 0 2 0 2 1 1