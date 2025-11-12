#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int n,m,r,cnt,a[N];
bool cmp(int x,int y) {
	return x>y;
}
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for (int j=1;j<=m;j++) {
		if (j%2==1) {
			for (int i=1;i<=n;i++) {
				cnt++;
				if (a[cnt]==r) {
					printf("%d %d\n",j,i);
					break;
				}
			}
		} else {
			for (int i=n;i>0;i--) {
				cnt++;
				if (a[cnt]==r) {
					printf("%d %d\n",j,i);
					break;
				}
			}
		}
		if (a[cnt]<r) break;
	}
	return 0;
}