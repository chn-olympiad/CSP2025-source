#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int c1,c2,id;
}cnt[5][200005];
int T,n,num,tot[5];
int a[200005][5];
bool cmp(node x,node y){
	if(x.c1 == y.c1) return x.c1 + x.c2 < y.c1 + y.c2;
	return x.c1 < y.c1;
}
void solve(int x,int y,int z){
	sort(cnt[x] + 1,cnt[x] + tot[x] + 1,cmp);
//	for(int i = 1;i <= tot[x];i++) printf("%lld ",cnt[x][i]);
//	puts(""); 
	for(int i = 1;i <= tot[x] - n / 2;i++){
		num -= cnt[x][i].c1;
		if(a[cnt[x][i].id][y] > a[cnt[x][i].id][z]){
			cnt[y][++tot[y]].id = cnt[x][i].id;
			cnt[y][tot[y]].c1 = cnt[x][i].c2;
		}
		else{
			cnt[z][++tot[z]].id = cnt[x][i].id;
			cnt[z][tot[z]].c1 = cnt[x][i].c2;
		}
	}
	if(tot[y] <= n / 2 && tot[z] <= n / 2){
		printf("%lld\n",num);
		return ;
	}
	if(tot[y] >= tot[z]){
		sort(cnt[y] + 1,cnt[y] + tot[y] + 1,cmp);
		for(int i = 1;i <= tot[y] - n/2;i++) num -= cnt[y][i].c1;
	}
	else{
		sort(cnt[z] + 1,cnt[z] + tot[z] + 1,cmp);
		for(int i = 1;i <= tot[z] - n/2;i++) num -= cnt[z][i].c1;
	}
	printf("%lld\n",num);
	return ;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		num = 0;
		memset(tot,0,sizeof tot);
		memset(cnt,0,sizeof cnt);
		scanf("%lld",&n);
		for(int i = 1;i <= n;i++){
			scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3]){
				num += a[i][1];
				cnt[1][++tot[1]].id = i;
				cnt[1][tot[1]].c1 = a[i][1] - max(a[i][2],a[i][3]);
				cnt[1][tot[1]].c2 = max(a[i][2],a[i][3]) - min(a[i][2],a[i][3]);
			}
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3]){
				num += a[i][2];
				cnt[2][++tot[2]].id = i;
				cnt[2][tot[2]].c1 = a[i][2] - max(a[i][1],a[i][3]);
				cnt[2][tot[2]].c2 = max(a[i][1],a[i][3]) - min(a[i][1],a[i][3]);
			}
			else{
				num += a[i][3];
				cnt[3][++tot[3]].id = i;
				cnt[3][tot[3]].c1 = a[i][3] - max(a[i][1],a[i][2]);
				cnt[3][tot[3]].c2 = max(a[i][1],a[i][2]) - min(a[i][1],a[i][2]);
			}
		}
		if(tot[1] <= n / 2 && tot[2] <= n / 2 && tot[3] <= n / 2){
			printf("%lld\n",num);
			continue;
		}
		if(tot[1] >= tot[2] && tot[1] >= tot[3]) solve(1,2,3);
		else if(tot[2] >= tot[1] && tot[2] >= tot[3]) solve(2,1,3);
		else solve(3,1,2);
	}
	return 0;
} 
