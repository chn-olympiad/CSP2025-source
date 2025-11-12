#include<bits/stdc++.h>
#define ll long long

using namespace std;
int n,m,a[103][103],k=0,r=1,c=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[1][1]) 
			{
				k++;
			}
		}
	}
	while(k)
	{
		if(r%2==0&&c==1) r++;
		else if(r%2==1&&c==n) r++;
		else if(r%2==0) c--;
		else if(r%2==1) c++;
		k--;
	}
	cout<<r<<' '<<c;
	return 0;
}