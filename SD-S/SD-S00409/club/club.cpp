#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>

using namespace std;

int T;
bool t_a = 1;	
int n,ans = 0;
int f[100005] = {0},s[100005] = {0},t[100005] = {0};

void initInput()
{
	cin >> T;
	
	while(T--)
	{
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			cin >> f[i] >> s[i] >> t[i];
			if(s[i]!=0 || t[i]!=0)
			{ 
				t_a = 0;
			}
		}
		if(t_a)
		{
			int ans = 0;
			sort(f+1,f+1+n);
			for(int i = n;i >= n/2+1;i--)
			{
				ans+=f[i];
			}
			cout << ans;
			return;
		}
		
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	initInput();
	
	return 0;	
} 
