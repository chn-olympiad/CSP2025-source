#include <iostream>
using namespace std;

int a[5501];
bool fl[5501];
long long gan(int n)
{
	long long sum=1;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
	}
	return sum;
}
long long c(int n,int m)
{
	return gan(n)/(gan(m)*gan(n-m));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long num=0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=3;i<n;i++)
	{
		num+=c(n,i);
	}
	num++;
	num%=998244353;
	cout << num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
