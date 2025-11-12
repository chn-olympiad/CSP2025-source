#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=100010;
int n,t;
long long a[3][N];
bool st[N];
long long ans,res,u[3];
void dfs() {
	bool flag1=true;
	for (int i=1; i<=n; i++)
		if (!st[i]) {
			flag1=false;
			break;
		}
	if (flag1) {
		ans=max(ans,res);
		return;
	}
	for (int j=1; j<=n; j++) {
		if (st[j]) continue;
		for (int i=0; i<3; i++) {
			if (!st[j]&&u[i]<n/2) {
				res+=a[i][j];
				st[j]=true;
				u[i]++;
				dfs();
				st[j]=false;
				u[i]--;
				res-=a[i][j];
			}
		}
	}
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		ans=0;
		res=0;
		scanf("%d",&n);
		for (int i=1; i<=n; i++)
			scanf("%d%d%d",&a[0][i],&a[1][i],&a[2][i]);
		long long sum1=0,sum2=0,sum0=0;
		for (int i=1; i<=n; i++) sum0+=a[0][i],sum1+=a[1][i],sum2+=a[2][i];
		if (sum1==0&&sum2==0) {
			long long a0[N];
			for (int i=1; i<=n; i++) a0[i]=a[0][i];
			sort(a0+1,a0+n+1);
			for (int i=n; i>=n-n/2+1; i--) ans+=a0[i];
			printf("%lld\n",ans);
			continue;
		} else if (sum1==0&&sum0==0) {
			long long a0[N];
			for (int i=1; i<=n; i++) a0[i]=a[2][i];
			sort(a0+1,a0+n+1);
			for (int i=n; i>=n-n/2+1; i--) ans+=a0[i];
			printf("%lld\n",ans);
			continue;
		} else if(sum2==0&&sum0==0) {
			long long a0[N];
			for (int i=1; i<=n; i++) a0[i]=a[1][i];
			sort(a0+1,a0+n+1);
			for (int i=n; i>=n-n/2+1; i--) ans+=a0[i];
			printf("%lld\n",ans);
			continue;
		}
		dfs();
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




