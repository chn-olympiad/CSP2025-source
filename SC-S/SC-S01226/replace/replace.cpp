#include<bits/stdc++.h>
using namespace std;
string m[200100][3];
string k[5000100][3];
long long n,q,i,j;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++)
	{
		cin>>m[i][1]>>m[i][2];
	}
	for (i=1;i<=q;i++)
	{
		long long cnt=0;
		cin>>k[i][1]>>k[i][2];
		if (k[i][1].size()!=k[i][2].size())
		{
			cout<<0<<endl;
			continue;
		}
		for (j=1;j<=n;j++)
		{
			if (k[i][1].size()<m[j][1].size())
			{
				continue;
			}
			if (k[i][1].find(m[j][1])!=-1)
			{
				string s1=k[i][1];
				long long h=k[i][1].find(m[j][1]);
				s1.replace(h,m[j][1].size(),m[j][2]);
				if (s1.find(k[i][2])!=-1)
				{
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}