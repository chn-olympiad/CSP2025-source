#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=505;
int n,m;
string s;
int a[MAXN];
int t[MAXN*MAXN];
int ans=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(t[a[i]]==1)
		{
			continue;
		}
		ans+=t[a[i]];
	}
	cout<<ans;
	return 0;
}

