#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[10010];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	int now=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	now=a[1];
	sort(a+1,a+n*m+1,cmp);
	int id;
	for(id=1;id<=n*m;id++)
	{
		if(a[id]==now)
		{
			break;
		}
	}
	int g=(id-1)/n;
	int h=id%n;
	cout<<g+1<<' ';
	if(g%2==0)
	{
		cout<<h<<endl;
	}
	else
	{
		cout<<n-h+1<<endl;
	}
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 92 93 
*/
