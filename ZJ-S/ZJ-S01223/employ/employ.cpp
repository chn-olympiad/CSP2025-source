#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		if(a!=0)cnt++;
	}
	//cout<<cnt<<endl;
	if(cnt<m)cout<<0;
	else{
		for(int i=2;i<=cnt;i++)
		{
			ans*=cnt;
			ans%=998244353;
			//cout<<ans<<endl;
		}
	}
	cout<<ans;
}
