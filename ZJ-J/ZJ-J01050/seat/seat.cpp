#include<bits/stdc++.h>
using namespace std;
int n,m;
int fs[101];
bool cmp(int x,int y)
{
	return x > y;
}
int main()
{
	freopen("seat,in","r",stdin);
	freopen("seat,out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i = 1;i <= n * m;i++)
	{
		cin>>fs[i];
	}
	int sum = fs[1];
	sort(fs + 1,fs + m * n + 1,cmp);
	int mc = 1;
	for(int i = 1;i <= n;i++)
	{
		if(i % 2 != 0)
		{
			for(int j = 1;j <= m;j++)
			{
				if(fs[mc] == sum)
				{
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
				mc++;
			}
		}
		else
		{
			for(int j = m;j >= 1;j--)
			{
				if(fs[mc] == sum)
				{
					cout<<i<<" "<<j<<"\n";
					return 0;
				}
				mc++;
			}
		}
	}
	return 0;
}
