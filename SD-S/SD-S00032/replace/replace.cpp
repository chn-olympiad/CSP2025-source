#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <map>
#define LL long long
using namespace std;
const int mod = 998244353;
vector<int> hsh[200010][2];
int pw[5000010],pwf[5000010];

unordered_map<LL,bool>mh;
//unordered_map<pair<int,int>,bool>mh[2];
const int p = 233;
int ksm(int a,int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1)
		{
			ans = 1ll * ans * a % mod;
		}
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return ans;
}
int query(vector<int>&h,int l,int r)
{
	if(l > r)
	{
		return 0;
	}
	int sum = h[r];
	if(l >= 1)
	{
		sum -= h[l - 1];
	}
	sum = (sum % mod + mod % mod);
	return 1ll * sum * pwf[l] % mod;
}
string s[200010][2];
namespace subA
{
	int nxt1[5000010],nxt2[5000010];
	int p[5000010],pl[5000010];
	bool ans1[5000010];
	bool ans2[5000010];
	void kmp(bool *ans,int *nxt,string &s,string &t)
	{
		int j = 0;
		for(int i = 0; i < s.size(); i++)
		{
			cerr << i << ' ' << j << '\n';
			while(j && t[j + 1] != s[i])
			{
				j = nxt[j];
			}
			if(t[j + 1] == s[i])
			{
				j++;
			}
			if(j == t.size() - 1)
			{
				ans[i - t.size() + 1] = 1;
				j = nxt[j];
			}
		}
	}
	void findnxt(int *nxt,string &s)
	{
		int j = 0;
		for(int i = 1; i < s.size(); i++)
		{
			while(j && s[j + 1] != s[i])
			{
				j = nxt[j];
			}
			if(s[j + 1] == s[i])
			{
				j++;
			}
			nxt[i] = j;
		}
		cerr << s << '\n';
		for(int i = 0; i < s.size(); i++)
		{
			cerr << nxt[i] << ' ';
		}
		cerr << '\n';
	}
	void solve(int n,int m)
	{
		memset(nxt1,0,sizeof nxt1);
		memset(nxt2,0,sizeof nxt2);
		string S1 = "",S2 = "";
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i][0] >> s[i][1];
			S1 += '{';
			p[S1.size()] = 0;
			pl[S1.size()] = -1;
			for(int j = 0; j < s[i][0].size(); j++)
			{
				pl[S1.size() + 1 + j] = j;
				p[S1.size() + 1 + j] = i;
			}
			S1 += s[i][0];
			S2 += '{';
			S2 += s[i][1];
		}
		string t1,t2;
		cin >> t1 >> t2;
		int l = -1,r = 0;
		if(t1.size() != t2.size())
		{
			cout << "0\n";
			return;
		}
		for(int i = 0; i < t1.size(); i++)
		{
			if(t1[i] == t2[i])
			{
				continue;
			}
			if(l == -1)
			{
				l = i;
			}
			r = i;
		}
		string T1 = "",T2 = "";
		for(int i = l; i <= r; i++)
		{
			T1 += t1[i];
			T2 += t2[i];
		}
		cerr << "kel\n";
		findnxt(nxt1,T1);
		findnxt(nxt2,T2);

		memset(ans1,0,sizeof ans1);
		memset(ans2,0,sizeof ans2);
		kmp(ans1,nxt1,S1,T1);
		cerr << "kel\n";
		kmp(ans2,nxt2,S2,T2);

		int ans = 0;
		for(int i = 0; i < S1.size(); i++)
		{
			if(ans1[i] && ans2[i])
			{
				int id = p[i];
				int L = l - pl[i] + 1;
				int R = r + s[id][0].size() - pl[i];
				if(L > 0 && R < t1.size())
				{
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}
map<pair<string,string>,int>M;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0] = 1;
	pwf[0] = 1;
	for(int i = 1; i <= 5000000; i++)
	{
		pw[i] = 1ll * pw[i - 1] * p % mod;
	}
	pwf[5000000] = ksm(pw[5000000],mod - 2);
	for(int i = 4999999; i >= 1; i--)
	{
		pwf[i] = 1ll * pwf[i + 1] * p % mod;
	}
	int n,m;
	cin >> n >> m;
//	if(m == 1)
//	{
//		subA::solve(n,m);
//	}
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i][0] >> s[i][1];
		M[make_pair(s[i][0],s[i][1])] = 1;
//		hsh[i][0].resize(s[i][0].size());
//		hsh[i][1].resize(s[i][0].size());
//		hsh[i][0][0] = s[i][0][0];
//		for(int j = 1; j < s[i][0].size(); j++)
//		{
//			hsh[i][0][j] = (1ll * hsh[i][0][j - 1] + 1ll * s[i][0][j] * pw[j]) % mod;
//		}
//		hsh[i][1][0] = s[i][1][0];
//		for(int j = 1; j < s[i][1].size(); j++)
//		{
//			hsh[i][1][j] = (1ll * hsh[i][1][j - 1] + 1ll * s[i][1][j] * pw[j]) % mod;
//		}
//		mh[1ll * hsh[i][0][s[i][0].size() - 1] * mod + hsh[i][1][s[i][1].size() - 1]]++;
	}
//	cout << query(hsh[1][0],0,2) << ' ' << query(hsh[1][1],2,4) << '\n';
	while(m--)
	{
		string t[2];
		cin >> t[0] >> t[1];
		if(t[0].size() != t[1].size())
		{
			cout << "0\n";
			continue;
		}
		vector<int> h[2];
		h[0].resize(t[0].size());
		h[1].resize(t[0].size());
		h[0][0] = t[0][0];
		h[1][0] = t[1][0];
		for(int i = 1; i < t[0].size(); i++)
		{
			h[0][i] = (1ll * h[0][i - 1] + 1ll * t[0][i] * pw[i]) % mod;
			h[1][i] = (1ll * h[1][i - 1] + 1ll * t[1][i] * pw[i]) % mod;
//			cerr << h[0][i] << ' ' << h[1][i] << '\n';
		}
		int ans = 0;
		for(int i = 0; i < t[0].size(); i++)
		{
			string now1 = "",now2 = "";
			bool f = 1;
			for(int j = 0;j < i;j++)
			{
				f &= t[0][j] == t[1][j];
			}
			if(!f)
			{
				break;
			}
			for(int j = i; j < t[0].size(); j++)
			{
//				if(query(h[0],0,i - 1) == query(h[1],0,i - 1)
//				        && query(h[0],j + 1,t[0].size() - 1) == query(h[1],j + 1,t[1].size() - 1)
//				        && mh.find(1ll * query(h[0],i,j) * mod + query(h[1],i,j))!= mh.end()
//				  )
//
//				{
//					ans += mh[1ll * query(h[0],i,j) * mod + query(h[1],i,j)];
//				}
				now1 += t[0][j];
				now2 += t[1][j];
				bool f = 1;
				for(int k = j + 1;k < t[0].size();k++)
				{
					f &= t[0][k] == t[1][k];
				}
				if(!f)
				{
					continue;
				}
				if(M.find(make_pair(now1,now2)) != M.end())
				{
					ans += M[make_pair(now1,now2)];
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
a l2sqrtl1,but eqaul to brute
why no pts for this?????
barrier is that we need to find s on every positon on t,and it may become qn,that's what I dont want
another sol is qL1,we can seperate out the inequal part and use kmp to search it on s.
every pos it be found we can check it's the answer or not.
in this,we can find out that answer is lessequal than n,useful???
in total i have got 50pts now.
mentioned that the beginning position must on the left side of the part
then we can make the brute have a 1/2,useless!
I need to work it out!!!
why brute is wrong?????????????????????????????????????????????????
Only eps pts
*/
