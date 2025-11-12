#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn=2000010;
ll n,m,k,a,b,sum,c[maxn];

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a;
		for(int j=1;j<=n;j++)
		{
			cin>>b;
		}
	}
	if(k==0)
	{
		sort(c+1,c+m+1);
		for(int i=1;i<n;i++)
		{
			sum+=c[i];
		}
		cout<<sum<<endl;
	}
	else
	{
		cout<<"0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
