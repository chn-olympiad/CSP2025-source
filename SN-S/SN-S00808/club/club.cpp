#include <bits/stdc++.h>
using namespace std;
const int M=1e5+3;
int bum[4];
bool used[M]= {0};
struct bm {
	int val,bu;//mval---最大价值，bu--部门
} a[M],b[M],c[M];
bool cmp(bm aa,bm bb) {
	return aa.val >bb.val ;
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		memset(used,0,sizeof used);
		memset(bum,0,sizeof bum);
		int n,aa,ab,ac;
		cin>>n;
		int n2=n>>2;
		for(int i=1; i<=n; i++) {
			cin>>a[i].val>>b[i].val>>c[i].val;
			a[i].bu=i;
			b[i].bu=i;
			c[i].bu=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		//tiaoshi
//		for(int i=1;i<=n;i++)
//		{
//			cout<<a[i].val <<" ";
//		}
//		cout<<endl;
		long long ans=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				bool au=used[a[i].bu],bu=used[b[j].bu];
				if(au&&bu) {
					continue;
				}
				if(bum[1]>=n2) {
					ans+=b[j].val;
					used[b[j].bu]=1;
					bum[2]++;
					continue;
				} else {
					ans+=a[i].val;
					used[a[i].bu]=1;
					bum[1]++;
					continue;
				}
				if((a[i].val>=b[j].val&&!au)||bu) {
					ans+=a[i].val;
					used[a[i].bu]=1;
					bum[1]++;
				} else if((a[i].val<b[j].val&&!bu)||au) {
					ans+=b[j].val;
					used[b[j].bu]=1;
					bum[2]++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
