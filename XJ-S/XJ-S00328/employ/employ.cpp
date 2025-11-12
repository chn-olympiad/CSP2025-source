#include<iostream>
using namespace std;
char s[505];
int flag[505];
int a[505];
int n,m;
long long cnt;
int L()
{
	int S=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='0' || S>=a[flag[i]])
		{
			S++;
		}
	}
	return n-S;
}
void D(int step)
{
	if(step==n+1)
	{
		if(L()>=m)
		{
			cnt++;
			cnt%=998244353;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=step;
			D(step+1);
			flag[i]=0;
		}	
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	D(1);
	cout<<cnt%998244353;
	return 0;
} 
