#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long A[3000000];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,s;
	cin>>n>>m;
if(m==n)
{
	cout<<n;

}else
{
	if(m==1)
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
