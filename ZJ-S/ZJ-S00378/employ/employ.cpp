#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[501]={},cnt=1,now=1;
	char c[500]={};
	cin>>n>>m;
	cin>>c;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i = 0;i<=n-1;i++)
	{
		if(c[i]=='1')
		{
			cnt*=now++;
		}
	}
	if(now<m)
	{
		cout<<0;
	}
	else
	{
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
