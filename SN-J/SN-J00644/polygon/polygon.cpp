#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,cnt=0,maxa=-1e9;
	vector<int> a;
	vector<int> s;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s[i]=s[i-1]+a[i];
		if(a[i]>maxa)maxa=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			if(s[j-1]+s[i]>=maxa*2) cnt++;
		}
	}
	cout << cnt;
	return 0;
}
