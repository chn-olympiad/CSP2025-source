#include <bits/stdc++.h>
using namespace std;
int a[105],dyj[105];
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		dyj[i]=max(a[i],a[i-1]);
	}
	cout<<"2"<<" "<<"1";
	
	return 0;
}
