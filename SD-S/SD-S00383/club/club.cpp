#include<bits/stdc++.h>
#define eb emplace_back
#define SZ(s) ((int)s.size())
#define all(s) s.begin(),s.end()
typedef double db;
const int N=1e5+5;
template<class T,class I> inline bool chkmax(T &a,I b){return a<b?a=b,1:0;}
template<class T,class I> inline bool chkmin(T &a,I b){return a>b?a=b,1:0;}
using namespace std;
int T,n,a[N][3],id[N],w[N];
vector<int> vec[3];
inline void solve(){
	scanf("%d",&n);
	for(int i=0;i<3;++i) vec[i].clear();
	int ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<3;++j) scanf("%d",&a[i][j]);
		id[i]=0;
		for(int j=1;j<3;++j) if(a[i][j]>a[i][id[i]]) id[i]=j;
		ans+=a[i][id[i]];
		w[i]=INT_MIN;
		for(int j=0;j<3;++j) if(j!=id[i]) chkmax(w[i],a[i][j]-a[i][id[i]]);
		vec[id[i]].eb(w[i]);
	}
	for(int i=0;i<3;++i){
		if(SZ(vec[i])>n/2){
			sort(all(vec[i]),greater<int>());
			for(int j=0;j<SZ(vec[i])-n/2;++j) ans+=vec[i][j];
			break;
		}
	}
	printf("%d\n",ans);
}
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	file("club");
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}
