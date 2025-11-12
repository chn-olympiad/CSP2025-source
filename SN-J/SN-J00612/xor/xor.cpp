#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor2.in","r",stdin);
	freopen("xor2.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int n[a];
	for(int i=0;i<a;i++)
	{
		cin>>n[i];
	}
	int c=0,d;
	int m[a-1];
	for(int i=0;i<a-1;i++)
	{
		m[i]=n[i];
		if(m[i]==b)
		{
			d=c+1;
		}
	}
	while(a!=0)
	{
		a--;
		for(int i=0;i<a;i++)
		{
			m[i]=m[i]|n[i+1+c];
			cout<<m[i]<<endl;
			if(m[i]==b)
			{
				d=c;
			}
		}
		c++;
	}
	cout<<d<<endl;
	return 0;
}
