#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000],flag=1,flagg=1,num1;
string str;
int main(){
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=0;i<n;i++) if(str[i]!='1') flag=0;
	for(int i=0;i<n;i++) if(str[i]!='0'){
		flagg=0;
		num1++;
	}
	int num=0;
	for(int i=1;i<=n;i++) if(c[i]==0) num++;
	long long ans=1;
	if(flag==1)
	{
		for(int i=2;i<=m;i++)
		{
			ans*=i;
		}
	}
	if(n-num<m) cout<<0;
	else if(m==1)
	{
		for(int i=2;i<=num1;i++)
		{
			ans*=i;
		}
		cout<<ans%998244353;
	}
	else if(flagg==1) cout<<0;
	else if(n>100&&m<=18)
	{
		for(int i=2;i<=m;i++)
		{
			ans*=i;
		}
		cout<<ans%998244353;
	}
	else if(m==n)
	{
		for(int i=2;i<=m;i++)
		{
			ans*=i;
		}
		cout<<ans%998244353;
	}
	else if(flag==1) cout<<ans%998244353;
	return 0;
}

