#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	string head,back,mid1,mid2;
};
struct edge
{
	int lon,p1,p2;
};
int n,q;
node a[200001];
edge b[200001];
node doo(string s1,string s2)
{
	int x = -1,y;
	for(int i = 0;i < s1.size();i++)
	{
		if(s1[i] != s2[i])
		{
			if(x == -1) x = i;
			y = i;
		}
	}
	node k;
	k.head = s1.substr(0,x);
	k.back = s1.substr(y + 1,n - y);
	k.mid1 = s1.substr(x,y - x + 1);
	k.mid2 = s2.substr(x,y - x + 1);
	return k;
}
bool judgeback(string s1,string s2)
{
	int x = s1.size(),y = s2.size();
	int j = 0;
	for(int i = x - y;i < x;i++)
	{
		if(s1[i] != s2[j]) return 0;
		j++;
	}
	return 1;
}
bool judgehead(string s1,string s2)
{
	int x = s1.size(),y = s2.size();
	for(int i = 0;i < y;i++)
	{
		if(s1[i] != s2[i]) return 0;
	}
	return 1;
}
bool judge(node k1,node k2)
{
	if(k1.mid1 != k2.mid1) return 0;
	if(k1.mid2 != k2.mid2) return 0;
	if(!judgeback(k1.head,k2.head)) return 0;
	if(!judgehead(k1.back,k2.back)) return 0;
	return 1;
}
edge does(string s1,string s2)
{
	edge k;
	for(int i = 0;i <= s1.size();i++)
	{
		if(s1[i] == 'b') k.p1 = i;
		if(s2[i] == 'b') k.p2 = i;
	}
	k.lon = s1.size();
	return k;
}
bool jjjudge(edge x,edge y)
{
	if(x.p1 - x.p2 != y.p1 - y.p2) return 0;
	if(x.p1 < y.p1) return 0;
	if(x.lon - x.p1 < y.lon - y.p1) return 0;
	return 1;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	if(n <= 1000||q == 1)
	{
		for(int i = 1;i <= n;i++)
		{
			string s1,s2;
			cin >> s1 >> s2;
			a[i] = doo(s1,s2);
		}
		for(int i = 1;i <= q;i++)
		{
			string s1,s2;
			cin >> s1 >> s2;
			int ans = 0;
			node k1 = doo(s1,s2);
			for(int j = 1;j <= n;j++)
			{
				node k2 = a[j];
				if(judge(k1,k2)) ans++;
			}
			cout << ans << endl;
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			string s1,s2;
			cin >> s1 >> s2;
			b[i] = does(s1,s2);
		}
		for(int i = 1;i <= q;i++)
		{
			string s1,s2;
			cin >> s1 >> s2;
			int ans = 0;
			edge k1 = does(s1,s2);
			for(int j = 1;j <= n;j++)
			{
				edge k2 = b[j];
				if(jjjudge(k1,k2)) ans++;
			}
			cout << ans << endl;
		}
	}
}
