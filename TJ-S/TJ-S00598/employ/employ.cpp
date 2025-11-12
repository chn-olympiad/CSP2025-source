#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cassert>
const int N=505,mod=998244353;
int n,m;
char s[N];
int c[N];
namespace Force{
	int t[N];
	void solve(){
		for(int i=1;i<=n;i++) t[i]=i;
		long long ans=0;
		do{
			int sum=0;
			for(int i=1;i<=n;i++){
				int x=t[i];
				if(i-1-sum>=c[x]) continue;
				if(s[i]-'0') sum++;
			}
			if(sum>=m) ans++,ans%=mod;
		}while(std::next_permutation(t+1,t+n+1));
		printf("%lld\n",ans);
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	scanf("%s",&s[1]);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	Force::solve();
	
	return 0;
}
