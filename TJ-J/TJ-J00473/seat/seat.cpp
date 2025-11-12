#include<bits/stdc++.h>
using namespace std;
int a[101];
int maaap[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int cj=a[1],q=n*m;
	sort(a+1,n*m+a+1);
	/*for(int i=1;i<=n*m;i++)
	{
		cout<<a[i]<<" ";
	}*/
	//cout<<endl;
	for(int j=1;j<=n;j=j+2)
	{
		//cout<<"q"<<endl;
		for(int k=1;k<=m;k++)
		{
			maaap[k][j]=a[q];
			//cout<<maaap[k][j]<<endl;
			q--;
		}
		for(int k=m;k>=1;k--)
		{
			maaap[k][j+1]=a[q];
			//cout<<maaap[k][j+1]<<endl;
			q--;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(maaap[i][j]==cj)
				cout<<j<<" "<<i;
		}
	}
	return 0;
}
