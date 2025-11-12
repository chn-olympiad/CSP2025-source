#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[1010],s[1010][1010];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i][i]=a[i];
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) s[i][j]=s[i][j-1] xor a[j];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(s[i][j]==k)
			{
				ans++;
				i=j+1;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}