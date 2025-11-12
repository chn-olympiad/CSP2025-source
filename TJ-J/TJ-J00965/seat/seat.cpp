#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cassert>
#include<cstdlib>
#include<ctime>
const int N=105;
int n,m;
int a[N],ans[15][15];
namespace Force{
	bool cmp(const int &q,const int &w){
		return q>w;
	}
	void solve(){
		int tar=a[1];
		std::sort(a+1,a+n*m+1,cmp);
		int t=0;
		for(int j=1;j<=m;j++){
			if(j%2){
				for(int i=1;i<=n;i++){
					ans[i][j]=a[++t];
					if(ans[i][j]==tar) printf("%d %d\n",j,i);
				}
			}else{
				for(int i=n;i>=1;i--){
					ans[i][j]=a[++t];
					if(ans[i][j]==tar) printf("%d %d\n",j,i);
				}
			}
		}
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	Force::solve();
	return 0;
}
