#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int a,b;
}b[100010];
int t,n,a[100010][4],sum[100010][4],flag,ans;
bool cmp(node xx,node yy){
	return xx.b-xx.a>yy.b-yy.a;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
				sum[i][j]=sum[i-1][j]+a[i][j];
			}
		}
		ans=0;
		for(int i=1;i<=3;i++){
			if(ans<sum[n][i]){
				ans=sum[n][i];
				flag=i;
			}
		}
		for(int i=1;i<=n;i++) b[i].a=a[i][flag];
		if(flag!=1) for(int i=1;i<=n;i++) b[i].b=max(a[i][1],a[i][5-flag]);
		else for(int i=1;i<=n;i++) b[i].b=max(a[i][2],a[i][3]);
		sort(b+1,b+n+1,cmp);
		int i=1;
		while(i<=n/2||b[i].b-b[i].a>0){
			ans+=b[i].b-b[i].a;
			i++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
