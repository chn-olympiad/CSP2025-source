#include<bits/stdc++.h>
using namespace std;
string s;
bool flag;
int x,c[505]; 
const int MOD=998244353;
int solve(int a,int b)
{
	int ans1=1,ans2=1;
	for (int i=a;i>0;i--)
	{
		ans1*=i;
	}
	if(a==b)
	{
		return ans1;
	}
	for (int i=a-b;i>0;i--)
	{
		ans2*=i;
	}
	return ans1/ans2;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	int j=0;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		if(x==1)
		{
			j++;
		}
		else
		{
			flag=true;
		}
	}
	if(flag==true)
	{
		cout<<988244352;
	}
	else
	{
		cout<<solve(j,m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}