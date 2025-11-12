#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=107;
int a[N];
int xiaoR,m,n,xiaoRseat;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	xiaoR=a[1];
	sort(a+1,a+1+m*n,cmp);
	for (int i=1;i<=m*n;i++)
	{
		if (xiaoR==a[i])
		{
			xiaoRseat=i;
			break;
		}
		//cerr<<a[i]<<endl;
	}
	//ап
	//cerr<<n<<endl;
	//cout<<xiaoRseat/n+1<<" ";
	int lie;
	if (xiaoRseat%n==0)
	{
		lie=xiaoRseat/n;
	}
	else 
	{
		lie=xiaoRseat/n+1;
	}
	int hang;
	if (lie%2==1)
	{
		hang=xiaoRseat%n;
		if (hang==0)
		{
			hang=n;
		}
	}
	else
	{
		hang=xiaoRseat%n;
		if (hang==0)
		{
			hang=n;
		}
		hang=n-hang+1;
	}
	cout<<lie<<" "<<hang<<endl;;
	return 0;
}
