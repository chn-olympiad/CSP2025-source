//SN-J00909  臧家乐  西安辅轮中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int cnt;
int num;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);		cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	num=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	int pos;
	for(int i=1;i<=n*m;i++)
		if(a[i]==num)
		{
			pos=i;
			break;
		}
	for(int j=1;j<=m;j++)
	{
		if(j&1)
			for(int i=1;i<=n;i++)
			{
				pos--;
				if(pos==0)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
		else
			for(int i=n;i>=1;i--)
			{
				pos--;
				if(pos==0)
				{
					cout<<j<<" "<<i;
					return 0;
				}
			}
	}
	return 0;
}
