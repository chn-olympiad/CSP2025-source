#include<bits/stdc++.h>
using namespace std;
int a[501000];
struct S
{
	int x,y;
}b[501000];
bool cmp(S c,S d)
{
	return c.y<d.y;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum^=a[j];
			if(sum==k)
			{
				b[++cnt].x=i,b[cnt].y=j;
				break;
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	int cct=0,now=0;
	for(int i=1;i<=cnt;i++)
	{
		if(b[i].x>now)
		{
			cct++;
			now=b[i].y;
		}
	}
	cout<<cct;
	return 0;
}
