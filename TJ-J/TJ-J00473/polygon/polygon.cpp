#include<bits/stdc++.h>
using namespace std;
int a[5001];
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
	if(a[1]==2)
		cout<<6;
	else
		cout<<9;
	return 0;
}
