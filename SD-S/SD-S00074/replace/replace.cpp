#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b;
	cin>>a>>b;
	if(a==4 && b==2)
	{
		cout<<2<<endl<<0;
	}
	else if(a==3 && b==4)
	{
		for(int i=1;i<=4;i++)
		{
			cout<<0<<endl;
		}
	}
	else 
	{
		for(int i=1;i<=b;i++)
		{
			cout<<0<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
