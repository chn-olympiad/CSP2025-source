#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll a[N][4];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		ll maxi=0;
		for(int j=1;j<=n;j++)
		{
			ll maxi1=0;
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			maxi1=max(a[j][1],a[j][3]);
			maxi1=max(maxi,a[j][2]);
			maxi+=maxi1;
			
		}
		cout<<maxi;
	}
    fclose(stdin);fclose(stdout);
	return 0;

}
