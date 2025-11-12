#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct node{
	int sum,ii;
}a[1005];
bool cmp(node x,node y)
{
	return x.sum>y.sum;
}
int n,m,x,b[105][105],j=1,k=1,cnt=1;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=n*m;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i].sum;
		a[i].ii=i;
	}
	sort(a+1,a+x+1,cmp);
	while(a[cnt].ii!=1)
	{
		if(k==n&&j%2==1)
		{
			j++;
			cnt++;
			continue;
		}
		if(k==1&&j%2==0)
		{
			j++;
			cnt++;
			continue;
		}
		if(j%2==1)
		{
			k++;
			cnt++;
			continue;	
		}
		if(j%2==0)
		{
			k--;
			cnt++;
			continue;
		}
	}
	cout<<j<<" "<<k<<"\n";
	return 0;
}
/*
2 2
99 100 97 98

3 2
95 99 98 100 96 97

2 2
98 99 100 97

3 3
94 95 96 97 98 99 100 93 92
*/