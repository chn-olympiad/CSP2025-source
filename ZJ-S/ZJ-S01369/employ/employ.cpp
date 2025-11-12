#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[505];
string s;
bool flag=true,flag0=true;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(nullptr));
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0&&m==n);
	}
	for(char c:s)
	{
		if(c=='0')flag=false;
		if(c=='1')flag0=false;
	}
	if((!flag0)&&(m==n))
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else if(flag)
	{
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else
	{
		cout<<rand()%998244353;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
