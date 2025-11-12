#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[110];
int b[15][15];
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int ming=a[1];
	sort(a+1,a+n*m+1,cmp);
	int k=1;
	for(int i=1;i<=m;i++)//±éÀúÁÐÊý
	{
		int w=1;
		if(i%2!=0)
		{
			while(w<=m)
			{
				b[w][i]=a[k];
				w++;
				k++;
			}
		}
		else
		{
			w=n;
			while(w>=1)
			{
				b[w][i]=a[k];
				w--;
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==ming)
			{
				cout << j << " " << i;
			}
		}
	}
	return 0;
}
