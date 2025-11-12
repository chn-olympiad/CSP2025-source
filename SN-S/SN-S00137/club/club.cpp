#include <bits/stdc++.h>

using namespace std;

int t,n,a[100010],b[100010],c[100010];

inline void solve(){
	scanf("%d",&n);
	long long like=0;
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	if(n==2){
		printf("%d\n",max({a[1]+b[2],a[1]+c[2],b[1]+a[2],b[1]+c[2],c[1]+a[2],c[1]+b[2]})); 
		return;
	}
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=n/2;i++)
		like+=a[i];
	printf("%lld\n",like);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		solve();
	}
}
