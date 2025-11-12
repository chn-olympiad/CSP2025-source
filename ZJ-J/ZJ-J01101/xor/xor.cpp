#include<bits/stdc++.h>
using namespace std;
struct s
{
	int x,y;
};
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	vector<vector<int> > dp(n,vector<int>(n,0));
	for (int i=0;i<n;i++)
	{
		dp[i][i]=a[i];
	}
	for (int i=n-2;i>=0;i--)
	{
		for (int j=i+1;j<n;j++)
		{
			dp[i][j]=int(dp[i][i]^dp[i+1][j]);
		}
	}
	vector<s> temp(n);
	int ans=0;
	for (int i=0;i<n;i++)
	{
		for (int j=i;j<n;j++)
		{
			if (dp[j-i][j]==k)
			{
				bool _=true;
				for (int p=0;p<ans;p++)
				{
					if (temp[p].x>=j-i&&temp[p].y<=j)
					{
						_=false;
						break;
					}
					
				}
				if (_)
				{
					temp[ans]={j-i,j};
					ans++;
				}
			}
		}
	}
	for (int i=0;i<ans;i++)
	{
		cout<<temp[i].x<<' '<<temp[i].y<<endl;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}