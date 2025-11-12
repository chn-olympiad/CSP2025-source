#include <bits/stdc++.h>

using namespace std;

const int N=105;
const int mod=998244353;

int n,m,s[N],c[N],p[N];

bool check()
{
	int fal=0,cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0||fal>=c[p[i]]) fal++;
		else cnt++;
	}
	return cnt>=m;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		s[i]=ch-'0';
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>c[i];
		p[i]=i;
	}
	int ans=0;
	do 
	{
		if(check())
		{
			ans++;
			ans%=mod;
		}
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	//666 CCF NB
	return 0;
}
