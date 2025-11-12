#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,s,cn,a[5],a1[N],a2[N],b1[N],b2[N],c[5],i,j;
unsigned long long m; 
bool u[N];
struct ab{int a,b;}S[N];
bool cmp(ab x,ab y)
{return x.b<y.b;}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		m=cn=c[1]=c[2]=c[3]=0;
		for(cin>>n,i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a[1],&a[2],&a[3]);
			a2[i]=j=max(max(a[1],a[2]),a[3]);
			if(a[1]==j)
			{
				a1[i]=1;
				if(a[2]>=a[3])
					b1[i]=2,b2[i]=a[2];
				else b1[i]=3,b2[i]=a[3];
			}
			if(a[2]==j)
			{
				a1[i]=2;
				if(a[1]>=a[3])
					b1[i]=1,b2[i]=a[1];
				else b1[i]=3,b2[i]=a[3];
			}
			if(a[3]==j)
			{
				a1[i]=3;
				if(a[1]>=a[2])
					b1[i]=1,b2[i]=a[1];
				else b1[i]=2,b2[i]=a[2];
			}
			c[a1[i]]++,S[i].a=i;
			S[i].b=a2[i]-b2[i];
		}
		sort(S+1,S+n+1,cmp);
		if(c[1]>n/2)cn=1;
		if(c[2]>n/2)cn=2;
		if(c[3]>n/2)cn=3;
		s=c[cn]-n/2;
		if(cn!=0)
		for(i=1;i<=n;i++)
			if(a1[S[i].a]==cn)
			{
				s--,u[S[i].a]=1;
				if(s==0)break;
			}
		for(i=1;i<=n;i++)
			if(u[i])m+=b2[i];
			else m+=a2[i];
		printf("%d\n",m);
		for(i=1;i<=n;i++)
			u[i]=0;
	}return 0;
}
