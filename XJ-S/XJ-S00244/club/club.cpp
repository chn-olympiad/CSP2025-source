#include<bits/stdc++.h>
using namespace std;
struct zx
{
	long long int a,b,c,abc;
}m[100086];
bool cmp(zx x,zx y)
{
	return x.abc>y.abc;
}
long long int x,y,z,a,b,c,max_1,finsh,f1,f2,f3;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>a;
	while(a--)
	{
		cin>>x;
		f1=x/2;
		f2=x/2;
		f3=x/2;
		finsh=0;
		for(int i=0;i<x;i++)
		{
			cin>>m[i].a>>m[i].b>>m[i].c;
			long long int max_2,min_2;
			max_2=max(m[i].a,m[i].b);
			max_2=max(max_2,m[i].c);
			min_2=min(m[i].a,m[i].b);
			min_2=min(min_2,m[i].c);
			m[i].abc=max_2-min_2;
			
			
		}
		sort(m,m+x,cmp);
		for(int i=0;i<x;i++)
		{
			max_1=max(m[i].a,m[i].b);
			max_1=max(max_1,m[i].c);
			if(max_1==m[i].a)
			{
				if(f1>0)
				{
					finsh+=max_1;
					cout<<max_1<<endl;
					max_1=0;
					f1--;
				}
				else if(f1==0)
				{
					max_1=max(m[i].b,m[i].c);
					if(max_1==m[i].b)
					{
						if(f2>0)
						{
							finsh+=max_1;
							cout<<max_1<<endl;
							max_1=0;
							f2--;
						}
						else if(f2==0)
						{
							finsh+=m[i].c;
							cout<<m[i].c<<endl;
							max_1=0;
							f3--;
						}
					}
				}
			}
			if(max_1==m[i].b)
			{
				if(f2>0)
				{
					finsh+=max_1;
					cout<<max_1<<endl;
					max_1=0;
					f2--;
				}
				else if(f2==0)
				{
					max_1=max(m[i].a,m[i].c);
					if(max_1==m[i].a)
					{
						if(f1>0)
						{
							finsh+=max_1;
							cout<<max_1<<endl;
							max_1=0;
							f1--;
						}
						else if(f2==0)
						{
							finsh+=m[i].c;
							cout<<m[i].c<<endl;
							max_1=0;
							f3--;
						}
					}
				}
			}
			if(max_1==m[i].c)
			{
				if(f3>0)
				{
					finsh+=max_1;
					cout<<max_1<<endl;
					max_1=0;
					f3--;
				}
				else if(f3==0)
				{
					max_1=max(m[i].b,m[i].a);
					if(max_1==m[i].b)
					{
						if(f2>0)
						{
							finsh+=max_1;
							cout<<max_1<<endl;
							max_1=0;
							f3--;
						}
						else if(f2==0)
						{
							finsh+=m[i].a;
							cout<<m[i].a<<endl;
							max_1=0;
							f3--;
						}
					}
				}
			}
		}
		cout<<finsh<<endl;
		for(int i=0;i<x;i++)
		{
			m[i].a=0;
			m[i].b=0;
			m[i].c=0;
		}
	}
	return 0;
}
