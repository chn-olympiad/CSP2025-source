#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int T,n,q;
int mymax(int a,int b,int c)
{
	return max(a,max(b,c));
}
int mymin(int a,int b,int c)
{
	return min(a,min(b,c));
}
int mid(int a,int b,int c)
{
	return a+b+c-mymax(a,b,c)-mymin(a,b,c);
}
struct node
{
	int a,b,c,l;
	void init()
	{
		if(a>=b&&a>=c) l=0;
		if(b>=c&&b>=a) l=1;
		if(c>=a&&c>=b) l=2;
	}
	bool operator<(const node&d)const
	{
		if(l!=d.l) return l<d.l;
		else return mymax(a,b,c)-mid(a,b,c)<mymax(d.a,d.b,d.c)-mid(d.a,d.b,d.c);
	}
}A[N],P[3][N];
int tot[3];
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--)
	{
		tot[0]=tot[1]=tot[2]=0;
		scanf("%lld",&n);
		int res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&A[i].a,&A[i].b,&A[i].c);
			A[i].init();
			P[A[i].l][++tot[A[i].l]]=A[i];
			res+=A[i].l==0?A[i].a:(A[i].l==1?A[i].b:A[i].c);
		}
		if(tot[0]>n/2)
		{
			for(int i=1;i<=tot[0];i++)
				A[i]=P[0][i];
			sort(A+1,A+1+tot[0]);
			for(int i=1;i<=tot[0]-n/2;i++)
				res=res-mymax(A[i].a,A[i].b,A[i].c)+mid(A[i].a,A[i].b,A[i].c);
		}else if(tot[1]>n/2)
		{
			for(int i=1;i<=tot[1];i++)
				A[i]=P[1][i];
			sort(A+1,A+1+tot[1]);
			for(int i=1;i<=tot[1]-n/2;i++)
				res=res-mymax(A[i].a,A[i].b,A[i].c)+mid(A[i].a,A[i].b,A[i].c);
		}else if(tot[2]>n/2)
		{
			for(int i=1;i<=tot[2];i++)
				A[i]=P[2][i];
			sort(A+1,A+1+tot[2]);
			for(int i=1;i<=tot[2]-n/2;i++)
				res=res-mymax(A[i].a,A[i].b,A[i].c)+mid(A[i].a,A[i].b,A[i].c);
		}
		printf("%lld\n",res);
	}
	return 0;
}
