#include <bits/stdc++.h>
using namespace std;
string p;
int a[1000001],cnt=0,n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>p;
	n=p.size();
	for(int i=0;i<n;i++)
	{
		if(p[i]>='0'&&p[i]<='9')
		{
			cnt++;
			a[cnt]=(int)(p[i]-'0');
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0)
	{
		cout<<0;
	}
	else
	{
		for(int i=1;i<=cnt;i++)
		{
			cout<<a[i];
		}
	}
	return 0;
}
