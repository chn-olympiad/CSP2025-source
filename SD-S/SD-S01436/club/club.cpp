#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
typedef long long LL;
int T,n;
int k1,k2,k3;
int q1[N],q2[N],q3[N];
struct node{
	int a1,a2,a3;
	int v;
}a[N];
bool cmp(int x,int y){
	return a[x].v > a[y].v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		k1 = k2 = k3 = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a1 > a[i].a2 && a[i].a1 > a[i].a3) q1[++k1] = i,a[i].v = a[i].a1 - max(a[i].a2,a[i].a3);
			else if(a[i].a2 > a[i].a3) q2[++k2] = i,a[i].v = a[i].a2 - max(a[i].a1,a[i].a3);
			else q3[++k3] = i,a[i].v = a[i].a3 - max(a[i].a1,a[i].a2);
		}
		if(k1 > n / 2) sort(q1 + 1,q1 + k1 + 1,cmp);
		if(k2 > n / 2) sort(q2 + 1,q2 + k2 + 1,cmp);
		if(k3 > n / 2) sort(q3 + 1,q3 + k3 + 1,cmp);
		LL ans = 0;
		for(int i = 1;i <= k1;i++){
			if(i <= n / 2) ans += a[q1[i]].a1;
			else ans = ans + a[q1[i]].a1 - a[q1[i]].v;
		}
		for(int i = 1;i <= k2;i++){
			if(i <= n / 2) ans += a[q2[i]].a2;
			else ans = ans + a[q2[i]].a2 - a[q2[i]].v;
		}
		for(int i = 1;i <= k3;i++){
			if(i <= n / 2) ans += a[q3[i]].a3;
			else ans = ans + a[q3[i]].a3 - a[q3[i]].v;
		}
		printf("%lld\n",ans); 
	}
	return 0;
}
