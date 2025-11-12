#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
int n;
const int maxn=5000+5,mod=998244353;
int a[maxn];
namespace Force{
	void solve(){
		int cnt=0;
		for(int s=0;s<(1<<n);s++){
			int max_=-0x3f3f3f3f,sum=0,c=0;
			for(int i=1;i<=n;i++) if(s>>(i-1)&1) c++,sum+=a[i],max_=std::max(max_,a[i]);
			if(c>=3&&sum>max_*2) cnt++,cnt%=mod;
		}
		printf("%d\n",cnt);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	Force::solve();
	return 0;
}
