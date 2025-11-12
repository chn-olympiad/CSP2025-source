#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <string>
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
	const int maxn=2e5+5;
	char s[5000005];
	struct rec{std::string s1,s2;}a[maxn];
	void solve(int _n,int _m){
		n=_n,m=_m;
		for(int i=1;i<=n;i++){
			scanf("%s",&s[1]);
			a[i].s1=&s[1];
			scanf("%s",&s[1]);
			a[i].s2=&s[1];
		}
		while(m--){
			scanf("%s",&s[1]);
			std::string q1,q2;
			q1=&s[1];
			scanf("%s",&s[1]);
			q2=&s[1];

			int ans=0;
			for(int l=0;l<(int)q1.size();l++){
				for(int r=l;r<(int)q1.size();r++){
					std::string t,t1,t2;
					bool can=true;
					for(int i=0;i<l;i++) if(q1[i]!=q2[i]) can=false;
					if(!can) continue;
					for(int i=r+1;i<(int)q1.size();i++) if(q1[i]!=q2[i]) can=false;
					if(!can) continue;
					for(int i=l;i<=r;i++) t+=q1[i];
					for(int i=1;i<=n;i++){
						if(a[i].s1==t){
							t1=a[i].s2;
							bool ok=true;
							for(int j=l,k=0;j<=r;j++,k++) if(q2[j]!=t1[k]) ok=false;
							if(ok) ans++;
						}
					}
				}
			}
			printf("%d\n",ans);
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	Force::solve(n,m);

	return 0;
}