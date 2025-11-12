#include<bits/stdc++.h>
using namespace std;
int n;
int a[5001];
int s[5001];
int f[5001];
bool fun(int x)
{
	int sum = 0;
	int fd[5001] = {0};
	for(int i = 0;i < x;i++)
	{
		if(f[i])
		{
			sum += a[i];
			fd[i] = 1;
		}
		else if(i < x)
		{
			sum += a[i];
			f[i] = 1;
			fd[i] = 1;
		}
	}
	for(int i = 0;i < x;i++)
	{
		if(!fd[i])
		{
			if(sum > a[i]) return 1;
			else return 0;
		}
	}
	return 0;
}
int main()
{
	freopen("polygon,in","r",stdin);
	freopen("polygon,out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	sort(a,a + n);
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		int sum = 0;
		s[i] = a[i];
		sum++;
		if(fun(i) && sum >= 3)
		{
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//#Shang4Shan3Ruo6Shui4
