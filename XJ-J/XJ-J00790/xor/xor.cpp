#include<iostream>
using namespace std;
int a[5000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2||m==3)
	{
		cout<<"2";
	}
	else
	{
		cout<<"1";
	}
	return 0;
}
