#include<bits/stdc++.h>
using namespace std;
struct node{
	int l1,l2;
};
node cha[100005];
bool cmp(node x,node y) {
	return x.l1>y.l1;
}
int op[5],a[100005][5],maxn[100005],mid[100005],t,n;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		int ans=0;
		scanf("%d",&n);
		for (int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if (a[i][1]>=max(a[i][2],a[i][3])) {
				maxn[i]=1;
				if (a[i][2]>a[i][3]) mid[i]=2;
				else mid[i]=3;
			}
			else if (a[i][2]>=max(a[i][1],a[i][3])) {
				maxn[i]=2;
				if (a[i][1]>a[i][3]) mid[i]=1;
				else mid[i]=3;
			}
			else {
				maxn[i]=3;
				if (a[i][1]>a[i][2]) mid[i]=1;
				else mid[i]=2;
			}
			cha[i].l1=a[i][maxn[i]]-a[i][mid[i]];cha[i].l2=i;
		}
		sort(cha+1,cha+n+1,cmp);
		op[1]=0,op[2]=0,op[3]=0;
		for (int i=1;i<=n;i++) {
			int j=cha[i].l2;
			//printf("%d ",j);
			if (op[maxn[j]]<n/2) {
				op[maxn[j]]++;
				ans+=a[j][maxn[j]];
			} else {
				op[mid[j]]++;
				ans+=a[j][mid[j]];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
