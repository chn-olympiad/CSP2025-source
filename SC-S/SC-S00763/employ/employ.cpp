#include<bits/stdc++.h>
using namespace std;
int n,m;
int q,v,f;
string s;
int c[1000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int p;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=s.length();i++)
	{
		v=n;
		q=0;
		f=0;
		int j=i;
		for(;j<=s.length();j++)
		{
			if(int(s[j-1])==48)
			{
				v--;
				q++;
			}
			if(q>=c[j]&&s[j-1]=='1')
			{
				v--;
				q++;
			}
			if(j==s.length())
			{
				j=1;
			}
			f++;
			if(f==s.length())
			{
				break;
			}
		}
		if(v>=m)
		{
			p++;
		}	
	}
	cout<<p;
	return 0;
}