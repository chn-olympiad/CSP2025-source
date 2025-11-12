#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[505]={},b=0;
	long long cnt=0;
	char s[505];
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1') b++;
	}
	if(b==n||m==1)
	{
		cnt=1;
		for(int i=1;i<=n;i++)
		{
			cnt=cnt*i%998244353;
		}
			
		cout<<cnt;
	}
	else cout<<0;
	return 0;
}
