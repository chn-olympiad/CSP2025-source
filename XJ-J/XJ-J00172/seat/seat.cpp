#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,i,j,a[15][15],s[105];
	cin>>n>>m;
	int sum=n*m;
	for(i=1;i<=sum;i++)
	{
		cin>>s[i];
	}
	int k=s[1];
	sort(s+1,s+sum+1,cmp);
	int q=1;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]=s[q];
			q++;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]==k)
			{
				if(i==1&&j<=n)	{cout<<i<<" "<<j;return 0;}
				else if(i==j-1) { cout<<j-1<<" "<<i-1;return 0;}
				else if(j==i-1) { cout<<j+1<<" "<<i+1;return 0;}
				else if(i==n&&j==m) { cout<<m<<" "<<n; return 0;}
				else cout<<j<<" "<<i;
			}
		}
	}
	return 0;
} 
