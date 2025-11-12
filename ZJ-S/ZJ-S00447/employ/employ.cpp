#include<bits/stdc++.h>
using namespace std;
long long n,m,fl1=1,fl2=1,cnt=0,c[505],mincc=INT_MAX,ans;
const int Mod=998244353;
char ch;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='0'&&fl2)fl1=0,cnt++;
		if(ch=='1')fl2=0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		mincc=min(mincc,c[i]);
	}
	if(fl1||!fl2&&(m==1)&&mincc>=cnt)
	{
		ans=1;
		for(int i=n;i>=1;i--)
		{
			ans*=(i%Mod);
			ans%=Mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
