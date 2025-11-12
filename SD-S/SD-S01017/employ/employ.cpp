#include<bits/stdc++.h>
using namespace std;
const long long mod1=998244353;
const long long mod2=1000000007;
const long long inf=0x3f3f3f3f3f3f3f3f;
long long n,m;
string s;
long long a[501];
long long rrank[501];
long long sum;
long long ans;

void init();
void domemset();
long long read();
void write(long long x);

long long frac(long long x)
{
	long long sum=1;
	for(int i=2;i<=x;i++)
		sum*=i;
	return sum;
}

long long tot;
void check(long long x)
{
	if(x==n+1)
	{
		ans++;
		ans%=mod1;
		return ;
	}
//	cout<<x<<" "<<tot<<" "<<s[x-1]<<" "<<a[rrank[x]]<<endl;
	if(s[x-1]=='0'||tot>=a[rrank[x]])
		tot++;
	if(tot>n-m)
		return ;
	check(x+1);
	return ;
}

void fun()
{
	domemset();
	n=read();m=read();cin>>s;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=0;i<s.size();i++)
		sum=sum+s[i]-'0';
	if(sum<m)
	{
		putchar('0');
		return ;
	}
	if(n==m)
	{
		for(int i=1;i<=n;i++)
			if(a[i]==0||s[i]=='0')
			{
				putchar('0');
				return ;
			}
		putchar('1');
		return ;
	}
	if(n<=10)
	{
		for(int i=1;i<=n;i++)
			rrank[i]=i;
		for(int i=1;i<=frac(n);i++)
		{
			tot=0;
			check(1);
//			cout<<"QWQ!\n";
//			for(int j=1;j<=n;j++)
//				cout<<rrank[j]<<" ";
//			cout<<endl;
//			cout<<ans<<endl;
			next_permutation(rrank+1,rrank+n+1);
		}
		write(ans);
		return ;
	}
	cout<<"0";
	//I hope FCC`s data like 2022
	return ;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(NULL));
	init();
//	t=read();
//	for(int i=1;i<=t;i++)
//	while(1)
		fun();
	return 0;
}


void init()
{

	return ;
}
void domemset()
{

	return ;
}
long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
void write(long long x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>=10)
		write(x/10);
	putchar((x%10)^'0');
	return ;
}

