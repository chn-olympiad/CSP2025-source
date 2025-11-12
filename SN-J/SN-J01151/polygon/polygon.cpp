#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int  n;
	cin>>n;
	int m=0,sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		m=max(m,a[i]);
	}
	if(sum>m*2) cout<<"1";
	else cout<<"0";
	return 0;
}
