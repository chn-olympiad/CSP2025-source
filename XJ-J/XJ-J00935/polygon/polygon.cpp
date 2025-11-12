#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 5e3+10;
#define LL long long int
LL ans = 0;
int a[N],n;
void hny(int x,int y,int u,int s){
	if (u == n) return ;
	for (int i=x-1;i>=1;i--) {
			if (s+a[i] > a[y]){
				ans++;
				hny(i,y,u+1,s+a[i]);
			}
			else{
				hny(i,y,u+1,s+a[i]);
				continue;
			}
	}
	ans %= 998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	bool f = true;
	if (n < 3){
		printf("0");
		return 0;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i] != 1) f = false;
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			hny(i,j,2,a[i]);
			ans %= 998244353;
		}
	}
	printf("%lld",ans%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
