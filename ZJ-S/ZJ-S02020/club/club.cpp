#include<bits/stdc++.h>
using namespace std;
const int N=100010;
struct ly{
	int x,y,z;
}a[N];
int t,n,A[N],B[N],C[N];
bool cmpa(int X,int Y)
{
	return (a[X].x-max(a[X].y,a[X].z))>(a[Y].x-max(a[Y].y,a[Y].z));
}
bool cmpb(int X,int Y)
{
	return (a[X].y-max(a[X].x,a[X].z))>(a[Y].y-max(a[Y].x,a[Y].z));
}
bool cmpc(int X,int Y)
{
	return (a[X].z-max(a[X].y,a[X].x))>(a[Y].z-max(a[Y].y,a[Y].x));
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		int cnta=0,cntb=0,cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
		for(int i=1;i<=n;i++)
		{
			if(a[i].x>=a[i].y&&a[i].x>=a[i].z)A[++cnta]=i;
			else if(a[i].y>=a[i].z&&a[i].y>=a[i].x)B[++cntb]=i;
			else if(a[i].z>=a[i].x&&a[i].z>=a[i].y)C[++cntc]=i;
		}
		int maxn=n/2;
		int ans=0;
		if(cnta<=maxn&&cntb<=maxn&&cntc<=maxn)
		{
			for(int i=1;i<=cnta;i++)ans+=a[A[i]].x;
			for(int i=1;i<=cntb;i++)ans+=a[B[i]].y;
			for(int i=1;i<=cntc;i++)ans+=a[C[i]].z;
		}
		else if(cnta>maxn)
		{
			sort(A+1,A+cnta+1,cmpa);
			for(int i=cnta;i>=maxn+1;i--)ans=ans+max(a[A[i]].y,a[A[i]].z);
			for(int i=1;i<=cntb;i++)ans+=a[B[i]].y;
			for(int i=1;i<=cntc;i++)ans+=a[C[i]].z;
			for(int i=1;i<=maxn;i++)ans+=a[A[i]].x;
		}
		else if(cntb>maxn)
		{
			sort(B+1,B+cntb+1,cmpb);
			for(int i=cntb;i>=maxn+1;i--)ans=ans+max(a[B[i]].x,a[B[i]].z);
			for(int i=1;i<=cnta;i++)ans+=a[A[i]].x;
			for(int i=1;i<=cntc;i++)ans+=a[C[i]].z;
			for(int i=1;i<=maxn;i++)ans+=a[B[i]].y;
		}
		else if(cntc>maxn)
		{
			sort(C+1,C+cntc+1,cmpc);
			for(int i=cntc;i>=maxn+1;i--)ans+=max(a[C[i]].y,a[C[i]].x);
			for(int i=1;i<=cntb;i++)ans+=a[B[i]].y;
			for(int i=1;i<=cnta;i++)ans+=a[A[i]].x;
			for(int i=1;i<=maxn;i++)ans+=a[C[i]].z;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
