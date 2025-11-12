#include<bits/stdc++.h>
using namespace std;
const int N=1e5+25;
#define ll long long

int n;
int a[N],b[N],c[N];
int cho_a[N],cho_b[N],cho_c[N];
int na,nb,nc;
int aft_mn[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		na=nb=nc=0;
		ll ans=0;
		for (int i=1;i<=n;++i){
			cin>>a[i]>>b[i]>>c[i];
			int mnx;
			if (a[i]>=b[i]){
				if (a[i]>=c[i]){
					ans+=a[i];
					mnx=max(b[i],c[i]);
					cho_a[++na]=a[i]-mnx;
				}
				else{
					ans+=c[i];
					mnx=max(a[i],b[i]);
					cho_c[++nc]=c[i]-mnx;
				}
			}
			else{
				if (b[i]>=c[i]){
					ans+=b[i];
					mnx=max(a[i],c[i]);
					cho_b[++nb]=b[i]-mnx;
				}
				else{
					ans+=c[i];
					mnx=max(a[i],b[i]);
					cho_c[++nc]=c[i]-mnx;
				}
			}
		}
		sort(cho_a+1,cho_a+na+1);
		sort(cho_b+1,cho_b+nb+1);
		sort(cho_c+1,cho_c+nc+1);
		int mxn=n/2;
		for (int i=1;i<=na-mxn;++i) ans-=cho_a[i];
		for (int i=1;i<=nb-mxn;++i) ans-=cho_b[i];
		for (int i=1;i<=nc-mxn;++i) ans-=cho_c[i];
		cout<<ans<<'\n';
	}
	return 0;
}
