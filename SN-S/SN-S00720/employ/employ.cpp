#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[110];

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	int ans=1;
	if(m==n)
	{
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0'){
				cout<<0<<endl;
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			ans=ans*i;
		}
		cout<<ans<<endl;
	}
	return 0;
}
