#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[100100],c;
	cin>>n>>m;
	for(int i;i<n*m;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(c==a[n])
	{
		cout<<1<<" "<<1<<endl;
	}
	if(n==1 && m==1)
	{
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	return 0;
}
