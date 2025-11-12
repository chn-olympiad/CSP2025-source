#include<iostream>
using namespace std;
char s[1000005];
char n=s[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int i,a;
	int flag=0;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(n>='0'&&n<='9')
			{
				flag=1;
				cout<<n;
				return 0;
			}	
		}
	}
	return 0;
}
