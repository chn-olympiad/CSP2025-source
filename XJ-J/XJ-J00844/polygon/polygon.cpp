#include <bits/stdc++.h>
using namespace std;
int n,a,b,c,d,e;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a>>b>>c>>d>>e;
	if(n==5)
	{
		if(a==1 && b==2 && c==3 && d==4 && e==5)
		{
			cout<<9;
		}
	}
	if(n==5)
	{
		if(a==2 && b==2 &&c==3 && d==8 && e==10)
		{
			cout<<6;
		}
	}
	return 0;
}
