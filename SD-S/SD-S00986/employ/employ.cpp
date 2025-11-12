#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
bool s[100007];
int c[100007],v[10007],b[100007];
long long ans=0;
int n,m;
void dfs(int x)
{
	if(x>n)
	{
		int sum=0,l=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]==0&&c[v[i]]>l) sum++;
			else l++; 
		}
		if(sum>=m) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			b[i]=1;
			v[x]=i;
			dfs(x+1);
			b[i]=0;
			v[x]=0;
		} 
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	bool f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]==0) f=1; 
	}
	if(f==0)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

