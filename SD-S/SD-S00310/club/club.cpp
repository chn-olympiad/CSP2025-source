#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
typedef double db;
typedef long double ld;
#define fir first
#define sec second
#define pb push_back
#define ppc __builtin_popcountll
using namespace std;
void rd(){}
template<typename T,typename ...U> void rd(T &x,U &...arg){
	x=0;int f=1,c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
	x*=f;rd(arg...);
}

const int maxn=1e5+5,inf=1e9;

int N,a[maxn][3];

void __main(){
	rd(N);
	for(int i=1;i<=N;i++)
		for(int j=0;j<3;j++)
			rd(a[i][j]);

	vector<int> vc[3];
	ll ans=0;
	for(int i=1;i<=N;i++){
		int m=max(a[i][0],max(a[i][1],a[i][2]));
		ans+=m;
		for(int j=0;j<3;j++){
			if(m==a[i][j]){
				vc[j].pb(i);
				break;
			}
		}
	}

	int mi=0;
	for(int i=0;i<3;i++)
		if(vc[i].size()>vc[mi].size())
			mi=i;
	for(auto &i:vc[mi]){
		int m=-inf;
		for(int j=0;j<3;j++){
			if(j!=mi){
				m=max(m,a[i][j]-a[i][mi]);
			}
		}
		i=m;
	}
	sort(vc[mi].begin(),vc[mi].end());
	while(int(vc[mi].size())>N/2){
		ans+=vc[mi].back();
		vc[mi].pop_back();
	}

	printf("%lld\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);

	int T;rd(T);
	while(T--) __main();
	return 0;
}
