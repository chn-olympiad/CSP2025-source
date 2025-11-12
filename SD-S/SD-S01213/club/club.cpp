#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
template <typename ty> 
inline void read(ty &x) {
	x=0; bool f=0; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
template <typename ty,typename ...T> 
inline void read(ty &x,T &...te) {
	read(x); read(te...);
}
const int N=1e5+50;
ll a[N][3];
void solve() {
	int n;
	read(n);
	for(int i=1;i<=n;i++) read(a[i][0],a[i][1],a[i][2]);
	ll ans=0;
	priority_queue<ll>q[3];
	for(int i=1;i<=n;i++) {
		vector<PII>vec;
		for(int j=0;j<3;j++) 
			vec.push_back({a[i][j],j});
		sort(vec.begin(),vec.end(),[&](const PII x,const PII y) {
			return x.fir>y.fir;
		});
		ans+=vec[0].fir;
		q[vec[0].se].push(vec[1].fir-vec[0].fir);
	}
	for(int i=0;i<3;i++) 
		while(q[i].size()>n/2) {
			ans+=q[i].top();
			q[i].pop();
		}
	printf("%lld\n",ans);
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
	while(T--) 
		solve();
	return 0;
}
