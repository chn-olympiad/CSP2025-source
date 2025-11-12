#include <iostream>
#include <cstring>
using namespace std;
int trie[15000010][26];
int word[15000010], bl[15000010];
int tot=0;

void insert(string s, int x)
{
	int u=0, len=s.size();
	for (int i=0;i<len;i++)
	{
		int a=s[i]-'a';
		if (trie[u][a]==0)
		{
			trie[u][a]=++tot;
		}
		u=tot;
	}
	word[u]++;
	bl[u]=x;
}

int find(string s, int p, int q)
{
	int u=0;
	for (int i=p;i<q;i++)
	{
		int a=s[0]-'a';
		if (trie[u][a]==0)
			return -1;
		u=trie[u][a];
	}
	if (word[u])
		return bl[u];
}

int n, q;
string s1, s2;
int main()
{
	freopen("replace1.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i=1;i<=n;i++)
	{
		cin >> s1 >> s2;
		insert(s1, i);
		insert(s2, i);
	}
	for (int i=1;i<=q;i++)
	{
		int ans=0;
		cin >> s1 >> s2;
		int l=s1.size();
		for (int j=0;j<l;j++)
		{
			for (int k=l;k>j;k--)
			{
				int f1=find(s1, j, k), f2=find(s2, j, k);
				if (f1!=-1&&f1==f2) ans++;
			}
		}
		printf("%d\n", ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
