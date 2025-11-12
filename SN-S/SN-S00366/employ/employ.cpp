#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n+1;i++)
	{
		int s;
		cin>>s;
	}
	long long cnt=1;
	for(int i=1;i<=n;i++)
	{
		cnt=cnt*i;
		cnt%=998244353;
	}
	cout<<cnt;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
