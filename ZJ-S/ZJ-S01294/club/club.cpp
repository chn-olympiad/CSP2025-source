#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+100;

void hey() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
int n;
struct str{
	pair<int,int> pa[3];
	int cha[2];
}ele[N];
void gofind(int i,int a,int b,int c) {
	if(a>=b&&a>=c) {
		ele[i].pa[1].first=a;
		ele[i].pa[1].second=1;
		if(b>=c) {
			ele[i].pa[2]={b,2};
			ele[i].pa[3]={c,3};
		} else {
			ele[i].pa[2]={c,3};
			ele[i].pa[3]={b,2};
		}
	}
	if(b>=c&&b>=a) {
		ele[i].pa[1]={b,2};
		if(a>=c) {
			ele[i].pa[2]={a,1};
			ele[i].pa[3]={c,3};
		} else {
			ele[i].pa[2]={c,3};
			ele[i].pa[3]={a,1};
		}
	}
	if(c>=b&&c>=a) {
		
		ele[i].pa[1]={c,3};
		if(a>=b) {
			ele[i].pa[2]={a,1};
			ele[i].pa[3]={b,2};
		} else {
			ele[i].pa[2]={b,2};
			ele[i].pa[3]={a,1};
		}
	}
	ele[i].cha[1]=ele[i].pa[1].first-ele[i].pa[2].first;
	ele[i].cha[2]=ele[i].pa[2].first-ele[i].pa[3].first;
}
bool cmp(str x,str y) {
	if(x.cha[1]==y.cha[1]) {
		if(x.cha[2]==y.cha[2]) {
			if(x.pa[1].first==y.pa[1].first) {
				if(x.pa[2].first==y.pa[2].first) {
					return x.pa[3].first>y.pa[3].first;
				}
				return x.pa[2].first>y.pa[2].first;
			}
			return x.pa[1].first>y.pa[1].first;
		}
		return x.cha[2]>y.cha[2];
	}
	return x.cha[1]>y.cha[1];
}
int ans[4],num[4];
signed main() {
	hey();
	int q;
	scanf("%lld",&q);
	while(q--) {
		ans[1]=ans[2]=ans[3]=num[1]=num[2]=num[3]=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++) {
			int a,b,c;
			scanf("%lld %lld %lld",&a,&b,&c);
			gofind(i,a,b,c);
		}
		sort(ele+1,ele+1+n,cmp);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=3;j++) {
				int u=ele[i].pa[j].second;
				int v=ele[i].pa[j].first;
				if(num[u]<n/2) {
					ans[u]+=v;
					num[u]++;
					break;
				}
			}
		}
		cout<<ans[1]+ans[2]+ans[3]<<'\n';
//		for(int i=1;i<=n;i++) {
//			for(int j=1;j<=3;j++) {
//				cout<<ele[i].pa[j].first<<' '<<ele[i].pa[j].second<<'\n';
//			}
//			cout<<"\n";
//		}
	}
	return 0;
}