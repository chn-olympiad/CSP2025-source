#include <bits/stdc++.h>
using namespace std;

struct stu
{
	long long v1,v2,v3,maxv,maxnum;
};
stu a[500005];

bool cmp(stu x,stu y)
{
	if(x.maxnum != y.maxnum)
		return x.maxnum < y.maxnum;
	else
		return x.maxv > y.maxv;
}

int main(void)
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long T;
	cin >> T;
	for(int z = 0;z < T;z++)
	{
		priority_queue <long long> pq1;
		priority_queue <long long> pq2;
		priority_queue <long long> pq3;
		long long ans = 0;
		long long n = 0;
		cin >> n;
		for(int i = 0;i < n;i++)
		{
			cin >> a[i].v1 >> a[i].v2 >> a[i].v3;
			a[i].maxv = max(a[i].v1,max(a[i].v2,a[i].v3));
			if(a[i].maxv == a[i].v1) a[i].maxnum = 1;
			else if(a[i].maxv == a[i].v2) a[i].maxnum = 2;
			else a[i].maxnum = 3;
		}
		sort(a,a + n,cmp);
		long long cnt1 = 0,cnt2 = 0,cnt3 = 0;
		for(int i = 0;i < n;i++)
		{
			if(a[i].maxnum == 1 && cnt1 < n / 2)
			{
				ans += a[i].maxv;
				cnt1++;
				//cout << ans << endl;
				continue;
			}
			if(a[i].maxnum == 2 && cnt2 < n / 2)
			{
				ans += a[i].maxv;
				cnt2++;
				//cout << ans << endl;
				continue;
			}
			if(a[i].maxnum == 3 && cnt3 < n / 2)
			{
				ans += a[i].maxv;
				cnt3++;
				//cout << ans << endl;
				continue;
			}
			
			if(a[i].maxnum == 1 && cnt1 == n / 2)
			{
				pq1.push(a[i].maxv);
			}
			if(a[i].maxnum == 2 && cnt2 == n / 2)
			{
				pq2.push(a[i].maxv);
			}
			if(a[i].maxnum == 3 && cnt3 == n / 2)
			{
				pq3.push(a[i].maxv);
			}
			//cout << ans << endl;
		}
		long long ans1 = ans;
		for(int i = 0;i < n;i++)
		{
			if(!pq1.empty())
			{
				if(a[i].maxnum == 1)
				{
					long long l1 = (a[i].maxv - max(a[i].v2,a[i].v3));
					cout << a[i].maxv << " " << l1 << endl;
					if(l1 < pq1.top() && l1 > 0)
					{
						ans1 += (pq1.top() - l1);
						//cout << a[i].maxv << "->" << max(a[i].v2,a[i].v3) << " But+" << (pq1.top() - l1) <<endl;
						pq1.pop();
					}
				}	
			}
			if(!pq2.empty())
			{
				if(a[i].maxnum == 2)
				{
					long long l2 = a[i].maxv - max(a[i].v1,a[i].v3);
					if(l2 < pq2.top() && l2 > 0)
					{
						ans1 += (pq2.top() - l2);
						//cout << a[i].maxv << "->" << max(a[i].v1,a[i].v3) << " But+" << (pq2.top() - l2) << endl;
						pq2.pop();
					}
				}	
			}
			if(!pq3.empty())
			{
				if(a[i].maxnum == 3)
				{
					long long l3 = a[i].maxv - max(a[i].v2,a[i].v1);
					if(l3 < pq3.top() && l3 > 0)
					{
						ans1 += (pq3.top() - l3);
						//cout << a[i].maxv << "->" << max(a[i].v2,a[i].v1) << " But+" << (pq3.top() - l3) << endl;
						pq3.pop();
					}
				}	
			}
		}
		cout <<  max(ans,ans1) << endl;
		//cout <<  min(ans,ans1) << endl;
	}
	return 0;
 } 
