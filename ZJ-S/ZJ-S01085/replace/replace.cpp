#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,q;
string t1,t2;
struct Node
{
	string s1,s2;
	int abx;
}str[1000000];
bool cmp(Node x,Node y)
{
	return x.abx < y.abx;
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n;i ++)
	{
		cin >> str[i].s1 >> str[i].s2;
		str[i].abx = str[i].s1.find('b')-str[i].s2.find('b');
	}
	if(n*q > 10000000)
	{
		while(q --)
		{
			cin >> t1 >> t2;
			int k = t1.find('b')-t2.find('b');
			sort(str+1,str+n+1,cmp);
			int l = 1,r = n,ans1 = 0,ans2 = 0;
			while(l <= r)
			{
				int mid = (l+r)/2;
				if(mid > k)
				{
					r = mid - 1;
				}
				if(mid < k)
				{
					l = mid + 1;
				}
				if(mid == k)
				{
					ans1 = mid;
					r = mid - 1;
				}
			}
			if(ans1 == 0)
			{
				cout << "0\n";
				continue;
			}
			l = 1,r = n;
			while(l <= r)
			{
				int mid = (l+r)/2;
				if(mid > k)
				{
					r = mid - 1;
					ans2 = mid;
				}
				if(mid <= k)
				{
					l = mid + 1;
				}
			}
			cout << ans2 - ans1 << "\n";
		}
		return 0;
	}
	while(q --)
	{
		cin >> t1 >> t2;
		int ans = 0,len = t1.length();
		if(len != t2.length())
		{
			cout << "0\n";
			continue;
		}
		for(int i = 1;i <= n;i ++)
		{
			int it = t1.find(str[i].s1),flag = 1,l = str[i].s1.length();
			if(it == -1) flag = 0;
			else
			{
				for(int j = 0;j < len;j ++)
				{
					if(j >= it && j < it + l)
					{
						if(str[i].s2[j-it] != t2[j]) 
						{
							flag = 0;
							break;
						}
					}
					else
					{
						if(t1[j] != t2[j]) 
						{
							flag = 0;
							break;
						}
					}
				}
			}
			if(flag == 1) ans ++;
		}
		cout << ans << "\n";
	}
	return 0;
}
