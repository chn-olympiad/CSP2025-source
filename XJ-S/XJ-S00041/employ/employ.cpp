#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,m;
long long ans;
string s;
int arr[510];

bool pd(int cc[],int xb)
{
	for(int a=0;a<xb;a++)
	{
		if(cc[xb]==arr[a])
			return 0;
	}
	return 1;
}

void dfs(int wz,int cc[],int xb)
{
	if(wz==n-1)
	{
		//检查是否可行
		int lu=0,tui=0;
		for(int a=0;a<n;a++)
		{
			if(s[a]=='1'&&tui<arr[a])
			{
				lu++;
			}
			else
				tui++;
		}
		if(lu>=m)
			ans=(ans+1)%N;
		return ;
	}
	for(int a=0;a<n;a++)
	{
		if(pd(cc,xb)==1)
		{
			cc[xb]=arr[a];
			xb++;
			dfs(wz+1,cc,xb);
			xb--;
		}
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int a=0;a<n;a++)
	{
		cin>>arr[a];
	}
	int cc[n+3];
	dfs(0,cc,0);
	cout<<ans;
	
	return 0;
} 
