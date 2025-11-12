#include<bits/stdc++.h>
using namespace std;
int a[10001],m,o,p,ans,b[10000],c[10000];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>p>>o;
	for(int i=0;i<m;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
		ans+=c[i];
	}
	cout<<ans<<endl;
	return 0;
}


