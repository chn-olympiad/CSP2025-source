#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<stack>
using namespace std;
const int N=108;
const int M=100008;
int n,m,i,j,a[M],ans=0,s,k=0;
int main()
{
	ios::sync_with_stdio(false);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(i=1;i<=s;i++)
		cin>>a[i];
	ans=a[1];
	sort(a+1,a+s+1);
	for(i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=n;j++)
			{
				//printf("%d %d:%d\n",i,j,a[s-k]);
				if(a[s-k]==ans)
					{
						printf("%d %d\n",i,j);
						return 0;
				}
				k++;
				}
		}
		else
		{
			for(j=n;j>=1;j--)
			{
				//printf("%d %d:%d\n",i,j,a[s-k]);
				if(a[s-k]==ans)
					{
						printf("%d %d\n",i,j);
						return 0;
					}
					k++;
				}
				
		}
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4
