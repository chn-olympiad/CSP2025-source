#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

typedef long long ll;

int n,T;

int a[MAXN],b[MAXN],c[MAXN];

struct Info
{
	int num,id;
}ma[MAXN],se[MAXN],tmp[10];

bool cmp(Info a,Info b)
{
	return a.num < b.num;
}

int read()
{
	int f = 1,res = 0;
	char c;
	while(c < '0' || c > '9')
	{
		c = getchar();
		if(c == '-') f = -1;
	}
	while('0' <= c && c <= '9')
	{
		res = res * 10 + (c - '0');
		c = getchar();
	}
	return f * res;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	T = read();
	while(T--)
	{
		n = read();
		for(int i = 1;i <= n;i++)
		{
			a[i] = read();
			b[i] = read();
			c[i] = read();
			tmp[1].num = a[i];
			tmp[2].num = b[i];
			tmp[3].num = c[i];
			tmp[1].id = 1;
			tmp[2].id = 2;
			tmp[3].id = 3;
			sort(tmp + 1,tmp + 1 + 3,cmp);
			ma[i] = tmp[3];
			se[i] = tmp[2];
		}

		ll sum = 0,na = 0,nb = 0,nc = 0;
		for(int i = 1;i <= n;i++)
		{
			sum += ma[i].num;
			if(ma[i].id == 1) na++;
			else if(ma[i].id == 2) nb++;
			else if(ma[i].id == 3) nc++;
		}		
		if(na <= (n / 2) && nb <= (n / 2) && nc <= (n / 2))
		{
			printf("%lld\n",sum);
			continue;
		}
		else
		{
			vector<int> delta;
			int tgtid;
			int exc = max(na,max(nb,nc));
			if(na >= nb && na >= nc) tgtid = 1;
			else if(nb >= na && nb >= nc) tgtid = 2;
			else if(nc >= na && nc >= nb) tgtid = 3;
			for(int i = 1;i <= n;i++)
				if(ma[i].id == tgtid)
					delta.push_back(ma[i].num - se[i].num);
			sort(delta.begin(),delta.end());
			int p = 0;
			while(exc > n / 2 && p < delta.size())
			{
				sum -= delta[p];
				p++;
				exc--;
			}
			printf("%lld\n",sum);
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
