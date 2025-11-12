#include<bits/stdc++.h>
#define int long long
#define For(i,j,k) for(int i=j;i<=k;++i)
#define dFor(i,j,k) for(int i=j;i>=k;--i)
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
namespace DEBUG{
	template<class T> void _debug(const char *s,T x){cout<<s<<'='<<x<<'\n';}
	template<class F,class...Nxt> void _debug(const char *s,F x,Nxt...nxt){
		int d=0;
		while(*s!=','||d) d+=*s=='(',d-=*s==')',cout<<*s++;
		cout<<'='<<x<<',';
		_debug(s+1,nxt...);
	}
	#define debug(...) _debug(#__VA_ARGS__,__VA_ARGS__)
}
using namespace DEBUG;
const int inf=1e18;
const int Mmod=1e9+7;
const int MAXN=200005;
int T,n,a[MAXN][4],f[MAXN];
inline bool cmp(int x,int y){
	switch(f[x]){
		case 1:return max(a[x][2],a[x][3])-a[x][1]<max(a[y][2],a[y][3])-a[y][1];
		case 2:return max(a[x][1],a[x][3])-a[x][2]<max(a[y][1],a[y][3])-a[y][2];
		case 3:return max(a[x][1],a[x][2])-a[x][3]<max(a[y][1],a[y][2])-a[y][3];
	}
}
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	FIO("club");
	cin>>T;
	while(T--){
		vector<int>v[4];
		cin>>n;
		For(i,1,n) For(j,1,3) cin>>a[i][j];
		For(i,1,n){
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) v[1].push_back(i),f[i]=1;
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) v[2].push_back(i),f[i]=2;
			else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2]) v[3].push_back(i),f[i]=3;
		}
		For(j,1,3) if(!v[j].empty()) sort(v[j].begin(),v[j].end(),cmp);
		int ans=0;
		For(j,1,3){
			int total=v[j].size();
			if(total<=n/2) continue;
			dFor(i,total-1,n/2){
				int x=v[j][i];
				switch(j){
					case 1:{
						if(a[x][2]>=a[x][3]&&(int)v[2].size()+1<=n/2) f[x]=2,v[2].push_back(x);
						else f[x]=3,v[3].push_back(x);
						break;
					}
					case 2:{
						if(a[x][1]>=a[x][3]&&(int)v[1].size()+1<=n/2) f[x]=1,v[1].push_back(x);
						else f[x]=3,v[3].push_back(x);
						break;
					}
					case 3:{
						if(a[x][1]>=a[x][2]&&(int)v[1].size()+1<=n/2) f[x]=1,v[1].push_back(x);
						else f[x]=2,v[2].push_back(x);
						break;
					}
				}
			}
		}
		For(i,1,n) ans+=a[i][f[i]];
		cout<<ans<<'\n';
	}
	return 0;
}

