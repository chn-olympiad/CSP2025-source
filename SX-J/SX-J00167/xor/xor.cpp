#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	string s;
	int x,sum=0,m;
	cin>>x;
	cin>>s;
	for(int i=1;i<=x;i++)
	{
	cin>>m;
	if(m>sum)
	{
		sum=m;
	}
	}
	cout<<sum-1;
	return 0;
}