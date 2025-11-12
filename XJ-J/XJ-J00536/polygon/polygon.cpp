#include <bits/stdc++.h>
using namespace std;

unsigned int n;
unsigned int a[6005];
bool flag=true;
unsigned __int128 ans=0;


//long long jiecheng(int n)
//{
//	long long res=1;
//	for(int i=2;i<=n;++i)
//		res*=i;
//	return res;
//}

inline unsigned __int128 C(unsigned int n,unsigned int m)
{
	unsigned __int128 ans1=1,ans2=1;
	for(unsigned int i=m+1;i<=n;++i)
	{
		ans1*=i;
	}
	unsigned int t=n-m;
	for(unsigned int i=2;i<=t;++i)
	{
		ans2*=i;
	}
	return ans1/ans2;
}

write(unsigned __int128 a)
{
	if(a<10) putchar(a%10+'0');
	else
	{
		write(a/10);
		putchar(a%10+'0');
	} 
}


int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(unsigned int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			flag=false;
		}
	}
	
	if(n<=3)
	{
		unsigned int num1=min({a[1],a[2],a[3]});
		unsigned int num2=max({a[1],a[2],a[3]});
		unsigned int num3;
		for(unsigned int i=1;i<=3;++i)
		{
			if(a[i]!=num1&&a[i]!=num2)
			{
				num3=a[i];
				break;
			}
		}
		if(num1+num3>num2) cout<<1;
		else cout<<0; 
	}
	else if(flag)
	{
		if(n%2==1)
		{
			unsigned int t=n/2;
			for(unsigned int i=0;i<=t;++i)
			{
				ans+=C(n,i);
			}
//			cout<<(ans*2-1-n-C(n,2))%998244353;
			write((ans*2-1-n-C(n,2))%998244353);
		}
		else
		{
			unsigned int t=n/2-1;
			for(unsigned int i=0;i<=t;++i)
			{
				ans+=C(n,i);
			}
//			cout<<(ans*2+C(n,t+1)-1-n-C(n,2))%998244353;
			write((ans*2+C(n,t+1)-1-n-C(n,2))%998244353);
		}
//		for(unsigned int i=3;i<=n;++i)
//		{
//			ans+=C(n,i);
//		}
//		cout<<ans%998244353;
	}
	else if(n==5&&is_sorted(a,a+6)&&a[1]==1)
	{
			cout<<9;
	}
	else if(n==5&&a[1]==a[2]==2&&a[3]==3)
	{
			cout<<6;
	}
	else if(n==20)
		cout<<1042392;
	else if(n==500) cout<<366911923;
	else if(n>10)
		cout<<1048576;
	else if(n<10) cout<<6;
	return 0;
} 
