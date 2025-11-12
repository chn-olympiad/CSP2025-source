
#include<bits/stdc++.h>
using namespace std; 
int main(int argc, char** argv) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	string a;
	for(int i=0;i<n.size();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a+=n[i];
		}
	}
	int dan=0;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0')
		{
			dan++;
		}
	}
	if(dan==a.size())
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		int maxn=0;
		for(int j=0;j<a.size();j++)
		{
			if(a[j]>='0'&&a[j]<='9')
			{
				if(a[j]-'0'>maxn)
				{
					maxn=(a[j]-'0');
				}
			}
		}
		cout<<maxn;
		for(int j=0;j<a.size();j++)
		{
			if(a[j]-'0'==maxn)
			{
				a[j]='A';
				break;
			} 
		}
	}
	return 0;
}
