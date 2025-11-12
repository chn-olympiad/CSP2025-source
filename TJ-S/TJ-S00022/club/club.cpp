#include<bits/stdc++.h>
using namespace std;
int t, n2;
long long cnt[3], n, hf;
bool fl1 = 0, fl2 = 0;
vector<long long> t1;
struct N
{
	long long a0, a1, a2;
	int num;
}n1[100005];
void Read()
{
	for(int i=0; i<n; i++)
		{
			cin >> n1[i].a0 >> n1[i].a1 >> n1[i].a2;
			long long maxn = n1[i].a0;
			if(n1[i].a1 > n1[i].a0)
			{
				maxn = n1[i].a1;
				n2 = 1;
			}
			if(n1[i].a2 > maxn)	
			{
				maxn = n1[i].a2;
				n2 = 2;
			}
			if(n1[i].a1 != 0)	fl1 = 1;
			if(n1[i].a2 != 0)	fl2 = 1;
			cnt[n2]++;
			n1[i].num = n2;
			n2 = 0;
			maxn = -1;   
		}
}
bool cmp1(N p, N q)
{
	if(p.num != q.num)	return p.num < q.num;
	else if(p.num == q.num && p.num == 0)
	{
		if(abs(p.a1 - q.a1) > abs(p.a2 - q.a2))	return p.a1 < q.a1;
		else if(abs(p.a1 - q.a1) < abs(p.a2 - q.a2)) return p.a2 < q.a2;
		else if(abs(p.a1 - q.a1) == abs(p.a2 - q.a2))	return p.a0 >= q.a0;
	}
	else if(p.num == q.num && p.num == 1)
	{
		if(abs(p.a0 - q.a0) > abs(p.a2 - q.a2))	return p.a0 < q.a0;
		else if(abs(p.a0 - q.a0) < abs(p.a2 - q.a2)) return p.a2 < q.a2;
		else if(abs(p.a0 - q.a0) == abs(p.a2 - q.a2))	return p.a1 >= q.a1;
	}
	else if(p.num == q.num && p.num == 2)
	{
		if(abs(p.a0 - q.a0) > abs(p.a1 - q.a1))	return p.a0 < q.a0;
		else if(abs(p.a0 - q.a0) < abs(p.a1 - q.a1)) return p.a1 < q.a1;
		else if(abs(p.a0 - q.a0) == abs(p.a1 - q.a1))	return p.a2 >= q.a2;
	}
}
bool cmp2(N p, N q)
{
	return p.a0 > q.a0;
}
bool cmp3(N p, N q)
{
	if(p.num != q.num)	return p.num < q.num;
	else if(p.num == q.num && p.num == 0)
	{
		if(abs(p.a1 - q.a1) > abs(p.a0 - q.a0))	return p.a1 > q.a1;
		else if(abs(p.a1 - q.a1) < abs(p.a0 - q.a0)) return p.a0 > q.a0;
	}
	else if(p.num == q.num && p.num == 1)
	{
		if(abs(p.a1 - q.a1) > abs(p.a0 - q.a0))	return p.a1 > q.a1;
		else if(abs(p.a1 - q.a1) < abs(p.a0 - q.a0)) return p.a0 > q.a0;
	}
}
int zhao()
{
	int ans = 0;
	sort(n1, n1+n, cmp1);
	int i0 = 0;
	while(n1[i0].num == n1[i0+1].num)
	{
		i0++;
	}
	int i1 = i0 + 1;
	while(n1[i1].num == n1[1+1].num && n1[i1].num == 1)
	{
		i1++;
	}
	if(cnt[0] > hf)
	{
		for(int j=hf; j<i0; j++)
		{
			if(n1[j].a1 > n1[j].a2)	n1[j].num = 1;
			else	n1[j].num = 2;
		}
	}
	else if(cnt[1] > hf)
	{
		for(int j=hf; j<=i1; j++)
		{
			if(n1[j].a0 >= n1[j].a2)	n1[j].num = 0;
			else	n1[j].num = 2;
		}
	}
	else if(cnt[2] > hf)
	{
		for(int j=i1; j<n; j++)
		{
			if(n1[j].a0 > n1[j].a1)	n1[j].num = 0;
			else	n1[j].num = 1;
		}
	}
	for(int i=0; i<n; i++)
	{
		if(n1[i].num == 0)	ans += n1[i].a0;
		else if(n1[i].num == 1)	ans += n1[i].a1;
		else if(n1[i].num == 2)	ans += n1[i].a2;
	}
	return ans;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out ", "w", stdout);
	cin >> t;
	for(int i=0; i<t; i++)
	{
		cin >> n;
		hf = n / 2;
		Read();
		if(fl1 == 0 && fl2 == 0)
		{
			sort(n1, n1+n, cmp2);
			int aa = 0;
			for(int j=0; j<hf; j++)
			{
				aa += n1[i].a0;
			}
			t1.push_back(aa);
			continue;
		}
		if(fl1 != 0 && fl2 == 0)
		{
			sort(n1, n1+n, cmp3);
			int aa = 0;
			int i0 = 0;
			while(n1[i0].num == n1[i0+1].num)
			{
				i0++;
			}
			if(cnt[0] > hf)
			{
				for(int j=hf; j<i0; j++)
				{
					n1[j].num = 1;
				}
			}
			else if(cnt[1] > hf)
			{
				for(int j=hf; j<n; j++)
				{
					n1[j].num = 0;
				}
			}
			for(int i=0; i<n; i++)
			{
				if(n1[i].num == 0)	aa += n1[i].a0;
				else	aa += n1[i].a1;
			}
			t1.push_back(aa);
			continue;
		}
		int ans0 = zhao();
		t1.push_back(ans0);
		for(int j=0; j<n; j++)
		{
			n1[j].a0 = 0;
			n1[j].a1 = 0;
			n1[j].a2 = 0;
			n1[j].num = 0;
		}
		fl1 = 0;
		fl2 = 0;
	}
	int le = t1.size();
	for(int i=0; i<le; i++)
	{
		cout << t1[i] << endl;
	}
	return 0;
}
