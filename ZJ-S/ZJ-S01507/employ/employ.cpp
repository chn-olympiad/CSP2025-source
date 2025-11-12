#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;
string s;
int ans = 0;
int c[505];

int zhuan(string ss)
{
	int x = 0;
	int len = ss.size();
	for(int i = 0;i < len;i++)
	{
		int xt = ss[i] - '0';
		x = x * 10 + xt;
	}
	return x;
}

string zhuan2(int x)
{
	string ss = "";
	while(x != 0)
	{
		char cc = (x % 10) + '0';
		ss = cc + ss;
		x/=10;
	}
	return ss;
}

int check(string s2)
{
	s2 = s2 + ' ';
	int sum = 0;
	int cnt = 0;
	string ss = "";
	int len = s2.size();
	for(int i = 1;i < len;i++)
	{
		if(s2[i] == ' ') 
		{
			int tt = zhuan(ss);
			if(cnt - sum < c[tt] && s[cnt] == '1') sum++;
			//cout<<tt<<" "<<cnt<<" "<<sum<<" "<<c[tt]<<" "<<s[cnt]<<"\n";
			cnt += 1;
			ss = "";
		}
		else
		{
			ss = ss + s2[i];
		}
	}
	
	return sum;
	
}

void dfs(int dep,string vis,string s2)
{
	
	if(dep >= n)
	{
		if(check(s2) >= m) ans++;
		return;
	}
	else
	{
		
		for(int i = 1;i <= n;i++)
		{
			if(vis[i] == '0')
			{
				string vi2s = vis;
				vi2s[i] = '1';
				string cc = zhuan2(i);
				dfs(dep + 1,vi2s, s2 + " " + cc);
			}
		}
	}
	
	
}

signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i = 1;i <= n;i++)
		cin>>c[i];

	string ts = "0";
	string s2="";
	for(int i = 1;i <=n;i++) ts += '0'; 
	
	dfs(0,ts,s2);
	cout<<ans<<"\n";
	return 0;
}

