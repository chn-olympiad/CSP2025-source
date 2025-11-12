#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int a[200000],b[200000],c[200000];
int z1[200000],z2[200000],z3[200000];
int r1,r2,r3;
long long ans = 0;
int shan[200000];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	for(int round = 1;round <= t;round ++){
		scanf("%d",&n);
		ans = 0;
		r1 = 0;
		r2 = 0;
		r3 = 0;
		
		for(int i = 1;i <= n;i ++){
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
			if(a[i] >= b[i] and a[i] >= c[i]){
				r1 ++;
				z1[r1] = i;
				ans += a[i];
			}
			else if(b[i] >= a[i] and b[i] >= c[i]){
				r2 ++;
				z2[r2] = i;
				ans += b[i];
			}
			else if(c[i] >= a[i] and c[i] >= b[i]){
				r3 ++;
				z3[r3] = i;
				ans += c[i];
			}
		}
		if(r1 > (n / 2)){
			for(int i = 1;i <= r1;i ++){
				shan[i] = min(a[z1[i]] - b[z1[i]],a[z1[i]] - c[z1[i]]);
			}
			sort(shan + 1,shan + 1 + r1);
			for(int i = 1;i <= (r1 - (n / 2));i ++){
				ans -= shan[i];
			}
		}
		else if(r2 > (n / 2)){
			for(int i = 1;i <= r2;i ++){
				shan[i] = min(b[z2[i]] - a[z2[i]],b[z2[i]] - c[z2[i]]);
			}
			sort(shan + 1,shan + 1 + r2);
			for(int i = 1;i <= (r2 - (n / 2));i ++){
				ans -= shan[i];
			}
		}
		else if(r3 > (n / 2)){
			for(int i = 1;i <= r3;i ++){
				shan[i] = min(c[z3[i]] - b[z3[i]],c[z3[i]] - a[z3[i]]);
			}
			sort(shan + 1,shan + 1 + r3);
			for(int i = 1;i <= (r3 - (n / 2));i ++){
				ans -= shan[i];
			}
		}
		printf("%lld\n",ans);
	}
	
	return 0;
}
