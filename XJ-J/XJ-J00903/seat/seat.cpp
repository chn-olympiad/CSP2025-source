#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r;
int rr[110];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int k=(i-1)*m+j;
			cin>>rr[k];
//			cout<<k<<" "<<rr[k]<<endl;
		}
	}
	r=rr[1];
	int c=1,cnt=1;
	sort(rr+1,rr+n*m,cmp);
	/*
	for(int i=1;i<=n*m;i++)
	{
		cout<<rr[i]<<" ";
	} 
	*/
	int beg=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=beg;j<=n&&j>=1;j+=c)
		{
			if(rr[cnt]==r)
			{
				cout<<i<<" "<<j<<endl;
				return 0;
			}
			cnt++;
		}
		c=c*(-1);
		if(beg==1)
		{
			beg=n;
		}
		else
		{
			beg=1;
		}
	}
	return 0;
} 
