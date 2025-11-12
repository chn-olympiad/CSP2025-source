#include<bits/stdc++.h>
using namespace std;
#define ll long long
long long n;
long long m;
string a;
int p[1000005];
int k;
int c;
int r;
int ans;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i = 1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 2;j<=n;j++)
		{
			for(int l = 1;l<=n;l++)
			{
				if(a[l-1] == '0' or p[l] < k)
				{
					k++;
				}
				else if(a[l-1] == '1' && p[l] >= k)
				{
					c++;
				}
			}
			if(c>=m)
			{
				ans++;
			}
			swap(p[j],p[j-1]); 
			c = 0;
			k = 0;
		}
	}
	cout<<ans;
	return 0;
}

