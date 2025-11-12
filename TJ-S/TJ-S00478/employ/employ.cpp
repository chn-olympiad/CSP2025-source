#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#define ll long long

template <typename T>
bool relax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}return false;
}
template <typename T>
bool tense(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}return false;
}

const int INF=0x3f3f3f3f;

namespace Force{
	int n,m;
	const int maxn=505;
	char a[maxn];
	int b[maxn],p[maxn],t[maxn];
	void solve(int _n,int _m){
		n=_n,m=_m;
		scanf("%s",&a[1]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);

		int ans=0;
		for(int i=1;i<=n;i++) p[i]=i;
		do{
			for(int i=1;i<=n;i++) t[i]=b[p[i]];
			int c=0;
			for(int i=1;i<=n;i++){
				if(c>=t[i]) c++;
				else{
					if(a[i]=='0') c++;
				}
			}
			if(n-c>=m){
				// for(int i=1;i<=n;i++) printf("%d ",t[i]);
				// puts("");
				ans++;
			}
		}while(std::next_permutation(p+1,p+n+1));
		printf("%d\n",ans);
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	Force::solve(n,m);

	return 0;
}