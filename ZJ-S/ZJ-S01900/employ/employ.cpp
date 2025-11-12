#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,a[100001],f;
long long sum;
bool vis[100001];
string s;
void dfs(int day,int k)
{
	bool val=true;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] && a[i]>day-k-1)
		{
			vis[i]=true;
			dfs(day+1,k+(s[day-1]-48));
			vis[i]=false;
			val=false;
		}
	}
	if(val && k==m) sum++;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1,0);
	cout<<sum%p;
	return 0;
}