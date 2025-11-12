#include<bits/stdc++.h>
using namespace std;
int T,n,a[100005][5],p,pp,d[5][100005],cnt[5],ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			p=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=p;
			if(p==a[i][1]) pp=max(a[i][2],a[i][3]);
			else if(p==a[i][2]) pp=max(a[i][1],a[i][3]);
			else if(p==a[i][3]) pp=max(a[i][1],a[i][2]);
			if(p==a[i][1]) d[1][++cnt[1]]=p-pp;
			else if(p==a[i][2]) d[2][++cnt[2]]=p-pp;
			else if(p==a[i][3]) d[3][++cnt[3]]=p-pp;
		}
		for(int i=1;i<=3;i++){
			if(cnt[i]>n/2){
				sort(d[i]+1,d[i]+cnt[i]+1);
				for(int j=1;j<=cnt[i]-n/2;j++) ans-=d[i][j];
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
