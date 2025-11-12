#include <bits/stdc++.h>

using namespace std;

const int N = 200050;
typedef long long ll;
int n;
int a[N][4];
struct node {
	ll val;
	int club;
	int club2;
	int id;
}c[N],d[N];
ll num[4];
void solve() {
	num[0]=num[1]=num[2]=num[3]=0;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		int maxn=std::max({a[i][1],a[i][2],a[i][3]});
		if(maxn==a[i][1]) {
			c[i].val=maxn-std::max(a[i][2],a[i][3]);
			c[i].club=1;
		}
		if(maxn==a[i][2]) {
			c[i].val=maxn-std::max(a[i][1],a[i][3]);
			c[i].club=2;
		}
		if(maxn==a[i][3]) {
			c[i].val=maxn-std::max(a[i][1],a[i][2]);
			c[i].club=3;
		}
		c[i].id=i;
	}
	sort(c+1,c+n+1,[](node x,node y){
		return x.val>y.val;
	});
	long long res=0;
	int fullid=-1;
	int pos=1;
	for(;pos<=n;pos++) {
		res+=a[c[pos].id][c[pos].club];
		++num[c[pos].club];
		if(num[c[pos].club]==(n>>1)) {
			fullid=c[pos].club;
			break;
		}
	}
	int c1,c2;
	if(fullid==1) c1=2,c2=3;
	if(fullid==2) c1=1,c2=3;
	if(fullid==3) c1=1,c2=2;
	for(int i=pos+1;i<=n;i++) {
		if(a[c[i].id][c1]>a[c[i].id][c2]) {
			d[i].val=a[c[i].id][c1]-a[c[i].id][c2];
			d[i].club=c1;
			d[i].club2=c2;
		}
		else {
			d[i].val=a[c[i].id][c2]-a[c[i].id][c1];
			d[i].club=c2;
			d[i].club2=c1;
		}
		d[i].id=c[i].id;
	}
	if(pos+1<=n)
	std::sort(d+pos+1,d+n+1,[](node x,node y){
		return x.val>y.val;
	});
	for(int i=pos+1;i<=n;i++) {
		if(num[d[i].club]<(n>>1)) {
			res+=a[d[i].id][d[i].club];
			++num[d[i].club];
		}
		else {
			res+=a[d[i].id][d[i].club2];
			++num[d[i].club2];
		}
	}
	cout<<res<<"\n";
}
int T;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	while(T--) {
		solve();
	}
	return 0;
}
