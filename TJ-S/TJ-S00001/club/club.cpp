#include<bits/stdc++.h>
using namespace std;
long long t,n,d[5],h;
struct cc{
	int x,d,x2,d2;
}a[100010];
bool cmp(cc a,cc b)
{
	if(a.x==b.x) return a.x2<b.x2;
	else return a.x>b.x;
}
bool cmp2(cc a,cc b)
{
	if(a.x2==b.x2) return a.x>b.x;
	else return a.x2<b.x2;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int a1,a2,a3;
			cin>>a1>>a2>>a3;
			a[i].x=max(a1,max(a2,a3));
			int f=min(a1,min(a2,a3));
			a[i].x2=a1+a2+a3-a[i].x-f;
			if(a[i].x==a1)
			{
				a[i].d=1;
			}
			else if(a[i].x==a2)
			{
				a[i].d=2;
			}
			else if(a[i].x==a3)
			{
				a[i].d=3;
			}
			if(a[i].x2==a1)
			{
				a[i].d2=1;
			}
			else if(a[i].x2==a2)
			{
				a[i].d2=2;
			}
			else if(a[i].x2==a3)
			{
				a[i].d2=3;
			}
		}
		sort(a+1,a+n+1,cmp);
		d[1]=d[2]=d[3]=0,h=0;
		for(int i=1;i<=n;i++)
		{
			if(d[a[i].d]<n/2)
			{
				h+=a[i].x;
				d[a[i].d]++;
			}
			else
			{
				if(d[a[i].d2]<n/2)
				{
					h+=a[i].x2;
					d[a[i].d2]++;
				}
			}
		}
		sort(a+1,a+n+1,cmp2);
		d[1]=d[2]=d[3]=0;
		long long h2=0;
		for(int i=1;i<=n;i++)
		{
			if(d[a[i].d]<n/2)
			{
				h2+=a[i].x;
				d[a[i].d]++;
			}
			else
			{
				if(d[a[i].d2]<n/2)
				{
					h2+=a[i].x2;
					d[a[i].d2]++;
				}
			}
		}
		h=max(h,h2);
		cout<<h<<endl;
//		for(int i=1;i<=n;i++)
//		{
//			if(d[a[i].d]<n/2)
//			{
//				h+=a[i].x;
//				v[++e]=i;
//				d[a[i].d]++;
//			}
//			else
//			{
//				int q=0,p=0;
//				for(int j=1;j<=e;j++)
//				{
//					if(a[v[j]].x<a[v[j]].x2+a[i].x)
//					{
//						if(p<a[v[j]].x2+a[i].x)
//						{
//							p=a[v[j]].x2+a[i].x;
//							q=j;
//						}
//					}
//				}
//				if(q!=0) 
//				{
//					d[a[v[q]].d2]++;
//					h-=a[v[q]].x;
//					h+=a[v[q]].x2+a[i].x;
//					v[q]=i;
//				}
//				if(d[a[i].d2]<n/2)
//				{
//					h+=a[i].x2;
//					d[a[i].d2]++;
//				}
//			}
//		}
	}
} 
