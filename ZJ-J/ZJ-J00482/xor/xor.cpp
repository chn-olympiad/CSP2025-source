#include<bits/stdc++.h>
using namespace std;
int n,a[200010],flag,flag2;
long long h;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>h;
	if(h > 1)
	{
		cout<<1;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i];
		if(a[i]!=1)flag = 1;
		if(a[i]>1)flag2 = 2;
	}
	if(flag2 == 2)
	{
		cout<<1;return 0;
	}
	if(flag == 0)cout<<n/2;
	else
	{
		int cnt = 0;
		if(h == 1)
		{
			for(int i = 1 ; i <= n ; i++)
				if(a[i] == 1)
				{
					cnt++;
					a[i] = 88;
				}
		}
		else
		{
			for(int i = 1 ; i <= n ; i++)
				if(a[i] == 0)
				{
					cnt++;
					a[i] = 88;
				}
			for(int i = 1 ; i <= n ; i++)
				if(a[i] == 1 && a[i+1] == 1)
				{
					cnt++;
					i++;
				}
		}
		cout<<cnt;
	}
	return 0;
}

