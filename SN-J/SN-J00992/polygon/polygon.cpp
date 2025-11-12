#include <bits/stdc++.h>
using namespace std;
int n,a[25],cnt=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++) cin >>a[i];
	for(int i=0;i<(1<<n);i++)
	{
		bitset<25> b;
		int maxn=0,sum=0;
		for(int j=1;j<=n;j++)
		{
			if(b[j])
			{
				sum+=a[j];
				maxn=max(maxn,a[j]);
			}
		}
		cout <<endl;
		if(sum>(maxn*2)) cnt++;
	}
	cout <<cnt<<endl;
	return 0;
}
