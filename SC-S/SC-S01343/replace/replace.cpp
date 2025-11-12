#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define maxn 200005
#define hash ZhaoAk
#define y1 zhaoshenghao666
#define nullptr 0
#define I ios::sync_with_stdio (0);
#define AK cin.tie (0);
#define CSP cout.tie (0);


using namespace std;


int n ,q;
string s1[maxn] ,s2[maxn];
int sz1[maxn] ,sz2[maxn];
string t1 ,t2 ,t3;
int st1 ,st2;


void work ()
{
	cin >> t1 >> t2;
	st1 = t1.size () ,st2 = t2.size ();
	t1 = "#" + t1 ,t2 = "#" + t2;
	t3 = t1;
	int ans = 0;
	for (int i = 1 ;i <= n ;i ++)
	{
		for (int j = 1 ;j + sz1[i] - 1 <= st1 ;j ++)
		{
			bool flag = 1;
			for (int k = j ;k - j + 1 <= sz1[i] ;k ++)
				if (s1[i][k - j + 1] != t1[k])
				{
					flag = 0;
					break;
				}
			if (flag)
			{
				for (int k = j ;k - j + 1 <= sz2[i] ;k ++)
					t1[k] = s2[i][k - j + 1];
				if (t1 == t2)	ans ++ ;
			}
			t1 = t3;
		}
	}
	cout << ans << endl;
	return ;
}


signed main()
{
	I AK CSP
	freopen ("replace.in" ,"r" ,stdin);
	freopen ("replace.out" ,"w" ,stdout);
	cin >> n >> q;
	for (int i = 1 ;i<= n ;i ++)
	{
		cin >> s1[i] >> s2[i];
		sz1[i] = s1[i].size () ,sz2[i] = s2[i].size ();
		s1[i] = "#" + s1[i] ,s2[i] = "#" + s2[i];
	}
	for (int i = 1 ;i <= q ;i ++)
		work ();
	return 0;
}
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/