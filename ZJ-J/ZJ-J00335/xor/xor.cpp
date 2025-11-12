#include<bits/stdc++.h>
using namespace std;
int a[500001];
int main()
{
	freopen("xor.in","r",stdin)
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int i=0,sumxor=0,cnt=0;
	for(int j=1;i<=n;j++)
	{
		do
		{
			sumxor^=a[++i];
			if(sumxor==k)
			{
				cnt++;
				sumxor=0;
			}
		}while(i<n);
		cout<<cnt;
	}
	return 0;
}
