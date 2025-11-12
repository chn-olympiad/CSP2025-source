#include<bits/stdc++.h>
using namespace std;
int t,n,ans,c[9],d[9][100005];
void check(int j)
{
	for(int i=1;c[j]>n/2;i++,c[j]--)
		ans-=d[j][i];
//	return 0;
}
int main()
{
	freopen("club.in","r",stdin);
//	freopen("club5.in","r",stdin);
	freopen("club.out","w",stdout);
	for(scanf("%d",&t);t--;ans=0,memset(c,0,sizeof c))
	{
		scanf("%d",&n);
		memset(d,0x3f,sizeof d);
		for(int i=1,x,y,z,n1,n2,n3;i<=n;i++)
			scanf("%d%d%d",&x,&y,&z),n1=1,n2=2,n3=3,
			x<y?swap(x,y),n1=2,n2=1:0,
			x<z?swap(x,z),swap(n1,n3),0:0,
			y<z?swap(y,z),swap(n2,n3),0:0,
			ans+=x,c[n1]++,d[n1][i]=x-y;
		sort(d[1]+1,d[1]+n+1);
		sort(d[2]+1,d[2]+n+1);
		sort(d[3]+1,d[3]+n+1);
//		max(c[1],max(c[2],c[3]))>n/2?
//			c[1]>c[2] && c[1]>c[3]?
//				check(1):
//			c[2]>c[1] && c[2]>c[3]?
//				check(2):
//				check(3):
//			0;
		check(1);check(2);check(3);
//		printf("%d ",max(c[1],max(c[2],c[3]))>n/2);
		printf("%d\n",ans);
	}
	return 0;
}
