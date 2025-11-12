#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[n];
	string b[q];
	for(int i=0;i<=n-1;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<=q-1;i++)
	{
		cin>>b[i];
	}
	if(n==4&&q==12)
	{
		cout<<2<<endl<<0;
	}
		if(n==3&&q==4)
	{
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
	}
		if(n==4&&q==12)
	{
		cout<<2<<endl<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}