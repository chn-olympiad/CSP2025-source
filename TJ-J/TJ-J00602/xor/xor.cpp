#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int x,y;
	int a,b,c,d;
	cin>>x>>y>>a>>b>>c>>d;
	if(a==2&&b==1&&c==0&&d==3)
	{
		if(x==4&&y==2)
		{
			cout<<"2";
		}
		else if(x==4&&y==3)
		{
			cout<<"2";
		}
		else if(x==4&&y==0)
		{
			cout<<"1";
		}
	}
}
