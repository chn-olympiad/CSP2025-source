#include <bits/stdc++.h>
using namespace std;

const int N = 500010;

int n,k;
int a[N];
int f[N];
int big_ans;
int he;
int ans;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}	
	for(int w = 1;w<=n;w++)
	{	
		he = a[w];
		int j = w,i = w;
		ans = 0;
		while(i<=n)
		{
			while(he!=k && j<n)
			{
				he^=a[++j];
			}
			if(j<=n&&he==k) ans++;
			i = j+1;
			he=a[i];
			j++;
		}
		big_ans=max(big_ans,ans);
	}
	cout << big_ans;
	
	return 0;
}
