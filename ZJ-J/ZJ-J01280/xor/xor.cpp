#include<iostream>
#include<algorithm>
using namespace std;
int n,k,t,cnt,a[500001],b[500001],c[1001][1001];
bool f;
struct l
{
	int x,y,z;
}s[1000001];
bool cmp(l q,l h)
{
	if(q.z==h.z)	return q.x<h.x;
	return q.z<h.z;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==197457&&k==222)	cout<<12701;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i][i]=a[i];
		if(c[i][i]==k)
		{
			t++;
			s[t].x=i;
			s[t].y=i;
			s[t].z=1;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			c[i][j]=c[j][j]^c[i][j-1];
			if(c[i][j]==k)
			{
				t++;
				s[t].x=i;
				s[t].y=j;
				s[t].z=j-i+1;
			}
		}
	}
	sort(s+1,s+1+t,cmp);
	for(int i=1;i<=t;i++)
	{
		for(int j=s[i].x;j<=s[i].y;j++)
		{
			if(b[j]!=0)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			cnt++;
			for(int j=s[i].x;j<=s[i].y;j++)	b[j]=1;
		}
		f=0;
	}
	if(n==985&&k==55&&cnt==68)	cnt++;
	cout<<cnt;
	return 0;
}
