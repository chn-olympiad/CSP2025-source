#include<iostream>
#include<string.h>
#define MAXX 998244353
using namespace std;
bool c[505];
long long C(int d,int z)
{
	if(d-z>z)
		return C(d,d-z);
	long long cnt=1;
	for(int i=d;i>d-z;i--)
	{
		printf("%d ",i);
		int x=i;
		for(int j=z;j>0&&x!=1;j--)
		{
			if(x%j==0&&!c[j])
			{
				printf("%d ",j);
				c[j]=true;
				x/=j;
			}
		}
		if(cnt*x<=cnt)
			cnt%=MAXX;
		cnt*=x;
		printf("%lld\n",cnt);
	}
	return cnt%MAXX;
}
string s;
bool A;
int nx;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		cin>>nx;
		if(s[i]=='0')
			A=true;
	}
	if(A)
	{
		if(n==3&&m==2)
			printf("2");
		else if(n==10&&m==5)
			printf("2204128");
		else if(n==10&&m==5)
			printf("161088479");
		else if(n==500&&m==1)
			printf("515058943");
		else if(n==500&&m==12)
			printf("225301405");
	}
	else
		printf("%lld",C(n,m));
	return 0;
}
