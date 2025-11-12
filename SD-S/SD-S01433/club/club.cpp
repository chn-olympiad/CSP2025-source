#include<bits/stdc++.h>
using namespace std;
long long a[200005][5];
long long d[5];
long long cha[5][200005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		long long n;
		scanf("%lld",&n);
		long long p=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++)
				scanf("%lld",&a[i][j]);
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			long long jl=-1,wei=0;
			for(int j=1;j<=3;j++)
				if(a[i][j]>jl)
				{
					jl=a[i][j];
					wei=j;
				}
			d[wei]++;
			long long jl2=999999;
			for(int j=1;j<=3;j++)
				if(j!=wei)jl2=min(jl2,jl-a[i][j]);
//			cout<<d[wei]<<' '<<wei<<' '<<jl2<<"\n";
			cha[wei][d[wei]]=jl2;
			ans+=jl;
		}
		long long fla=0,junheng;
		for(int i=1;i<=3;i++)
			if(d[i]>p)fla=i,junheng=d[i]-p;
		if(fla){
			sort(cha[fla]+1,cha[fla]+d[fla]+1);
//			cout<<d[fla]<<' '<<fla<<"\n";
			for(int i=1;i<=d[fla]-p;i++){
				ans-=cha[fla][i];
			}
		}
		printf("%lld\n",ans);
		memset(cha,0,sizeof(cha));
		memset(d,0,sizeof(d));
		memset(a,0,sizeof(a));
	}
	return 0;
} 

