#include<bits/stdc++.h>
using namespace std;
long long v[100010],d[100010],n,t;
struct Node
{
	long long z,hao;
}a[100010],b[100010],c[100010];
struct HAO
{
	long long z,hao,shu;
}s[1000010];
bool cmp(Node x,Node y)
{
	return x.z>y.z;
}
bool cmpp(HAO x,HAO y)
{
	return x.z>y.z;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		long long sum=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].z>>b[i].z>>c[i].z;
			a[i].hao=b[i].hao=c[i].hao=i;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		for(int i=1;i<=n;i++)
		{
			s[i].z=a[i].z;
			s[i].shu=0;
			s[i].hao=a[i].hao;
		}
		for(int i=1;i<=n;i++)
		{
			s[i+n].z=b[i].z;
			s[i+n].shu=1;
			s[i+n].hao=b[i].hao;
		}
		for(int i=1;i<=n;i++)
		{
			s[i+n*2].z=c[i].z;
			s[i+n*2].shu=2;
			s[i+n*2].hao=c[i].hao;
		}
		sort(s+1,s+1+n+n+n,cmpp);
		for(int i=1;i<=n*3;i++)
		{
			if(v[s[i].hao]==0&&d[s[i].shu]<n/2)
			{
				sum+=s[i].z;
				v[s[i].hao]=1;
				d[s[i].shu]++;
			}
		}
		for(int i=1;i<=n*3;i++)v[s[i].hao]=d[s[i].shu]=0;
		cout<<sum<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}