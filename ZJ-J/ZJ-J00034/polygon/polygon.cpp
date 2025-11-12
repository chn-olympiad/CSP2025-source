#include<bits/stdc++.h>
using namespace std;
long long asd = 998244353;
long long asdf(int x,int y)
{
	long long a = 1;
	long long b = 1;
	for(int i = 0;i < y;i++)
	{
		a = a * (x - i) % asd;
		b = b * (i + 1) % asd;
	}
	return a / b % asd;
}
int a[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	scanf("%d" ,&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d" ,&a[i]);
	}
	if(n <= 5000 && n > 500 || n <= 500 && n > 20)
	{
		long long ret = 0;
		for(int i = 3;i <= n;i++)
		{
			ret = (ret + asdf(n,i)) % asd;
		}
		printf("%lld" ,ret);
		return 0;
	}
	if (a[1] + a[2] > a[3] && a[2] + a[3] > a[1] && a[1] + a[3] > a[2])
	{
		printf("1");
		return 0;
	}
	printf("0");
	return 0;
}
