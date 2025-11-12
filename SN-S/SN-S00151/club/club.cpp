#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
#define elif else if
using namespace std;
struct in
{
	int st, nd, rd;
};
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--)
	{
		int n, ans = 0;
		cin >> n;
		vector<in> a(n);
		vector<int> c1(n);
		vector<int> c2(n);
		int m1 = 0, m2 = 0, m3 = 0;
		for(int i = 1;i <= n;i++) cin >> a[i].st >> a[i].nd >> a[i].rd;
		for(int i = 1;i <= n;i++)
		{
			if(a[i].st >= a[i].nd && a[i].st >= a[i].rd) m1++;
			elif(a[i].nd >= a[i].st && a[i].nd >= a[i].rd) m2++;
			elif(a[i].rd >= a[i].st && a[i].rd >= a[i].nd) m3++;
		}
		/*先算出最大的情况，
		然后如果不符合更改第一大与第二大差最小的人，更改（m[n] - n / 2）个，
		若仍不符合，
		则更改新的超限的组别的中与m[3]好感度差值最小的*/               
		if(m1 >= m2 && m1 >= m3)
		{
			for(int i = 1;i <= n;i++)
			{
				ans += max(max(a[i].st, a[i].nd), a[i].rd);
			}
		}
		elif(m2 >= m1 && m2 >= m3)
		{
			for(int i = 1;i <= n;i++)
			{
				ans += max(max(a[i].st, a[i].nd), a[i].rd);
			}
		}
		elif(m3 >= m1 && m3 >= m2)
		{
			for(int i = 1;i <= n;i++)
			{
				ans += max(max(a[i].st, a[i].nd), a[i].rd);
			}
		}
		if(m1 <= n / 2 && m2 <= n / 2 && m3 <= n / 2)
		{
			cout<<ans<<endl;
			continue;
		}
		
		if(m1 >= n / 2 || m2 >= n / 2 || m3 >= n / 2)
		{
			if(m1 > n / 2)
			{
				for(int i = 1;i <= n;i++)
				{
					int a1 = a[i].st, a2 = a[i].nd, a3 = a[i].rd;
					if((a1 > a2 && a1 < a3) || (a1 < a2 && a1 > a3))
					{
						if(a1 > a2 && a1 < a3)
						{
							c[i] = a3 - a1;
						}
						elif(a1 < a2 && a1 > a3)
						{
							c[i] = a2 - a1;
						}
					}
					elif((a2 > a1 && a2 < a3) || (a2 < a1 && a2 > a3))
					{
						if(a2 > a1 && a2 < a3)
						{
							c[i] = a3 - a2;
						}
						elif(a2 < a1 && a2 > a3)
						{
							c[i] = a1 - a2;
						}
					}
					elif((a3 > a1 && a3 < a2) || (a3 < a1 && a3 > a2))
					{
						if(a3 > a1 && a3 < a2)
						{
							c[i] = a2 - a3;
						}
						elif(a3 < a1 && a3 > a2)
						{
							c[i] = a1 - a3;
						}
					}
				}
			}
		
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
