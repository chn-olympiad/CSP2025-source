#include <bits/stdc++.h>
using namespace std;
int n,m;
struct node{int s,id;} a[105];
bool cmp(node a,node b)
{
	return a.s > b.s;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) 
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++) cout<<a[i].s<<' '<<a[i].id<<"  ";
	//cout<<endl;
	int k=1;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[k].id==1)
			{
				cout<<j<<" ";
				if(j%2==0) cout<<n-i+1;
				else cout<<i;
				return 0;
			}
			k++;
		}
	}
	return 0;
}
