#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N],f[N][N];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			f[i][j]=(f[i][j-1]^a[j]);	
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			if(f[i][j]==k)
			{
				cnt++;
				int d=max(i,j);
				i=d,j=d;
			}	
	cout<<cnt;
	return 0;
}