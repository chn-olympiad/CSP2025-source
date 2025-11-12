#include<bits/stdc++.h>
using namespace std;
const int N=105;
int mapp[N][N];
int a[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,m,w=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int k=a[1];
	sort(a+1,a+n*m+1,cmp);
	bool flag=true,flag1=false;
	for(int i=1,j=1;i<=n;)
	{
		if(w+1<=n*m)
			mapp[i][j]=a[++w];
		if(j<m&&flag)
			j++;
		else if(j==m && flag==1)
		{
			flag=false;
			i++;
		}		
		else if(!flag && j>1)
			j--;
		else if(j==1 && flag==0)
			i++;	
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mapp[i][j]==k)
				cout<<i<<" "<<j;
	return 0;
}

