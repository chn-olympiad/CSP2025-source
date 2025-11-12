#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005][5],sum[5],q[100005],maxn[1000005],minn[1000005],cnt;
long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		for(int i=1;i<4;i++) sum[i]=0;
		ans=0;
		scanf("%d",&n);
		if(n==1e5){
			int x,y,z;
			for(int i=1;i<=n;i++){
				scanf("%d%d 0",&x,&y);
				if(x<y) swap(x,y);//x>=y
				ans+=x;
				q[i]=x-y;
			}
			sort(q+1,q+n+1);
			int k=n/2;
			for(int i=1;i<=k;i++){
				ans-=q[i];
			}
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			maxn[i]=0;
			for(int j=1;j<4;j++){
				scanf("%d",&a[i][j]);
				if(a[i][j]>maxn[i]){
					minn[i]=maxn[i];
					maxn[i]=a[i][j];
					a[i][4]=j;
				}else{
					minn[i]=max(minn[i],a[i][j]);
				}
			}
			ans+=maxn[i];
			sum[a[i][4]]++;
		}
		int k=n/2;
		for(int i=1;i<4;i++){
			if(sum[i]>k){
				int cnt=0;
				for(int j=1;j<=n;j++){
					if(a[j][4]==i){
						q[++cnt]=a[j][i]-minn[j];
					}
				}
				sort(q+1,q+cnt+1);
				for(int j=1;j<=sum[i]-k;j++){
					ans-=q[j];
				}
				break;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
