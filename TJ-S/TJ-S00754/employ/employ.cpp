#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[500];
bool isok[500];
int ans = 0;
vector<int> t;
void dfs(int p,int num,int lose,int w)
{
	if(p == n)
	{
		if(num == m)
		{
			ans+=1;
			return ;
		}
	}
	else
	{
		for(int i = 0;i<n;i++)
		{
			if(lose<c[i] and isok[i] == false)
			{
				if(s[w] == '1')
				{
					isok[i] = true;
					dfs(p+1,num+1,lose,w+1);
					isok[i] = false;
				}
				else if(s[w] == '0') 
				{
					isok[i] = true;
					dfs(p+1,num,lose+1,w+1);
					isok[i] = false;
				}
			}
			else if(isok[i] == false)
			{
				isok[i] = true;
				dfs(p+1,num,lose+1,w+1);
				isok[i] = false;
			}
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	cin>>n>>m>>s;
	for(int i = 0;i<n;i++)
	{
		cin>>c[i];
	}
	dfs(0,0,0,0);
	cout<<ans<<endl;
	return 0;
}
