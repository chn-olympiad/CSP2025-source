#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int ans=0,bns=0,cns=0,dns=0,ens=0,fns=0,gns=0,hns=0,ins=0,jns=0;
	int cnt=0;
	for(int i=0;i<=a.length();i++)
	{
		if(a[i]=='9')
		{
			ans++;
		}
		else if(a[i]=='8')
		{
			bns++;
		}
		else if(a[i]=='7')
		{
			cns++;
		}
		else if(a[i]=='6')
		{
			dns++;
		}
		else if(a[i]=='5')
		{
			ens++;
		}
		else if(a[i]=='4')
		{
			fns++;
		}
		else if(a[i]=='3')
		{
			gns++;
		}
		else if(a[i]=='2')
		{
			hns++;
		}
		else if(a[i]=='1')
		{
			ins++;
		}
		else if(a[i]=='0')
		{
			jns++;
		}
		else
		{
			cnt++;
		}
	}	
	for(int i=1;i<=ans;i++)
	{
		cout<<"9";
	}
	for(int i=1;i<=bns;i++)
	{
		cout<<"8";
	}
	for(int i=1;i<=cns;i++)
	{
		cout<<"7";
	}
	for(int i=1;i<=dns;i++)
	{
		cout<<"6";
	}
	for(int i=1;i<=ens;i++)
	{
		cout<<"5";
	}
	for(int i=1;i<=fns;i++)
	{
		cout<<"4";
	}
	for(int i=1;i<=gns;i++)
	{
		cout<<"3";
	}
	for(int i=1;i<=hns;i++)
	{
		cout<<"2";
	}
	for(int i=1;i<=ins;i++)
	{
		cout<<"1";
	}
	for(int i=1;i<=jns;i++)
	{
		cout<<"0";
	}
	return 0;
}
