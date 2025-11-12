#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],b[100005],c[4];
struct node {
	int id, val, to;
	bool operator < (const node &y) const {
		return val<y.val;
	}
} tmp[100005];
void solve(int x, int y, int z) {
	for(int i=1,j=0; i<=n; i++) {
		if(b[i]==x) {
			tmp[++j].id=i;
			if(a[i][y]>a[i][z]) tmp[j].to=y, tmp[j].val=a[i][x]-a[i][y];
			else tmp[j].to=z, tmp[j].val=a[i][x]-a[i][z];
		}
	}
	sort(tmp+1,tmp+1+c[x]);
	int m=c[x]-n/2;
	for(int i=1; i<=m; i++) {
		c[x]--;
		c[tmp[i].to]++;
		b[tmp[i].id]=tmp[i].to;
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		memset(c,0,sizeof c);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=3; j++)
				scanf("%d",&a[i][j]);
		for(int i=1; i<=n; i++) {
			int maxj, mx=0;
			for(int j=1; j<=3; j++)
				if(a[i][j]>mx)
					mx=a[i][j], maxj=j;
			b[i]=maxj, c[maxj]++;
		}
		if(c[1]>n/2) solve(1,2,3);
		if(c[2]>n/2) solve(2,1,3);
		if(c[3]>n/2) solve(3,1,2);
		long long ans=0;
		for(int i=1; i<=n; i++) ans+=a[i][b[i]];
		printf("%lld\n",ans);
	}

	return 0;
}