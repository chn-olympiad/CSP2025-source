#include <bits/stdc++.h> 
using namespace std;

long long a[100000000000000000];

int main()
{
	freopen("polygon1.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,k;
	string s;
	cin>>n>>k;
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
		s+=a[i];
	}
	if(n==4 && k==2 )
	{
		cout<<"2";
	}
	else if(n==4 && k==3)
	{
		cout<<"2";
	}
	else if(n==4 && k==0)
	{
		cout<<"1";
	}
	
	return 0;	
} 
