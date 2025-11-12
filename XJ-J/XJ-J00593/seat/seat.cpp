#include<bits/stdc++.h> 
using namespace std;
int a[10005];
bool cmp(int qwe1,int qwe2)
{
	return qwe1>qwe2;
}
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
	int bj=a[1];
	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++)
//	{
//		cout<<i<<" "<<a[i]<<endl;
//	}
	for(int i=1;i<=n*m;i++)
	{
		if(bj==a[i])
		{
		//	cout<<i<<" ";
			int n1=i;
			int ls=n1/n;
			int hs=n1%n;
			if(ls%2==0&&hs!=0)
			{
				cout<<ls+1<<" "<<hs;
			}
			else if(ls%2==1&&hs!=0)
			{
				cout<<ls+1<<" "<<n-hs+1;
			}
			else if(ls%2==0&&hs==0)
			{
				cout<<ls<<" "<<1;
			}
			else if(ls%2==1&&hs==0)
			{
				cout<<ls<<" "<<n; 
			}
			break;
		}
	}
	return 0;
}
