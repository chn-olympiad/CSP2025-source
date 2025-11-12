#include<bits/stdc++.h>
using namespace std;
long long int n,k,cnt;
int a[5050];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int l=3;l<=n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int s=0,maxn=0;
			for(int j=i;j<=i+l-1;j++)
			{
				s+=a[i];
				maxn=max(maxn,a[i]);
			}
			if(s>maxn*2)
			{
				cnt++;
				cnt%=998;
				cnt%=244;
				cnt%=353;
			}
		}
	}
	cout<<cnt;
	return 0;
}









