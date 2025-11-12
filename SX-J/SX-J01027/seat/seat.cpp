#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],t;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=2;i<=n*m;i++) cin>>a[i];
	a[1]=t;
	sort(a+1,a+n*m+1,cmp);
	int mx=1,my=1,ss=1,fx=1;
	while(1)
	{
		if(a[ss]==t)
		{
			cout<<my<<" "<<mx;
			return 0;
		}
		if((my%2==0&&mx==1)||(my%2!=0&&mx==n))
		{
			my++;
			fx*=-1;
		}
		else mx+=fx;
		ss++;
	}
	return 0;
}
