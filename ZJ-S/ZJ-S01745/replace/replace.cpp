#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10, _Q=2e5+10;

int n, Q;
int Total=1;
vector<string> End[N<<3];
int Trie[N<<3][200];
int ans;
void Solve(int x, int p, string Str, string Target)
{
	for(;;x=Trie[x][Str[p]], p++)
	{
		string z="";
		if(p<Str.size())
			z=Str.substr(p);
		for(int i=0;i<End[x].size();i++)
		{
			if(End[x][i]+z==Target)
				ans++;
		}
		if(p==Str.size() || !Trie[x][Str[p]])
			break;
	}
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &Q);
	for(int i=1;i<=n;i++)
	{
		string s1, s2;
		cin>>s1>>s2;
		int Now=1;
		for(int j=0;j<s1.size();j++)
		{
			if(!Trie[Now][s1[j]])
				Trie[Now][s1[j]]=++Total;
			Now=Trie[Now][s1[j]];
		}
		End[Now].push_back(s2);
	}
	for(int i=1;i<=Q;i++)
	{
		string Str, Target;
		ans=0;
		cin>>Str>>Target;
		if(Str.size()!=Target.size())
			{printf("0\n");continue;}
		for(int j=0;j<Str.size();j++)
		{
			Solve(1, j, Str, Target.substr(j));
			if(Str[j]!=Target[j])
				break;
		}
		printf("%d\n", ans);
	}
	return 0;
}
/*
如果没理解错题目应该是个trie树模拟模板题
照着跑然后替换就好了 

4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

做剪枝
给每一个点找到一个当前子树下有End的最低深度，若超出就跑 
*/
