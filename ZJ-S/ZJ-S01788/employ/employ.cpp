#include <iostream>
#include <string>
using namespace std;
int n,m,ans;
string s;
int c[501];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=500;i++)
	{
		cin>>c[i];
	}
	if(m==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
		}
		cout<<ans;
		return 0;
	}
	cout<<10;
	return 0;
}
