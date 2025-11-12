#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int val,id;
}a[101];
int n,m,cnt,s,tot;
bool cmp(node aa,node bb){
	return aa.val > bb.val;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cnt = n * m;
	for (int i = 1;i <= cnt;i++){
		scanf("%lld",&a[i].val);
		a[i].id = i;
	}
	sort(a + 1,a + cnt + 1,cmp);
	for (int i = 1;i <= cnt;i++){
		if (a[i].id == 1){
			s = i;
			break;
		}
	}
	for (int j = 1;j <= m;j++){
		if (j % 2 == 0){
			for (int i = n;i >= 1;i--){
				tot++;
				if (tot == s){
					printf("%lld %lld",j,i);
					return 0;
				}
			}
		}else{
			for (int i = 1;i <= n;i++){
				tot++;
				if (tot == s){
					printf("%lld %lld",j,i);
					return 0;
				}
			}
		}
	}
	return 0;
}
