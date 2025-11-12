#include<bits/stdc++.h>
using namespace std;
int n,m,gr;
int a[105];
int t;
int hang,lie;
int k;
int b[105][105];
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	gr=a[1];
	sort(a+1,a+1+n*m,cmp);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			k++;
			b[j][i]=a[k];
		}
	}
	/*
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
 cout<<endl;
	*/
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(gr==b[i][j])
			{
				if(j%2==0)
				{
					hang=m-i+1;
				}
				else hang=i;
				cout<<j<<" "<<hang;
				return 0;
			}
		}
	}
	
}
