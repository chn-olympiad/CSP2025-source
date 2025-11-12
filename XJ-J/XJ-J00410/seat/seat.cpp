#include<iostream>
#include<algorithm>
using namespace std;
const int N=105;
int a[N],n,m;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int i,j,k,Rscore,Ri;
	cin>>n>>m;
	for(i=1;i<=n*m;i++) cin>>a[i];
	Rscore=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			for(j=1;j<=n;j++)
			{
				if(a[n*(i-1)+j]==Rscore)
				{
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
		else
		{
			for(j=n,k=1;j>=1;j--,k++)
			{
				if(a[n*(i-1)+k]==Rscore)
				{
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	return 0;
}
