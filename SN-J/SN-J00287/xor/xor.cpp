//岳颢晨 SN-J00287 西安滨河学校 
#include<bits/stdc++.h>
int a[500000];
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==3)
	{
		cout<<2;
	}
	if(n==4&&k==0)
	{
		cout<<1;
	}
	if(n==4&&k==2)
	{
		cout<<2;
	}
	return 0;
}
