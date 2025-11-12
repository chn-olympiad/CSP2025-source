#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u[1000005],v[1000005],w[1000005];
struct zz{
	int gzf;
	int lf[10005];
}a[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 1;i <= m;i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	}for(int i = 1;i <= k;i++){
		scanf("%d",&a[i].gzf);
		for(int j = 1;j <= n;j++){
			scanf("%d",&a[i].lf[j]);
		}
	}
	int cnt = 0;
	sort(w + 1,w + m + 1);
	for(int i = 1;i <= m / 2;i++){
		cnt += w[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n / 2;i++){
		cnt += a[i].gzf;
	}
	printf("%d",cnt);
	return 0;
}
