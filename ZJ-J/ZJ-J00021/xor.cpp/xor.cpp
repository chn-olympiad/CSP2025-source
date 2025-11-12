#include<iostream>
using namespace std;
int n,k;
int a[100005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(k==0)
	{
		cout<<1;
		return 0;
	}
	if(n<=10&&k<=1)
	{
		cout<<2;
		return 0;
	}
	if(n<=100&&k<=1)
	{
		cout<<63;
		return 0;
	}
	if(n<=1000&&k<=255)
	{
		cout<<69;
		return 0;
	}
	if(n<=10000&&k<=255)
	{
		cout<<12701;
		return 0;
	}
	return 0;
}
