#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][3],cnt[3],bst[100005],f[100005],ans,b,tag,lst[100005],k;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		b=n>>1;
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		for(int i=1;i<=n;i++)scanf("%lld%lld%lld",&a[i][0],&a[i][1],&a[i][2]);
		for(int i=1;i<=n;i++){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
				cnt[0]++;
				bst[i]=1;
				ans+=a[i][0];
				f[i]=min(a[i][0]-a[i][1],a[i][0]-a[i][2]);
			}else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2]){
				cnt[1]++;
				bst[i]=2;
				ans+=a[i][1];
				f[i]=min(a[i][1]-a[i][0],a[i][1]-a[i][2]);
			}else{
				cnt[2]++;
				bst[i]=3;
				ans+=a[i][2];
				f[i]=min(a[i][2]-a[i][1],a[i][2]-a[i][0]);
			}
		}
		if(cnt[0]>b)tag=1;
		else if(cnt[1]>b)tag=2;
		else if(cnt[2]>b)tag=3;
		if(tag>0){
			k=0;
			for(int i=1;i<=n;i++){
				if(bst[i]==tag)lst[++k]=f[i];
			}
			sort(lst+1,lst+k+1);
			for(int i=cnt[tag-1]-b;i>0;i--)ans-=lst[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
