#include<bits/stdc++.h>

using namespace std;
const int N=1e5+15;
int t,n;
//int dp[205][205][205];
struct T{
	int k1,k2,k3;
}a[N];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
bool cmp1(T x,T y)
{
	return x.k1>y.k1;
}
bool cmp2(T x,T y)
{
	return max(x.k1,x.k2)>max(y.k1,y.k2);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--)
	{
		for(int i=1;i<=N-2;i++) a[i].k1=0,a[i].k2=0,a[i].k3=0;
//		for(int i=0;i<=200;i++)
//		for(int j=0;j<=200;j++)
//		for(int k=0;k<=200;k++) dp[i][j][k]=0;
		n=read();
		int flag1=1,flag2=1;
		for(int i=1;i<=n;i++) 
		{
			a[i].k1=read(),a[i].k2=read(),a[i].k3=read();
			if(a[i].k3!=0) flag1=0;
			if(a[i].k2!=0||a[i].k3!=0) flag2=0;
		}
		if(flag2) //A
		{
			sort(a+1,a+n+1,cmp1);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			ans+=a[i].k1;
			printf("%d\n",ans);
			continue;
		}
//		else if(flag1) //B 
//		{
//			sort(a+1,a+n+1,cmp2);
//			int c1=0,c2=0,ans=0;
//			for(int i=1;i<=n;i++)
//			{
//				if(a[i].k1>a[i].k2) ans+=a[i].k1,c1++;
//				else if(a[i].k1==a[i].k2) ans+=a[i].k1; 
//			}
//		}
		
		else if(n==2)
		{
			int s1=max(a[1].k1,max(a[1].k2,a[1].k3)),s2=max(a[2].k1,max(a[2].k2,a[2].k3));
			int p1,p2,ans=0;
			if(s1==a[1].k1) p1=1;
			else if(s1==a[1].k2) p1=2;
			else p1=3;
			if(s2==a[2].k1) p2=1;
			else if(s2==a[2].k2) p2=2;
			else p2=3;
			if(p1!=p2) ans=s1+s2;
		//	printf("%d %d\n",p1,p2);
			else ans=max(a[1].k1+max(a[2].k2,a[2].k3),max(a[1].k2+max(a[2].k1,a[2].k3),a[1].k3+max(a[2].k1,a[2].k2))); 
			printf("%d\n",ans);
			continue;
		//	else ans=
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++) ans+=max(a[i].k1,max(a[i].k2,a[i].k3));
			printf("%d\n",ans);
			continue;
			
		}
	//	dp[i][j][k]=max(dp[i-1][j][k]+a[now].k1,dp[i][j-1][k]+a[now],)
	}
	return 0;
}
