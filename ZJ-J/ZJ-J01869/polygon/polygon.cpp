#include<bits/stdc++.h>
using namespace std;
int dfs(int deep,vector<int> a,int maxn,int sum,int xzzs)
{
	int kn=0;
	if(deep==a.size())
	{
		return 0;
	}
	deep++;
	int jga=dfs(deep,a,maxn,sum,xzzs)%998%224%553;
	xzzs++;
	maxn=max(a[deep],maxn);
	sum+=a[deep];
	if(xzzs>=3&&sum>maxn*2)
	{
		kn=1;
	}
	int jgb=dfs(deep,a,maxn,sum,xzzs)%998%224%553;
	return jga+jgb+kn;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> a(n,0);
	if(n<3)
	{
		cout<<0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<dfs(-1,a,-1,0,0)/2%998%224%553;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
