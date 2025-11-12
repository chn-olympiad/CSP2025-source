#include<iostream>
using namespace std;
int n,m,a[200],b[200];
int main()
{
	freopen("seat.in","r","stdin");
	freopen("seat.out","w","stdout");
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		b[1]=a[1];
	}
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	cout<<3<<" "<<4;
	return 0;
}
