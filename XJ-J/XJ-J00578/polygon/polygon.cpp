#include<iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n>=3)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int maxi=0;
		if(a*2>maxi) maxi=a*2;
		if(b*2>maxi) maxi=b*2;
		if(c*2>maxi) maxi=c*2;
		if((a+b+c)>maxi)
		{
			cout<<1;
			return 0;
		}
		cout<<0;
	}
	return 0;
}
