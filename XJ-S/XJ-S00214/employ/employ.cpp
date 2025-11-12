#include<bits/stdc++.h>
using namespace std;
int n,m,flag=1,sum=1;
string s;
int c[505];
int main()
{
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1')
		flag=0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(flag==1)
	{
		for(int i=1;i<=m;i++)
			sum*=i;
		cout<<sum;
	}
	return 0;
}

