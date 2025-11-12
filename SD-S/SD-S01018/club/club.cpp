#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using i128=__int128;
using ull=unsigned long long;
//bool f1;
inline void read(int &a){
	a=0;register char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
namespace SOLVE{
	const int N=1e5+5;
	int a[N][3],n; 
	int vis[3],t[N];
	vector<int> p;
	void main(){
		read(n);
		for(int i=1;i<=n;i++) for(int j=0;j<3;j++) read(a[i][j]);
		ll ans=0;vis[0]=vis[1]=vis[2]=0;p.clear();
		for(int i=1;i<=n;i++){
			int maxx=max(max(a[i][0],a[i][1]),a[i][2]);
			ans+=maxx;
			for(int j=0;j<3;j++){
				if(a[i][j]==maxx){
					vis[j]++;
					t[i]=j;
					break;
				}
			}
		}
		int pt=-1;
		for(int i=0;i<3;i++) if(vis[i]>n/2) pt=i;
		if(pt==-1){
			printf("%lld\n",ans);
			return ;
		}
		for(int i=1;i<=n;i++) if(t[i]==pt){
			int pmax=0;
			for(int j=0;j<3;j++) if(pt!=j) pmax=max(pmax,a[i][j]);
			p.emplace_back(a[i][pt]-pmax); 
		}
		sort(p.begin(),p.end());
		int x=vis[pt]-n/2;
		for(auto i:p){
			ans-=i;x--;
			if(x==0) break;
		}
		printf("%lld\n",ans);
	}
}
//bool f2;
int main(){
//	int _=clock();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=1;
	read(T);
	while(T--) SOLVE::main();
//	cerr<<((&f2)-(&f1))/1024.0/1024.0<<endl;
//	cerr<<clock()-_<<endl;
	return 0;
}
