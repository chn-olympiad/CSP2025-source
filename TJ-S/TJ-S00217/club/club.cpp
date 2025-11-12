#include <bits/stdc++.h>

using namespace std;
int t;

struct club
{
	int a,b,c;
}	d[100009];


int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	
	while(t--)
	{
		priority_queue <long long> q;
		priority_queue <long long> q2;
		priority_queue <long long> q3;
		int a2 = 0,b2 = 0,c2 = 0;
		int n,ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			d[i].a = x;
			d[i].b = y;
			d[i].c = z;
			
		}
		
		for(int i = 1;i <= n;i++)
		{
			long long x = d[i].a;
			long long y = d[i].b;
			long long z = d[i].c;
			int cnt = max(z,max(x,y));
			if(cnt == x)
			{
				if(a2 != n / 2)
				{
					ans += x;
					a2++;
					q.push((100001 - (x - max(y,z))) * 1000000 + i);
				}
				else
				{
					int cnt2 = q.top() % 1000000;
					int cnt3 = max(d[cnt2].b,d[cnt2].c) - d[cnt2].a + x;
					if(cnt3 > max(y,z))
					{
						ans += cnt3;
						q.pop();
						q.push((100001 - (x - max(y,z))) * 1000000 + i);
					}
					else
					{
						ans += max(y,z);
					}
				}
			}
			
			else if(cnt == y)
			{
				if(b2 != n / 2)
				{
					ans += y;
					b2++;
					q2.push((100001 - (y - max(x,z))) * 1000000 + i);
				}
				else
				{
					int cnt2 = q2.top() % 1000000;
					int cnt3 = max(d[cnt2].a,d[cnt2].c) - d[cnt2].b + y;
					if(cnt3 > max(x,z))
					{
						ans += cnt3;
						q2.pop();
						q2.push((100001 - (y - max(x,z))) * 1000000 + i);
					}
					else
					{
						ans += max(x,z);
					}
				}
			}
			
			else if(cnt == z)
			{
				if(c2 != n / 2)
				{
					ans += z;
					c2++;
					q3.push((100001 - (z - max(y,x))) * 1000000 + i);
				}
				else
				{
					int cnt2 = q3.top() % 1000000;
					int cnt3 = max(d[cnt2].b,d[cnt2].a) - d[cnt2].c + z;
					if(cnt3 > max(y,x))
					{
						ans += cnt3;
						q3.pop();
						q3.push((100001 - (z - max(y,x))) * 1000000 + i);
					}
					else
					{
						ans += max(y,x);
					}
				}
			}
				
			
		}
		
		
		cout << ans << endl;
	
	
	} 
	
	
	


	
	
	
	
	return 0;
} 
