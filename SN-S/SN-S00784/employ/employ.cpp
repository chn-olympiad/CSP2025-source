#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,z=1,c[1000],cpan=0,span=0;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++)
	{
		cin >> c[i];
		z=z*i;
		if(c[i]==0) cpan=1;
	}
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]==0) span=1;
		}
		
		if((span!=1)&&(cpan!=1)) cout << (z%998244353) <<endl;
			
		else cout << 0 <<endl;
	}
	return 0;
}
