#include<bits/stdc++.h>
using namespace std;
int n,m,num[128],tmp,cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;int t=n*m;
	for(int i=1;i<=t;i++)
		cin>>num[i];
	tmp=num[1];
	sort(num+1,num+t+1,cmp);
	for(int i=1;i<=m;i++)
		if(i%2==1)
		{
			for(int j=1;j<=n;j++)
				if(num[++cnt]==tmp)
				{
					cout<<i<<" "<<j;
					return 0;
				}
		}
		else
		{
			for(int j=n;j>=1;j--)
				if(num[++cnt]==tmp)
				{
					cout<<i<<" "<<j;
					return 0;
				}
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
