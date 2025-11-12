#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum[500005];
int a[500005];
int n,k;
struct node {
	int l,r;
} b[500005];
bool cmp(node x,node y) {
	if(x.r==y.r) {
		return x.l<y.l;
	}
	return x.r<y.r;
}
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	int cnt=0;
	int cntt=0;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			cntt++;
			if(cntt>5e8) {
				break;
			}
			if((sum[j]^sum[i-1])==k) {
				b[++cnt].r=j;
				b[cnt].l=i;
				break;
			}
		}
		if(cntt>5e8) {
			break;
		}
	}
	cntt=0;
	for(int i=n; i>=1; i--) {
		for(int j=n; j>=i; j--) {
			cntt++;
			if(cntt>5e8) {
				break;
			}
			if((sum[j]^sum[i-1])==k) {
				b[++cnt].r=j;
				b[cnt].l=i;
				break;
			}
		}
		if(cntt>5e8) {
			break;
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int lst=0,rst=0;
	int res=0;
	for(int i=1; i<=cnt; i++) {
		if(b[i].l>rst) {
			res++;
			lst=b[i].l;
			rst=b[i].r;
		}
	}
	cout<<res<<endl;
}
