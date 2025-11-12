#include<cstdio>
#include<algorithm>
#include<cmath>
/*
4 2
2 1 0 3
*/
namespace force{
	const int MAXN=5e5+5;
	int n,k;
	int a[MAXN];
	int s[MAXN];
	int ans=0;
	void solve(){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		s[1]=a[1];
		for(int i=2;i<=n;i++){
			s[i]=(s[i-1]^a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((s[j]^s[i-1])==k){
					ans++;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
}
int main(){
	force::solve();
	return 0;
}
