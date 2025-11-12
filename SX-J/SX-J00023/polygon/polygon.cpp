#include<bits/stdc++.h>
using namespace std;
int num;
int wood[10000];
int sam;
int dp[1000][1000];


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>wood[i];
	}
	for(long long i=1;i<=num;i++)
	{
		for(long long j=i;j<=num;j++)
		{
			if(wood[i]>wood[j])
			{
				int t;
				t=wood[i];
				wood[i]=wood[j];
				wood[j]=t;
			}
		}
	}
	if(num==3)
	{
		int d=wood[num];
		int db=0;
		for(int i=1;i<=num;i++)
		{
			db+=wood[i];
		}
		if(db>d*2)
		{
			cout<<"1";
			return 0;
		}
		else
		{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}