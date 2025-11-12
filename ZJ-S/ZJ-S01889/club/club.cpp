#include<bits/stdc++.h>
using namespace std;
const int MS=1e5+5;
int T,n,ans;
int a[MS][5],prf[MS],cnt[5],t[MS];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(cnt,0,sizeof(cnt));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				prf[i]=1;
				cnt[1]++;
				ans+=a[i][1];
			}else
			if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				prf[i]=2;
				cnt[2]++;
				ans+=a[i][2];
			}else
			{
				prf[i]=3;
				cnt[3]++;
				ans+=a[i][3];
			}
		}
		int opt=0;
		for(int i=1;i<=3;i++)
			if(cnt[i]>n/2)opt=i;
		if(opt==0){
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(prf[i]==opt){
				cnt[0]++;
				int minn=1e9;
				for(int j=1;j<=3;j++)
					if(opt!=j)minn=min(minn,abs(a[i][j]-a[i][opt]));
				t[cnt[0]]=minn;
			}
		}
		sort(t+1,t+cnt[0]+1);
		for(int i=1;i<=cnt[opt]-n/2;i++)
			ans-=t[i];
		printf("%d\n",ans);
	}
	return 0;
}
