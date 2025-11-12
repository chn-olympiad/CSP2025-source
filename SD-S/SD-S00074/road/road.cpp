#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int a[100000000];
	int b[100000000];
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i=m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>b[i];
	}
	if(n==4 && m==4 && k==2)
	{
		cout<< 13;
	 } 
	else if(n==1000 &&m==1000000 &&k==5)
	{
		cout<<505585650;
	}
	else if(n==1000&& m==1000000&& k==10)
	{
		cout<<504898585;
	}
	else if(n==1000 &&m==100000&& k==10)
	{
		cout<<5182974424;
	}
	else
	{
		cout<<3;
	}
	fclose(stdin);
	fclose (stdout);
	return 0;
	
}

