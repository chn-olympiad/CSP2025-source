#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5+5;
int n, a[N][4],T,zhi[N][4];
struct Peo {
	int idd, zhi;
} q1[N], q2[N], q3[N];
bool cmp(Peo x, Peo y) {
	return x.zhi > y.zhi;
}
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>T;
	for(int t=1;t<=T;t++){
		scanf("%d", &n);
		int c1 = 0, c2 = 0, c3 = 0, l = n / 2,ans=0;
		for (int i = 1; i <= n; i++) {
			int x1, x2, x3;
			scanf("%d%d%d", &x1, &x2, &x3);
			zhi[i][1]=x1,zhi[i][2]=x2,zhi[i][3]=x3;	
			a[i][1] =min(x1-x2,x1-x3), a[i][2] =min(x2-x1,x2-x3), a[i][3] =min(x3-x2,x3-x1);
			int mn = max({x1,x2,x3});
			if (mn == x1) {
				q1[++c1] = {i, a[i][1]};
				ans+=x1;
			} else if (mn == x2) {
				q2[++c2] = {i, a[i][2]};
				ans+=x2;
			} else if (mn == x3) {
				q3[++c3] = {i, a[i][3]};
				ans+=x3;
			}
		}
		sort(q1 + 1, q1 + c1 + 1,cmp);
		sort(q2 + 1, q2 + c2 + 1,cmp);
		sort(q3 + 1, q3 + c3 + 1,cmp);
		if (c1 > l) {
			for (int i = c1; i > l; i--) {
				int k=q1[i].idd;
				if(zhi[k][2]>zhi[k][3]){	
					ans-=zhi[k][1];
					ans+=zhi[k][2];
				}
				else{
					ans-=zhi[k][1];
					ans+=zhi[k][3];
				}
			}
		}
		if (c2 > l) {
			for (int i = c2; i > l; i--) {
				int k=q2[i].idd;
				if(zhi[k][1]>zhi[k][3]){
					ans-=zhi[k][2];
					ans+=zhi[k][1];
				}
				else{
					ans-=zhi[k][2];
					ans+=zhi[k][3];
				}
			}
		}
		if (c3 > l) {
			for (int i = c3; i > l; i--) {
				int k=q3[i].idd;
				if(zhi[k][1]>zhi[k][2]){
					ans-=zhi[k][3];
					ans+=zhi[k][1];
				}
				else{
					ans-=zhi[k][3];
					ans+=zhi[k][2];
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}