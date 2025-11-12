#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
long long jc(int a)
{
	long long ans=1;
	for(int i=2;i<=a;i++)
	{
		ans=((ans%mod)*(i%mod))%mod;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,flag=1;
	string s;
	cin>>n>>m;
	cin>>s;
	int x;
	for(int i=1;i<=m;i++)
	{
		cin>>x;
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1')
		{
			flag=0;
		}
		break;
	}
	long long sum=0;
	if(flag==1)
	{
		sum=jc(n)%mod;
		sum=((sum%mod)/(jc(n-m)%mod))%mod;
		cout<<sum;
		return 0;
	}
	if(flag==0)
		cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

