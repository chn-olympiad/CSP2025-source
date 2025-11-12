#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,ans=0,x=0,c[501],a[501];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]>x)
			x=c[i];
		a[c[i]]++;
	}
	int i=1,j=1;
	while(j<=x&&i<=m)
	{
		while(a[j]==0)
			j++;
		ans++;
		i++;
		j++;
	}
	if(ans>m)
	{
		cout<<m;
		return 0;
	}
	cout<<ans;
	return 0;
}
