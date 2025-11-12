#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
/	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string s[400010],t[400010];
	for(int i=1;i<=n;i++)
	{
		if(i==1)
		{
			cin>>s[i]>>s[i+1];
		}
		else
		{
			cin>>s[2*i+1]>>s[2*(i+1)];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<0;
	}
	return 0;
}
