#include<bits/stdc++.h>
using namespace std;
int n, k,s[500005],ans;
bool check(int x, int y)
{
	for(int i =x;i<=y; i++)
	{
		if(s[i]==-1)return 0;
	}
	int asdf =s[x];
	for(int i =x+1;i<=y; i++)
	{
		asdf=asdf^s[i];
	}
	if(asdf==k)return 1;
	else return 0;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i =1; i<=n; i++)
	{
		cin >> s[i];
		if(s[i]==k)
		{
			ans++;
			s[i]=-1;
		}
	}for(int i=2; i<=n; i++)//数量 
	{
		for(int j=1; j<=n-i+1; j++)//开头 
		{
			int x=j+i-1;//结尾
			if(check(j, x))
			{
				for(int qwer =j; qwer<=x; qwer++)
				{
					s[qwer]=-1;
				}ans++;
			}
		}
	}cout<<ans; 
	return 0;
} 
