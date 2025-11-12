// replace

#include <bits/stdc++.h>

#define endl '\n'

#define lnt unsigned long long
#define lowbit(x) (x & -x)

using namespace std;

const int N = 2e5 + 5;
const int M = 5e6 + 5;
const lnt B = 131;

int n, q;
string s1[N], s2[N];
string t1[N], t2[N];

struct binaryIndexedTree
{
	int c[M];
	
	inline void updat(int p, int x)
	{
		for (int i = p; i < M; i += lowbit(i))
			c[i] += x;
	}
	
	inline int query(int p, int x = 0)
	{
		for (int i = p; i > 0; i -= lowbit(i))
			x += c[i];
		return x;
	}
} bit;

//namespace subtask_B
//{
//	struct ques
//	{
//		int l, r, c;
//		
//		friend bool operator < (ques a, ques b)
//		{
//			return a.l == b.l ? a.r < b.r : a.l < b.l;
//		}
//	};
//	
//	vector <int> vec1, vec2, vec3, vec4;
//	vector <ques> a[N], b[N];
//	vector <ques> c[N], d[N];
//	
//	inline int chek()
//	{
//		for (int i = 1; i <= n; i ++)
//		{
//			int c = 0;
//			for (int j = 1; j < s1[i].length(); j ++)
//			{
//				if (s1[i][j] != 'a' && s1[i][j] != 'b') return 0;
//				if (s1[i][j] == 'b')
//					if (++ c >= 2)
//						return 0;
//			}
//			c = 0;
//			for (int j = 1; j < s2[i].length(); j ++)
//			{
//				if (s2[i][j] != 'a' && s2[i][j] != 'b') return 0;
//				if (s2[i][j] == 'b')
//					if (++ c >= 2)
//						return 0;
//			}
//		}
//		for (int i = 1; i <= q; i ++)
//		{
//			int c = 0;
//			for (int j = 1; j < t1[i].length(); j ++)
//			{
//				if (t1[i][j] != 'a' && t1[i][j] != 'b') return 0;
//				if (t1[i][j] == 'b')
//					if (++ c >= 2)
//						return 0;
//			}
//			c = 0;
//			for (int j = 1; j < t2[i].length(); j ++)
//			{
//				if (t2[i][j] != 'a' && t2[i][j] != 'b') return 0;
//				if (t2[i][j] == 'b')
//					if (++ c >= 2)
//						return 0;
//			}
//		}
//		return 1;
//	}
//	
//	inline int main()
//	{
//		for (int i = 1; i <= n; i ++)
//		{
//			int p = 0;
//			for (int j = 1; j < s1[i].length(); j ++)
//				if (s1[i][j] == 'b')
//				{
//					p = j;
//					break;
//				}
//			int q = 0;
//			for (int j = 1; j < s2[i].length(); j ++)
//				if (s2[i][j] == 'b')
//				{
//					q = j;
//					break;
//				}
//			if (p >= q)
//			{
//				vec1.push_back(p - q);
//				a[p - q].push_back((ques) {q, s1[i].length() - p, i});
//			}
//			else
//			{
//				vec2.push_back(q - p);
//				b[q - p].push_back((ques) {p, s1[i].length() - q; i});
//			}
//		}
//		sort(vec1.begin(), vec1.end()), vec1.erase(unique(vec1.begin(), vec1.end()), vec1.end());
//		sort(vec2.begin(), vec2.end()), vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
//		for (int i = 0; i < vec1.size(); i ++)
//		{
//			int u = vec1[i];
//			sort(a[u].begin(), a[u].end());
//		}
//		for (int i = 0; i < vec2.size(); i ++)
//		{
//			int u = vec2[i];
//			sort(b[u].begin(), b[u].end());
//		}
//		for (int i = 1; i <= q; i ++)
//		{
//			int s = 0, t = 0;
//			for (int j = 1; j < t1[i].length(); j ++)
//				if (t1[i][j] == 'b')
//				{
//					s = j;
//					break;
//				}
//			for (int j = 1; j < t2[i].length(); j ++)
//				if (t2[i][j] == 'b')
//				{
//					t = j;
//					break;
//				}
//			if (s >= t)
//			{
//				int p = lower_bound(vec1.begin(), vec1.end(), s - t) - vec1.begin();
//				if (p < vec1.size() && vec1[p] == s - t)
//				{
//				}
//			}
//		}
//		
//		return 0;
//	}
//}

namespace subtask_1
{
	lnt bas[N];
	lnt va1[N], va2[N];
	lnt sm1[N], sm2[N];
	
	inline lnt hsh1(int l, int r)
	{
		return sm1[r] - sm1[l - 1] * bas[r - l + 1];
	}
	
	inline lnt hsh2(int l, int r)
	{
		return sm2[r] - sm2[l - 1] * bas[r - l + 1];
	}
	
	inline int main()
	{
		bas[0] = 1;
		for (int i = 1; i <  N; i ++) bas[i] = bas[i - 1] * B;
		for (int i = 1; i <= n; i ++)
		{
			for (int j = 1; j < s1[i].length(); j ++)
				va1[i] = va1[i] * B + (s1[i][j] - 'a' + 1);
			for (int j = 1; j < s2[i].length(); j ++)
				va2[i] = va2[i] * B + (s2[i][j] - 'a' + 1);
		}
		for (int i = 1; i <= q; i ++)
		{
			int p = 0;
			int q = 1;
			for (int j = 1; j < t1[i].length(); j ++) if (t1[i][j] != t2[i][j]) p = j;
			for (int j = 1; j < t1[i].length(); j ++)
				if (t1[i][j] != t2[i][j])
				{
					q = j;
					break;
				}
			for (int j = 1; j < t1[i].length(); j ++)
				sm1[j] = sm1[j - 1] * B + (t1[i][j] - 'a' + 1);
			for (int j = 1; j < t2[i].length(); j ++)
				sm2[j] = sm2[j - 1] * B + (t2[i][j] - 'a' + 1);
				
			int ans = 0;
			for (int j = 1; j < t1[i].length(); j ++)
			{
				if (j > q)
					break;
				for (int k = 1; k <= n; k ++)
					if (j + s1[k].length() - 2 < t1[i].length())
					{
						if (j + s1[k].length() - 2 < p) continue;
						if (va1[k] != hsh1(j, j + s1[k].length() - 2)) continue;
						if (va2[k] != hsh2(j, j + s2[k].length() - 2)) continue;
						ans ++;
					}
			}
					
			printf("%d\n", ans);
		}		
		return 0;
	}
}

int main()
{
	freopen("replace.in" , "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) cin >> s1[i] >> s2[i], s1[i] = " " + s1[i], s2[i] = " " + s2[i];
	for (int i = 1; i <= q; i ++) cin >> t1[i] >> t2[i], t1[i] = " " + t1[i], t2[i] = " " + t2[i];
		
//	if (subtask_b::chek()) return subtask_B::main();
	
	return subtask_1::main();
	
	return 0;
}
