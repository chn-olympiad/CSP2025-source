#include<cstdio>
#include<algorithm>
template <typename T> bool tense(T &a,const T &b){return b<a?a=b,true:false;}
template <typename T> bool relax(T &a,const T &b){return b>a?a=b,true:false;}

int n,m;

namespace Force{
	const int N = 510,mod = 998244353;
	char s[N];
	int c[N];
	int p[N];
	
	void solve(){
		scanf("%s",&s[1]);
		for(int i=1;i<=n;i++) scanf("%d",&c[i]);
		for(int i=1;i<=n;i++) p[i] = i;
		int res = 0;
		do{
			int cnt = 0;
			for(int i=1;i<=n;i++){
				if(i-1-cnt>=c[p[i]]) continue;
				if(s[i]=='1') cnt++;
			}
			if(cnt>=m){
				res = (res+1)%mod;
//				for(int i=1;i<=n;i++) printf("%d ",p[i]);
//				puts("");
			}
		} while(std::next_permutation(p+1,p+n+1));
		printf("%d\n",res);
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	Force::solve();
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	solve();
	return 0;
}


