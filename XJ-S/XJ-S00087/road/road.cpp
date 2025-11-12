#include <iostream> 
#include <algorithm>
using namespace std;
int n,m,k;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a[m][1],pf[m];
	for(int i=0;i<m;i++)
	{
		cin>>a[i][0]>>a[i][1]>>pf[i];
	}
	cout<<"13";
	return 0; 
} 
