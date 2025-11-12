#include <bits/stdc++.h>
using namespace std;

long long a[500001];
long long sum[500001];
bool b[500001];
struct row
{
	long long l,r;
};
void sets(row &r,long long a,long long b)
{
	r.l = a;
	r.r = b;
}
vector <row>v;

bool cmp(row a,row b)
{
	return a.r < b.r;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin >> n >> k;
	for(long long i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum[i] = sum[i - 1] ^ a[i];
	}
	for(long long r = 1;r <= n;r++)
	{
		for(long long l = r;l >= 1;l--)
		{
			long long ans = sum[r] ^ sum[l - 1];
			if(ans == k)
			{
				row rs;
				sets(rs,l,r);
				v.push_back(rs);
				break;
			}
		}
	}
	sort(v.begin(),v.end(),cmp);
	long long last = 0;
	long long res = 1;
	for(long long i = 1;i < v.size();i++)
	{
		if(v[i].l > v[last].r)
		{
			last = i;
			res ++;
		}
	}
	cout << res;
	return 0;
}
