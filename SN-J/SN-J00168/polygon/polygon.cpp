#include <iostream>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdou);
	int n,a,b,c,cnt,ans;
	cin>>n>>a>>b>>c;
	cnt=a+b+c;
	ans=max(max(a,b),max(a,c));
	if(cnt>ans*2)
	{
		cout<<"1";
	}
	return 0;
}
