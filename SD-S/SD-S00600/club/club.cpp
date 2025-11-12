#include<bits/stdc++.h>
using namespace std;
struct mem
{
	int a1,a2,a3;
}m[100010];
int f[100010];
bool cmpa(mem a,mem b)
{
	return a.a1>b.a1;
}
int wmax(int a,int b,int c)
{
	if(a>=b)
	{
		if(c>=a)
			return 3;
		else
			return 1;
	}
	else
	{
		if(c>=b)
			return 3;
		else
			return 2;
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		int wm=0,n,lim,a_jd=0,ans=0,l1=0,l2=0,l3=0;
		cin>>n;
		lim=n/2;
		for(int i=1;i<=n;i++)
		{
			cin>>m[i].a1>>m[i].a2>>m[i].a3;
			if(m[i].a2==0&&m[i].a3==0)
				a_jd++;
		}
		if(a_jd==n)
		{
			sort(m+1,m+n+1,cmpa);
			for(int i=1;i<=lim;i++)
				ans+=m[i].a1;
			cout<<ans<<endl;
			continue;
		}//A 5pts
		for(int i=1;i<=n;i++)
		{
		
			if(l2<lim&&l3<lim&&l1<lim)
			{
				f[i]=f[i-1]+max(max(m[i].a1,m[i].a2),m[i].a3);
				wm=wmax(m[i].a1,m[i].a2,m[i].a3);
				if(wm==1)
					l1++;
				else if(wm==2)
					l2++;
				else
					l3++;
//				for(int x=1;x<=n;x++)
//					cout<<f[x]<<" ";
//				cout<<endl;
//				cout<<l1<<" "<<l2<<" "<<l3<<endl;
//				cout<<wm<<endl; f[i-1]-m[j].a1+m[i].a1+max(m[j].a2,m[j].a3)
			}
			else
			{
				for(int j=1;j<i;j++)
				{
					if(l1==lim)
					{
						f[i]=max(max(max(f[i-1]-m[j].a1+m[i].a1+max(m[j].a2,m[j].a3),f[i-1]+m[i].a2),f[i-1]+m[i].a3),f[i]);
					}
				    if(l2==lim)
					{
						f[i]=max(max(max(f[i-1]+m[i].a1,f[i-1]+m[i].a2-m[j].a2+max(m[j].a1,m[j].a3)),f[i-1]+m[i].a3),f[i]);
					}
					if(l3==lim)
					{
						f[i]=max(max(max(f[i-1]+m[i].a1,f[i-1]+m[i].a2),f[i-1]+m[i].a3-m[j].a3+max(m[j].a2,m[j].a1)),f[i]);
					}		
				}
			}
//			for(int x=1;x<=n;x++)
//				cout<<f[x]<<" ";
//			cout<<endl;	 
		}
//		cout<<f[1]<<" "<<f[2]<<endl;
		ans=f[n];
		cout<<ans<<endl;
//		cout<<l1<<" "<<l2<<" "<<l3<<endl;
		for(int i=1;i<=n;i++)
		{
			m[i].a1=0;m[i].a2=0;m[i].a3=0;
			f[i]=0;
		}
	}
	return 0;
}
