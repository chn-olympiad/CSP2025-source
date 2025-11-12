#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int a[n]={0};
	int num=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		num+=a[i];
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

