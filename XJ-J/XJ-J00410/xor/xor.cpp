#include<iostream>
#include<algorithm>
using namespace std;
const int N=5e5+5;
int a[N],f[N],n,k,sum=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int i,now=-1;
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++)
	{
		if(now==-1)
		{
			now=a[i];
		}
		else now^=a[i];
		if(now==k)
		{
			sum++;
			now=-1;
			continue;
		}
	}
	cout<<sum;
	return 0;
}
