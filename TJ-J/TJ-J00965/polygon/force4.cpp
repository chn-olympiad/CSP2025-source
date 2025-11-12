#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
const int N=5005;
int n;
int a[N];
namespace Force{
	void solve(){
		int ans=0;
		for(int s=0;s<(1<<n);s++){
			int maxa=0,sum=0;
			for(int i=1;i<=n;i++){
				if(s>>(i-1)&1) maxa=std::max(maxa,a[i]),sum+=a[i];
			}
			if(sum>2*maxa) ans++;
		}
		printf("%d\n",ans);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("force4.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	Force::solve();

	return 0;
}
