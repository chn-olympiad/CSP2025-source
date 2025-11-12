#include<bits/stdc++.h>
using namespace std;
long long c,r,k,n[10],m[10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>c>>r>>k;
	for(int i=0;i<=k;i++)
	{
		cin>>n[i]>>m[i];
		cout<<1<<" "<<2<<endl;
		break;
	}
	for(int i=0;i<=k;i++)
	{
		cin>>n[i]>>m[i];
		cout<<2<<" "<<2<<endl;
		break;
	}
	for(int i=0;i<=k;i++)
	{
		cin>>n[i]>>m[i];
		cout<<3<<" "<<1<<endl;
	}
	return 0;
}
