#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
string s[N],s1[N];
int n,m;
void bfs(string h,string h1)
{
	queue<string> q;
	q.push(h);
	int ans = 0;
	while(q.size())
	{
		h = q.front();
		q.pop();
		if(h==h1)
		{
			ans++;
			continue;
		}
		int n1 = h.size();
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<n1;j++)
			{
				int fl = 1;
				for(int k=j;k<=j+s[i].size()-1;k++)
				{
					if(h[k]!=s[i][k-j])
					{
						fl = 0;
						break;
					}
				}
				if(fl)
				{
					string hk = h;
					for(int k=j;k<=j+s[i].size()-1;k++)hk[k] = s1[i][k-j];
					q.push(hk);
				}
			}
		}
	}
	printf("%d\n",ans);
} 
int main()
{
    freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin >> s[i] >> s1[i];
	}
	while(m--)
	{
		string h,h1;
		cin >> h >> h1;
		bfs(h,h1);
	}
	return 0;
}

