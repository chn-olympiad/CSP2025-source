#include<iostream>
#include<cstring>
using namespace std;
string b[10005];
int a[10005];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c,i,d;
	cin>>n>>m;
	cin>>c;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		d=a[i]*a[i+1];
	}
	cout<<d;
	return 0;
}
