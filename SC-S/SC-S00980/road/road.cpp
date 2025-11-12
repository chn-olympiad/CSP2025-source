#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int m,n,k;
	cin>>n>>m>>k;
	int u[m];
	int v[m];
	int w[m];
	int a[m][n];
	int mmy=0;
	for(int i=1;i<=m;++i)
    {
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int j=1;j<=m;++j)
    {
        for(int k=1;k<n;++k)
        {
            cin>>a[j][k];
        }
    }
    cout<<mmy;
	return 0;
}
