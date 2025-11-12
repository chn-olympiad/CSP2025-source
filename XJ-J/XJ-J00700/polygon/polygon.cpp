#include<bits/stdc++.h>
using namespace std;
bool v[5005];
int a[5005];
long long int s,t,n;
void dfs(int ge,int maxn,int he,int kai)
{
	if(ge==t)
	{
		if(he>maxn*2)
		s++;
		s%=988244353;
		return ;
	}
	for(int i=kai;i<=n;i++)
	if(v[i]==0)
	{
		v[i]=1;
		dfs(ge+1,max(maxn,a[i]),he+a[i],i+1);
		v[i]=0;
	}
	return ;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.oout","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(t=3;t<=n;t++)
	dfs(0,0,0,1);
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
