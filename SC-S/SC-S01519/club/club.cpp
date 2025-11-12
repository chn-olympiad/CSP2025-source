#include <iostream>
#include <algorithm>
#include <array>
using ll = long long;
using namespace std;
using arr4=array<int,4>;
const int N=1e5+3;
arr4 a[N];
ll ans;
int n;
bool cmp(arr4 x,arr4 y) {
	if(x[1]!=y[1]) return x[1]<y[1];
	if(x[2]!=y[2]) return x[2]<y[2];
	return x[3]<y[3];
}
namespace spcA {
	bool check() {
		for(int i=1;i<=n;i++)
			if(a[i][2]||a[i][3]) return 0;
		return 1;
	}
	bool cmpa(arr4 x,arr4 y) {
		return x[1]>y[1];
	}
	ll work() {
		sort(a+1,a+1+n,cmpa);
		ll sum=0;
		for(int i=1;i<=(n>>1);i++) {
			sum+=a[i][1];
		}
		return sum;
	}
}
namespace spcB {
	bool check() {
		for(int i=1;i<=n;i++)
			if(a[i][3]) return 0;
		return 1;
	}
}
ll b[N][4];
void dfs(const int dp,const int c1,const int c2,const int c3,const ll sum) {
	if(c1>(n>>1)||c2>(n>>1)||c3>(n>>1)) return ;
	if(dp>n) {
		if(sum>ans) ans=sum;
		return ;
	}
	dfs(dp+1,c1+1,c2,c3,sum+a[dp][1]);
	dfs(dp+1,c1,c2+1,c3,sum+a[dp][2]);
	dfs(dp+1,c1,c2,c3+1,sum+a[dp][3]);
}
arr4 getid(const arr4 a) {
	int num=*max_element(a.begin(),a.end()),nxt=0;
	arr4 id;
	for(int j=1;j<=3;j++) if(a[j]==num) {
		id[1]=j;
		break;
	}
	for(int j=1;j<=3;j++) if(j!=id[1]) {
		nxt=max(nxt,a[j]);
	}
	for(int j=1;j<=3;j++) if(j!=id[1] && a[j]==nxt) {
		id[2]=j;
		break;
	}
	for(int j=1;j<=3;j++) if(j!=id[2] && j!=id[1]) {
		id[3]=j;
		break;
	}
	return id;
}
void solve() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) b[i][j]=0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=3;j++) {
			scanf("%d",&a[i][j]);
			b[i][j]=b[i-1][j]+a[i][j];
		}
	}
	if(spcA::check()) {
		printf("%lld",spcA::work());
		return;
	}
	sort(a+1,a+1+n,cmp);
//	ll sum=0; int p[4]={0};
//	for(int i=1;i<=n;i++) {
//		arr4 id=getid(a[i]);
//		if(p[id[1]]<(n>>1)) {
//			p[id[1]]++;
//			sum+=a[i][id[1]];
//		} else if(p[id[2]]<(n>>1)) {
//			p[id[2]]++;
//			sum+=a[i][id[2]];
//		} else {
//			p[id[3]]++;
//			sum+=a[i][id[3]];
//		}
//	}
//	printf("%d\n",sum);
	ans=0;
	dfs(1,0,0,0,0);
	printf("%lld\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) {
		solve();
	}
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
/*
1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
/*
1
2
10 9 8
4 0 0
*/