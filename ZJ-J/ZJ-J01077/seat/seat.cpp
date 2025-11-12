#include<bits/stdc++.h>
using namespace std;
const int N=110;

int n,m,a[N],zw[15][15];

bool cmp(int a,int b)
{
	return a>b;
}
int f(int a)
{
	if(a%(n+1)!=0) return a%(n+1);
	else return a/n;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int cnt,Rg=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==Rg)
		{
			cnt=i;
			break;
		}
	int nc=1;
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
			for(int i=1;i<=n;i++)
			{
				zw[i][j]=nc;
				if(nc==cnt)
				{
					cout<<j<<' '<<i;
					return 0;
				}
				nc++;
			}
		else
			for(int i=n;i>=1;i--)
			{
				zw[i][j]=nc;
				if(nc==cnt)
				{
					cout<<i<<' '<<j; 
					return 0;
				}
				nc++;
			}
	}
	return 0;
}
