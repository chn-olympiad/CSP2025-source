#include<bits/stdc++.h>
using namespace std;
long long a[5001];
long long p[5001];
long long n;
long long ans=0;
long long num1,num2;
void dfs(int now)
{
	if(now<=-1)
	{
		if(num1>num2)ans++;
		return;
	}
	num1+=a[now];
	dfs(now-1);
	num1-=a[now];
	if(p[now-1]+num1>num2)
		dfs(now-1);
}
int main()
{
	freopen("polygen.in","r",stdin);
	freopen("polygen.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0)p[i]=a[i];
		else p[i]=a[i]+p[i-1];
	}
	sort(a,a+n);
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	if(n==3)
	{
		if(a[2]>=a[0]+a[1])
			cout<<0;
		else
			cout<<1;
		return 0;
	}
	for(int i=2;i<n;i++)
	{
		num2=a[i];
		if(p[i-1]<=num2)continue;
		dfs(i-1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
