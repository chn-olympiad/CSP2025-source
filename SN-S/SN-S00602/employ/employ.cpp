#include <bits/stdc++.h>
using namespace std;
int n,m,a[500],c[500],ans;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		int cnt=s[i];
		a[i]=cnt-48;
	}
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
	}
	sort(c,c+n);
	int err=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==0||err>=c[i])
		{
			err++;
		}
		else
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
