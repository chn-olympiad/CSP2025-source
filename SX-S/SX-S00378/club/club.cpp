#include <bits/stdc++.h>
#define ll longlong
using namespace std;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,a[100010],ans=0,b1[100010],b2[100010],b3[100010],b4[100010],x;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		cin>>n;
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<3; k++)
			{
				cin>>a[k];
			}
			if(a[1]==0&&a[2]==0) ans+=a[0];
			for(int k=0; k<3; k++)
			{
				a[k]=0;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}