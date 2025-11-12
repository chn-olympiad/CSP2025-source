#include <bits/stdc++.h>
using namespace std;
struct xin
{
	int a,b,c;
}r[100001],tp[4][100001];
int n,t,js[4];
int qs(xin p)
{
	return max(p.a,max(p.b,p.c));
}
int qz(xin p)
{
	return max(min(p.a,p.b),max(min(p.a,p.c),min(p.b,p.c)));
}
int qx(xin p)
{
	return min(p.a,min(p.b,p.c));
}
bool cmp1(xin x,xin y)
{
	return (x.a-max(x.b,x.c))>(y.a-max(y.b,y.c));
}
//bool cmp11(xin x,xin y)
//{
//	return (x.b-x.c)>(y.b-y.c);
//}
//bool cmp12(xin x,xin y)
//{
//	return (x.b-x.c)<(y.b-y.c);
//}
bool cmp2(xin x,xin y)
{
	return (x.b-max(x.a,x.c))>(y.b-max(y.a,y.c));
}
//bool cmp21(xin x,xin y)
//{
//	return (x.a-x.c)>(y.a-y.c);
//}
//bool cmp22(xin x,xin y)
//{
//	return (x.a-x.c)<(y.a-y.c);
//}
bool cmp3(xin x,xin y)
{
	return (x.c-max(x.a,x.b))>(y.c-max(y.a,y.b));
}
//bool cmp31(xin x,xin y)
//{
//	return (x.a-x.b)>(y.a-y.b);
//}
//bool cmp32(xin x,xin y)
//{
//	return (x.a-x.b)<(y.a-y.b);
//}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t)
	{
		js[1]=0;
		js[2]=0;
		js[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>r[i].a>>r[i].b>>r[i].c;
		}
		for(int i=1;i<=n;i++)
		{
			if(qs(r[i])==r[i].a)
			{
				js[1]++;
				tp[1][js[1]]=r[i];
			}
			else if(qs(r[i])==r[i].b)
			{
				js[2]++;
				tp[2][js[2]]=r[i];
			}
			else if(qs(r[i])==r[i].c)
			{
				js[3]++;
				tp[3][js[3]]=r[i];
			}
		}
//		cout<<js[1]<<' '<<js[2]<<'\n';
		if(js[1]>n/2)
		{
			sort(tp[1]+1,tp[1]+js[1]+1,cmp1);
			for(;js[1]>n/2;js[1]--)
			{
				if(qz(tp[1][js[1]])==tp[1][js[1]].b)
				{
					js[2]++;
					tp[2][js[2]]=tp[1][js[1]];
				}
				else
				{
					js[3]++;
					tp[3][js[3]]=tp[1][js[1]];
					js[1]--;
				}
			}
//			if(js[2]>n/2)
//			{
//				sort(tp[2]+1,tp[2]+js[2]+1,cmp11);
//				for(int i=js[2];i>=n/2+1;i--)
//				{
//					js[3]++;
//					tp[3][js[3]]=tp[2][i];
//					js[2]--;
//				}
//			}
//			if(js[3]>n/2)
//			{
//				sort(tp[3]+1,tp[3]+js[3]+1,cmp12);
//				for(int i=js[3];i>=n/2+1;i--)
//				{
//					js[2]++;
//					tp[2][js[2]]=tp[3][i];
//					js[3]--;
//				}
//			}
		}
//		cout<<js[1]<<' '<<js[2]<<'\n';
		if(js[2]>n/2)
		{	
			sort(tp[2]+1,tp[2]+js[2]+1,cmp2);
			for(;js[2]>n/2;js[2]--)
			{
				if(qz(tp[2][js[2]])==tp[2][js[2]].a)
				{
					js[1]++;
					tp[1][js[1]]=tp[2][js[2]];
					js[2]--;
				}
				else
				{
					js[3]++;
					tp[3][js[3]]=tp[2][js[2]];
					js[2]--;
				}
			}
//			if(js[1]>n/2)
//			{
//				sort(tp[1]+1,tp[1]+js[1]+1,cmp21);
//				for(int i=js[1];i>=n/2+1;i--)
//				{
//					js[3]++;
//					tp[3][js[3]]=tp[1][i];
//					js[1]--;
//				}
//			}
//			if(js[3]>n/2)
//			{
//				sort(tp[3]+1,tp[3]+js[3]+1,cmp22);
//				for(int i=js[3];i>=n/2+1;i--)
//				{
//					js[1]++;
//					tp[1][js[1]]=tp[3][i];
//					js[3]--;
//				}
//			}
		}
		if(js[3]>n/2)
		{
			sort(tp[3]+1,tp[3]+js[3]+1,cmp3);
			for(;js[3]>n/2;js[3]--)
			{
				if(qz(tp[3][js[3]])==tp[3][js[3]].a)
				{
					js[1]++;
					tp[1][js[1]]=tp[3][js[3]];
					js[3]--;
				}
				else
				{
					js[2]++;
					tp[2][js[2]]=tp[3][js[3]];
					js[3]--;
				}
			}
//			if(js[1]>n/2)
//			{
//				sort(tp[1]+1,tp[1]+js[1]+1,cmp31);
//				for(int i=js[1];i>=n/2+1;i--)
//				{
//					js[2]++;
//					tp[2][js[2]]=tp[3][i];
//					js[3]--;
//				}
//			}
//			if(js[2]>n/2)
//			{
//				sort(tp[2]+1,tp[2]+js[2]+1,cmp32);
//				for(int i=js[2];i>=n/2+1;i--)
//				{
//					js[1]++;
//					tp[1][js[1]]=tp[2][i];
//					js[2]--;
//				}
//			}
		}
		int ans=0;
//		cout<<js[1]<<" "<<js[2]<<" "<<js[3]<<'\n';
		for(int i=1;i<=js[1];i++)
		{
//			cout<<tp[1][i].a<<' ';
			ans+=tp[1][i].a;
		}
//		cout<<'\n';
		for(int i=1;i<=js[2];i++)
		{
//			cout<<tp[2][i].b<<' ';
			ans+=tp[2][i].b;
		}
//		cout<<'\n';
		for(int i=1;i<=js[3];i++)
		{
//			cout<<tp[3][i].c<<' ';
			ans+=tp[3][i].c;
		}
//		cout<<'\n';
		cout<<ans<<'\n'; 
		t--;
	}
	return 0;
}
