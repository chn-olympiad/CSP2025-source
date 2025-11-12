#include<iostream>
#include<algorithm>
using namespace std;
struct ss
{
	long long ti;
	bool f=0;
};
bool v[15001];
struct sss
{
	int c,x,id;
}t[15001];
bool cmp(sss a,sss b)
{
	return a.x>b.x;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int z_1,z_2,z_3;
			cin>>z_1>>z_2>>z_3;
			t[++cnt]={1,z_1,i};
			t[++cnt]={2,z_2,i};
			t[++cnt]={3,z_3,i};
		}
		sort(t+1,t+cnt+1,cmp);
		ss a[5];
		long long s=0;
		for(int i=1;i<=cnt;i++)
		{
			if(v[t[i].id]==1)
			{
				continue;
			}
			if(a[t[i].c].f==1)
			{
				continue;
			}
			if(a[t[i].c].ti==n/2)
			{
				a[t[i].c].f=1;
			}
			a[t[i].c].ti++;
			v[t[i].id]=1;
			s+=t[i].x;
		}
		cout<<s;
	}		
	return 0;
} 
