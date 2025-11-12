#include<bits/stdc++.h>
using namespace std;
int n,k,tot,ans,a[500001],b[5001][5001];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			b[i][j]=b[i][j-1]^a[j];
		}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if(b[i][j]==k)
			{
				ans++;
				break;
			}
		}
	cout<<ans<<endl;
	return 0;
}
//#Shang4Shan3Ruo6Shui4