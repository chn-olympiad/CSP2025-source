#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,k,a[N],s[N],mx;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	cin >> a[1];
	s[1] = a[1];
	for(int i = 2;i<=n;i++)
	{
		cin >> a[i];
		s[i] = s[i-1]^a[i];
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = i;j<=n;j++)
		{
			if(s[j]^s[i-1]==k)
			{
				if(j==i)
				{
					mx = max(mx,1);
				}
				else
				{
					mx = max(mx,j-i);
				}
			}
		}
	}
	cout << mx;
	return 0;
}
