#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T;
int n;
ll ans;
struct o
{
	int val,id;
};
int a[100005],b[100005],c[100005];
int f[100005];
bool cmp(o A,o B)
{
	if(A.val!=B.val)return A.val>B.val;
	return A.id<B.id;
}
//struct node
//{
//	int a,b,c;
//	operator < (const node p) const
//	{
//		return max(abs(a-b),max(abs(b-c),abs(a-c)))>max(abs(p.a-p.b),max(abs(p.b-p.c),abs(p.a-p.c)));
//	}
//};
//priority_queue<node>q;
o ab[100005],bc[100005],ac[100005];
//bool cmp(int A,int B)
//{
//	return A>B;
//}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		bool flag2=0,flag3=0;
		for(int i=1;i<=n;i++)
		{
			int ta,tb,tc;
			cin>>ta>>tb>>tc;
			a[i]=ta;b[i]=tb;c[i]=tc;
			if(b[i])flag2=1;
			if(c[i])flag3=1;
			ab[i].val=ta-tb;
			bc[i].val=tb-tc;
			ac[i].val=ta-tc;
			ab[i].id=ac[i].id=bc[i].id=i;
		}
		ans=0;
		if(!flag2&&!flag3)
		{
			sort(a+1,a+n+1);
			for(int i=n/2+1;i<=n;i++)
			{
				ans+=a[i];
			}
			cout<<ans<<'\n';
		}
		else if(!flag3)
		{
			sort(ab+1,ab+n+1,cmp);
			for(int i=1;i<=n/2;i++)
			{
				ans+=a[ab[i].id];
			}
			for(int i=n/2+1;i<=n;i++)
			{
				ans+=b[ab[i].id];
			}
			cout<<ans<<'\n';
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				ans+=max(a[i],max(b[i],c[i]));
			}
			cout<<ans<<'\n';
		}
//		sort(ab+1,ab+n+1,cmp);
//		sort(ac+1,ac+n+1,cmp);
//		sort(bc+1,bc+n+1,cmp);
//		int Ab=1,Ac=1,Bc=1,aB=n,aC=n,bC=n;
//		int az=0,bz=0,cz=0;
//		ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			while(f[ab[Ab].id]==1)Ab++;
//			while(f[ab[aB].id]==1)aB--;
//			while(f[ac[Ac].id]==1)Ac++;
//			while(f[ac[aC].id]==1)aC--;
//			while(f[bc[Bc].id]==1)Bc++;
//			while(f[bc[bC].id]==1)bC--;
//			int mmax=0,nage=1;
//				if(az<(n/2)&&mmax<ab[Ab].val)
//				{
//					mmax=ab[Ab].val;
//					nage=1;
//				}
//				if(bz<(n/2)&&mmax<-ab[aB].val)
//				{
//					mmax=-ab[aB].val;
//					nage=2;
//				}
//				if(az<(n/2)&&mmax<ac[Ac].val)
//				{
//					mmax=ac[Ac].val;
//					nage=3;
//				}
//				if(cz<(n/2)&&mmax<-ac[aC].val)
//				{
//					mmax=-ac[aC].val;
//					nage=4;
//				}
//				if(bz<(n/2)&&mmax<bc[Bc].val)
//				{
//					mmax=bc[Bc].val;
//					nage=5;
//				}
//				if(cz<(n/2)&&mmax<-bc[bC].val)
//				{
//					mmax=-bc[bC].val;
//					nage=6;
//				}
//			if(nage==1)
//			{
//				f[ab[Ab].id]=1;
//				ans+=a[ab[Ab].id];
//				az++;
//			}
//			else if(nage==2)
//			{
//				f[ab[aB].id]=1;
//				ans+=b[ab[aB].id];
//				bz++;
//			}
//			else if(nage==3)
//			{
//				f[ac[Ac].id]=1;
//				ans+=a[ac[Ac].id];
//				az++;
//			}
//			else if(nage==4)
//			{
//				f[ac[aC].id]=1;
//				ans+=c[ac[aC].id];
//				cz++;
//			}
//			else if(nage==5)
//			{
//				f[bc[Bc].id]=1;
//				ans+=b[bc[Bc].id];
//				bz++;
//			}
//			else if(nage==6)
//			{
//				f[bc[bC].id]=1;
//				ans+=c[bc[bC].id];
//				cz++;
//			}
//		}
//		cout<<ans<<'\n';
//		sort(a+1,a+n+1,cmp);
//		sort(b+1,b+n+1,cmp);
//		sort(c+1,c+n+1,cmp);
//		int ap=1,bp=1,cp=1;
//		int az=0,bz=0,cz=0;
//		ans=0;
//		for(int i=1;i<=n;i++)
//		{
//			while(f[a[ap].id]==1)ap++;
//			while(f[b[bp].id]==1)bp++;
//			while(f[c[cp].id]==1)cp++;
//			if(az<(n/2)&&a[ap].val>=b[bp].val&&a[ap].val>=c[cp].val)
//			{
//				f[a[ap].id]=1;
//				ans+=a[ap].val;
//				ap++;
//				az++;
//			}
//			else if(bz<(n/2)&&b[bp].val>=a[ap].val&&b[bp].val>=c[cp].val)
//			{
//				f[b[bp].id]=1;
//				ans+=b[bp].val;
//				bp++;
//				bz++;
//			}
//			else if(cz<(n/2)&&c[cp].val>=a[ap].val&&c[cp].val>=b[bp].val)
//			{
//				f[c[cp].id]=1;
//				ans+=c[cp].val;
//				cp++;
//				cz++;
//			}
//		}
//		cout<<ans<<'\n';
		for(int i=1;i<=n;i++)
		{
			f[i]=0;
		}
	}
	return 0;
}
