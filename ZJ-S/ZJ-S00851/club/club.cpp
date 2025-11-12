#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int a[N][3];
int b[N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		int num0=0,num1=0,num2=0;
		for(int i=1; i<=n; i++) {
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) num0++;
			else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) num1++;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][2]) num2++;
		}
		long long ans=0;
		bool pas=false;
		if(num0>n/2) {
			for(int i=1; i<=n; i++) {
				if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) {
					b[a[i][0]-max(a[i][1],a[i][2])]++;
				}
				ans+=max(a[i][1],a[i][2]);
			}
		} else if(num1>n/2) {
			for(int i=1; i<=n; i++) {
				if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]) {
					b[a[i][1]-max(a[i][0],a[i][2])]++;
				}
				ans+=max(a[i][0],a[i][2]);
			}
		} else if(num2>n/2) {
			for(int i=1; i<=n; i++) {
				if(a[i][2]>=a[i][0]&&a[i][2]>=a[i][1]) {
					b[a[i][2]-max(a[i][0],a[i][1])]++;
				}
				ans+=max(a[i][1],a[i][0]);
			}
		} else {
			pas=true;
			for(int i=1; i<=n; i++) {
				ans+=max(max(a[i][0],a[i][1]),a[i][2]);
			}
			printf("%lld\n",ans);
		}
		int js=0;
		if(!pas) {
			bool flag=true;
			for(int i=20001; i>=0; i--) {
				if(flag) {
					if(b[i]) {
						ans+=b[i]*i;
						js+=b[i];
					}
					if(js==n/2) {
						printf("%lld\n",ans);
						flag=false;
					}
				}
				b[i]=0;
			}
		}
	}
	return 0;
}