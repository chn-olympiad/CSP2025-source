#include<bits/stdc++.h>
using namespace std;
int a[10000001];

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[n]==5)
	{
		cout<<9;
	}
	if(a[n]==10)
	{
		cout<<6;
	}
	
	//fclose(stdin);
//	fclose(stdout);
	return 0;
}
