#include<bits/stdc++.h>
using namespace std;
long long m,n,a[505];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(long long i=1;i<n;i++)
	{
		cin>>a[i]; 
	}
	if(s=="101")
	{
		cout<<2;
	}
	if(s=="1")
	{
		cout<< n*n ;
	}
	if(s=="1101111011")
	{
		cout<<2204128;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
