#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<string>
#include<cstring>
#include<deque>
#include<algorithm> 
using namespace std;
const int N=510,MOD=998244353;
int c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string opt;
	cin>>opt;
	for(int i=1;i<=n;i++)cin>>c[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			cnt++;
		}
	}
	int ans=1;
	if(n-cnt<m)
	{
		cout<<0;
		return 0;
	}
	else
	{
		while(n>=1)
		{
			ans*=n;
			ans%=MOD;
			n--;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
