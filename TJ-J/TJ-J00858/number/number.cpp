#include<iostream>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int s[1000],a=1,q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>s[i];
	}
	for(int i=1;i<=q;i++)
	{
		if(a<s[i])
		{
			a=s[i];
		}
	}
		
	return 0;
}
