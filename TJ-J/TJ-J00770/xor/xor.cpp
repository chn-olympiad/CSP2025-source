#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

template <typename T>
bool tense(T &a,const T &b){
	if(a>b){
		a=b;
		return true;
	}return false;
}
template <typename T>
bool relax(T &a,const T &b){
	if(a<b){
		a=b;
		return true;
	}return false;
}

namespace Force{
	int n,m;
	const int maxn=5e5+5;
	int a[maxn],s[maxn];
	int ans;
	void dfs(int lastr,int c){
		// printf("%d %d\n",lastr,c);
		relax(ans,c);		
		for(int l=lastr+1;l<=n;l++) for(int r=l;r<=n;r++){
			// printf("[%d,%d] = %d\n",l,r,s[r]^s[l-1]);
			if((s[r]^s[l-1])==m) dfs(r,c+1);
		}
	}
	
	void solve(int _n,int _m){
		n=_n,m=_m;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);

		for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		// for(int l=1;l<=n;l++) for(int r=l;r<=n;r++){
		// 	printf("[%d,%d] = %d\n",l,r,s[r]^s[l-1]);
		// }
		dfs(0,0);
		printf("%d\n",ans);

		for(int ans=n;ans>=0&&0;ans--){
			bool ok=false;
			// ok=f(ans);

			if(ok){
				printf("%d\n",ans);
				break;
			}
		}
	}
}

namespace Better{
	int n,m;
	const int maxn=5e5+5;
	int a[maxn],s[maxn];
	struct rec{int l,r;}b[maxn];
	bool operator<(const rec &a,const rec &b){
		if(a.r==b.r) return a.l>b.l;
		return a.r<b.r;
	}
	
	void solve(int _n,int _m){
		n=_n,m=_m;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);

		for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		int len=0;
		for(int l=1;l<=n;l++) for(int r=l;r<=n;r++){
			if((s[r]^s[l-1])==m){
				b[++len]=(rec){l,r};
				// assert((s[r]^s[l-1]==m)&&(s[r]^m==s[l-1]));
			}
		}
		std::sort(b+1,b+len+1);
		int ans=0;
		for(int i=1,lastr=0;i<=len;i++){
			if(lastr<b[i].l){
				ans++;
				lastr=b[i].r;
			} 
		}
		printf("%d\n",ans);
	}
}

namespace Correct{
	int n,m;
	const int maxn=5e5+5;
	int a[maxn],s[maxn],c[1024*1024+10];
	struct rec{int l,r;}b[maxn];
	bool operator<(const rec &a,const rec &b){
		if(a.r==b.r) return a.l>b.l;
		return a.r<b.r;
	}
	
	void solve(int _n,int _m){
		n=_n,m=_m;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);

		for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
		int len=0;
		for(int i=1;i<=n;i++){
			// s[i]=s[i-1]^a[i];
			if(a[i]==m) b[++len]=(rec){i,i};
			if(c[(s[i]^m)]>0) b[++len]=(rec){c[(s[i]^m)]+1,i};
			relax(c[s[i]],i);
		}
		// for(int l=1;l<=n;l++) for(int r=l;r<=n;r++){
			// if((s[r]^s[l-1])==m) b[++len]=(rec){l,r};
		// }
		std::sort(b+1,b+len+1);
		// for(int i=1;i<=len;i++) printf("%d %d\n",b[i].l,b[i].r);
		int ans=0;
		for(int i=1,lastr=0;i<=len;i++){
			if(lastr<b[i].l){
				// printf("%d %d\n",b[i].l,b[i].r);
				ans++;
				lastr=b[i].r;
			} 
		}
		printf("%d\n",ans);
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);
	if(n<=1000) Better::solve(n,m);
	else Correct::solve(n,m);

	return 0;
}
