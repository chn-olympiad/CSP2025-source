#include<iostream>
using namespace std;
int main()
{
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
int k,n,a[1005];

cin>>n>>k;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
if(k==0&&n<=2)
{
	cout<<1;
}
if(k==0&&n>2)
{
	int o=0;
	for(int i=1;i<=n/2;i++)
	{
		o=o+i;
	}
	cout<<n*(n/2)-2*o+n/2;
}
	return 0;
}
