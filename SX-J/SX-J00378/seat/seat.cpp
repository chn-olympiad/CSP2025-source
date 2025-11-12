#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[105];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	cout<<n<<" "<<m;
	return 0;
}