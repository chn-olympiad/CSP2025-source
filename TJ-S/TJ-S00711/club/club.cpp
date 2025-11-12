#include <bits/stdc++.h>
using namespace std;
int t,n,v[4],s,m1,m2,m3;
struct N{
	int b[4];
}a[100001];
bool cmp(N x,N y){
	return max(max(x.b[1],x.b[2]),x.b[3]) > max(max(y.b[1],y.b[2]),y.b[3]);
}
void dfs(int d,int p){
	if(d > n){
		s = max(s,p);
		return;
	}
	for(int i = 1;i <= 3;i++){
		if(v[i] < n / 2){
			v[i]++;
			dfs(d + 1,p + a[d].b[i]);
			v[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		v[1] = v[2] = v[3] = s = 0;
		scanf("%d",&n);
		for(int i = 1;i <= n;i++){
			scanf("%d%d%d",&a[i].b[1],&a[i].b[2],&a[i].b[3]);
		}
		if(n < 18) dfs(1,0);
		else{
			sort(a + 1,a + n + 1,cmp);
			for(int i = 1;i <= n;i++){
				m1 = m2 = m3 = 1;
				for(int j = 2;j <= 3;j++){
					if(a[i].b[j] > a[i].b[m1]) m1 = j;
					else if(a[i].b[j] > a[i].b[m2]) m2 = j;
					else m3 = j;
				}
				if(v[m1] < n / 2){
					v[m1]++;
					s += a[i].b[m1];
				}else if(v[m2] < n / 2){
					v[m2]++;
					s += a[i].b[m2];
				}else if(v[m3] < n / 2){
					v[m3]++;
					s += a[i].b[m3];
				}
			}
		}
		printf("%d\n",s);
	}
	return 0;
}
