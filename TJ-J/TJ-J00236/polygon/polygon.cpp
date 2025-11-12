#include <bits/stdc++.h>
using namespace std;
int n,cnt,l;
int arr[5001];
int dfs[5001];
void abc(int x,int y,int m,int z)
{
	int a = m;
	if(y<3||x<=2*m)
	{
		for(int i = y;i < n;i++)
		{
			m = dfs[i];
			y++;
			abc(x+dfs[i],y,m,z+1);
			x-=dfs[i];
			y--;
			m = dfs[i-1];
		}
	}else
	{
		cout << x<<" "<<y<<" "<<m<<" "<<z<<" "<<n-z<<" ";
		cnt+=n-z;
		return;
	}
	return;
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin >> n;
	int a;
	for(int i = 0;i < n;i++)
	{
		int b;
		cin >> b;
		arr[b]++;
		if(a<b)
			a = b;
	}
	int b = 0;
	for(int i = 1;i <= a+1;i++)
	{
		while(arr[i]>0)
		{
			arr[i]--;
			dfs[b]=i;
			b++;
		}
	}
	abc(0,0,0,0);
	cout << cnt;
	return 0;
	
}
