#include<bits/stdc++.h>//T2_100? synb synb
using namespace std;
#define ll long long
int n,m,l,a1;
int a[110],b[11][11];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//synb synb
	l=n*m;
	for(int i=1;i<=l;i++)
	{
		cin>>a[i];
 	}
	a1=a[1];
	sort(a+1,a+l+1,cmp);//synb synb
	int i=1,j=1,f=1,k=1;
	while(i<=m)//synb synb
	{
		if(f==1)
		{
			while(j<=n)
			{
				b[j][i]=a[k];
//				cout<<b[j][i]<<" ";
				k++,j++;
			}
			f=0,j=n;
			i++;
		}
		else
		{
			while(j>=1)
			{
				b[j][i]=a[k];
//				cout<<b[j][i]<<" ";
				k++,j--;
			}
			f=1,j=1;
			i++;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++)//synb synb
	{
		for(int j=1;j<=n;j++)
		{
//			cout<<b[i][j]<<" ";
			if(b[i][j]==a1)
			{
				cout<<j<<" "<<i;
			}
		}
//		cout<<'\n';
	}
	//synb synbsynb synbsynb synbsynb synbsynb synbsynb synbsynb synbsynb synb
	return 0;
}