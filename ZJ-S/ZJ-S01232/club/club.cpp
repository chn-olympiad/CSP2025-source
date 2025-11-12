#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int t,n,k,a1,a2,a3,p;
long long s;
struct club
{
	int b1,b2,b3,b;
}a[100010];
struct cl
{
	int c;
}e[100010];
bool cmp(cl x,cl y)
{
	return x.c<y.c;
}
int read()
{
	char t;
	int q=0;
	while(t<'0'||t>'9')t=getchar();
	q=int(t)-48;
	t=getchar();
	while(t>='0'&&t<='9')q=q*10+int(t)-48,t=getchar();
	return q;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int u=1;u<=t;u++)
	{
		s=0,a1=a2=a3=0,k=0,p=0;
		n=read();
		for(int i=1;i<=n;i++)
		{
	    	a[i].b1=read(),a[i].b2=read(),a[i].b3=read();
		    if(a[i].b1>=a[i].b2&&a[i].b1>=a[i].b3)a1++,s+=a[i].b1,a[i].b=1;
		    else if(a[i].b2>=a[i].b1&&a[i].b2>=a[i].b3)a2++,s+=a[i].b2,a[i].b=2;
		    else a3++,s+=a[i].b3,a[i].b=3;
	    }
		if(a1>n/2)
		{
			p=a1-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].b==1)
				{
					k++;
					e[k].c=min(a[i].b1-a[i].b2,a[i].b1-a[i].b3);
				}
			}
			sort(e+1,e+k+1,cmp);
			for(int i=1;i<=p;i++)
			{
				s-=e[i].c;
			}
			cout<<s<<endl;
		}
		else if(a2>n/2)
		{
			p=a2-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].b==2)
				{
					k++;
					e[k].c=min(a[i].b2-a[i].b1,a[i].b2-a[i].b3);
				}
			}
			sort(e+1,e+k+1,cmp);
			for(int i=1;i<=p;i++)
			{
				s-=e[i].c;
			}
			cout<<s<<endl;
		}
		else if(a3>n/2)
		{
			p=a3-n/2;
			for(int i=1;i<=n;i++)
			{
				if(a[i].b==3)
				{
					k++;
					e[k].c=min(a[i].b3-a[i].b2,a[i].b3-a[i].b1);
				}
			}
			sort(e+1,e+k+1,cmp);
			for(int i=1;i<=p;i++)
			{
				s-=e[i].c;
			}
			cout<<s<<endl;
		}
		else cout<<s<<endl;
	}
	return 0;
}
