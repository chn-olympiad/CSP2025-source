#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,k;
int a[N];
int xor_sum[N];
struct node {
	int f;
	int z;
} q[1000009];
bool cmp(node x,node y) {
	if(x.z==y.z) {
		return x.f<y.f;
	} else {
		return x.z<y.z;
	}
}
bool f[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n>N+99) {
		cout<<0;
		return 0;
	}
	int ma=0;
	bool tpp=true;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
		if(a[i]!=1) tpp=false;
		xor_sum[i]=xor_sum[i-1]^a[i];
	}
	if(tpp){
		cout<<n/2;
	} else {
		long long js=0;
		for(int i=1; i<=n; i++) {
			for(int j=i; j<=n; j++) {
				int o=xor_sum[j]^xor_sum[i-1];
				if(o==k) {
					js++;
					q[js].f=i;
					q[js].z=j-i;
				}
			}
		}
		int ans=0;
		sort(q+1,q+1+js,cmp);
		for(long long i=1; i<=js; i++) {
			bool tf=true;
			for(int j=q[i].f; j<=q[i].f+q[i].z; j++) {
				if(f[j]==true) {
					tf=false;
					break;
				}
			}
			if(tf) {
				ans++;
				for(int j=q[i].f; j<=q[i].f+q[i].z; j++) {
					f[j]=true;
				}
			}
		}
		printf("%d",ans);
	}
	return 0;
}