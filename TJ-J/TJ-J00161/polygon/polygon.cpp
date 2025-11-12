#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char** argv) {
	freopen("polygon","r",stdin);
	freopen("polygon","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int a[10001];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int f=j+1;f<=n;f++)
			{
				int maxn;
				maxn=max(a[i],a[j]);
				maxn=max(maxn,a[f]);
				if(a[i]+a[j]+a[f]>maxn)
				{
					ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
