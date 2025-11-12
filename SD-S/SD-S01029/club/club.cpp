#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int T,n;
int a[N][3],col[N],cnt[10];
int qu[N],idx,k;
LL ans;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans=0,cnt[0]=cnt[1]=cnt[2]=0;
		k=0,idx=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i) 
		{
			scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) ans+=a[i][0],col[i]=0,++cnt[0];
			else if(a[i][1]>a[i][0]&&a[i][1]>=a[i][2]) ans+=a[i][1],col[i]=1,++cnt[1];
			else if(a[i][2]>a[i][0]&&a[i][2]>a[i][1]) ans+=a[i][2],col[i]=2,++cnt[2];
		}
//		for(int i=1;i<=n;++i) cout<<col[i]<<" ";
//		cout<<endl;
//		cout<<ans<<endl;
		for(int i=0;i<3;++i)
			if(cnt[i]>n/2)
			{
				k=cnt[i];
				for(int j=1;j<=n;++j)
					if(col[j]==i)
						for(int k=0;k<3;++k)
							if(k!=i)
							{
								if(a[j][i]-a[j][k]>a[j][i]-a[j][3-k-i]) qu[++idx]=a[j][i]-a[j][3-k-i];
								else qu[++idx]=a[j][i]-a[j][k];
								break;
							}
			}
//		for(int i=1;i<=idx;++i) cout<<qu[i]<<" ";
//		cout<<endl;
		sort(qu+1,qu+idx+1);
		for(int i=1;i<=k-n/2;++i) ans-=qu[i];
		printf("%lld\n",ans);
	}
	return 0;
} 
/*1
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926*/
