#include<bits/stdc++.h>
using namespace std;
int main ()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[100000],num;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    for(int i=1;i<=s.size();i++)
	{
		if(s[i]='1')
		{
			num++;
		}
	}
	if(num==m)
	{
		for(int i=1;i<=n;i++)
	    {
			for(int j=1;j<=n;j++)
			{
				if(a[j]>a[i])
				{
					swap(a[j],a[i]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			
		}
	}
	while(num!=m)
	{
		
	}
	return 0;
}
