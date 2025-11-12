#include<bits/stdc++.h> 
using namespace std;

const int N=110;
int n,m;
int a[N],s[N][N];

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int o=a[1],d=n*m; 
	sort(a+1,a+n*m+1);
	for(int i=1;i<=m;i++){
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
			{
				s[j][i]=a[d];
				if(o==a[d])
				{
					cout<<i<<' '<<j;
					return 0;
				}
				d--;
				}
		}
		else{
			for(int j=n;j>=1;j--)
			{
				s[j][i]=a[d];
				if(o==a[d])
				{
					cout<<i<<' '<<j;
					return 0;
				}
				d--;
			}
		}
	}
	return 0;
}
