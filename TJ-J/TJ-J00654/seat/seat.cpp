#include<bits/stdc++.h>
using namespace std;
int a[15][15],b[105],ans,n,m,k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		{
			cin>>b[i];
		}
	ans=b[1];
	sort(b+1,b+1+n*m);
	k=n*m;
	for(int i=1,j=1;i<=m,j<=n;)
		{
			if(b[k]==ans)
			{
				cout<<i<<" "<<j;
				return 0;
			}
			else k--;
			if(j==n&&i%2==1)
			{
				i++;
				
			}
			else if(j==1&&i%2==0)
			{
				i++;
			}
			else if(i%2==1)j++;
			else if(i%2==0)j--;
		}
	return 0;
 } 
