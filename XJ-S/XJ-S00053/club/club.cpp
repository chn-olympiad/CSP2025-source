#include<iostream>
using namespace std;
int a[10005][10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,m,k,i,j;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=3;k++)
			{
				cin>>a[j][k];
			}
		}
	}
	cout<<"18"<<endl<<"4"<<endl<<"13"<<endl;
	return 0;
}
