#include <bits/stdc++.h>
//#define int long long
using namespace std;

struct Stu
{
	int u;
	int v;
	int length;
	
	bool operator<(const Stu &y)const
	{
		return this->length < y.length;
	}
	
	bool operator<=(const Stu &y)const
	{
		return this->length <= y.length;
	}
	
	bool operator>(const Stu &y)const
	{
		return this->length > y.length;
	}
};
priority_queue <Stu,vector <Stu>,greater <Stu> > qa;
priority_queue <Stu,vector <Stu>,greater <Stu> > q;
int a[11][10001];
vector <Stu> tmp;
int f[20001];
bool nd[11];
bool ji[11];
int c[11];
int n,m,k;
long long minn = 1e18;

void init()
{
	for(int i = 1;i <= n+k;i++)
	{
		f[i] = i;
	}
}

int find(int x)
{
	if(f[x] == x)
	{
		return x;
	}
	return f[x] = find(f[x]);
}

void merge(int x,int y)
{
	f[find(x)] = find(y);
}

long long check()
{
	init();
	long long ans = 0;
	int cnt = 0;
	for(int i = 1;i <= k;i++)
	{
		if(ji[i] == true)
		{
			cnt++;
			ans += c[i];
			for(int j = 1;j <= n;j++)
			{
				qa.push({n+i,j,a[i][j]});
			}
		}
	}
	for(int i = 1;i < n+cnt;i++)
	{
		Stu st;
		do
		{
			if(!qa.empty()&&q.top() > qa.top())
			{
				st = qa.top();
				qa.pop();
			}
			else
			{
				st = q.top();
				tmp.push_back(q.top());
				q.pop();
			}
		}
		while(find(st.u) == find(st.v));
		ans += st.length;
		merge(st.u,st.v);
	}
	for(int i = 0;i < tmp.size();i++)
	{
		q.push(tmp[i]);
	}
	tmp.clear();
	while(!qa.empty())
	{
		qa.pop();
	}
	return ans;
}

void dfs(int t,long long ck)
{
	if(t > k)
	{
		minn = min(minn,ck);
		return;
	}
	if(nd[t])
	{
		ji[t] = false;
		dfs(t+1,ck);
		ji[t] = true;
		dfs(t+1,check());
		return;
	}
	ji[t] = false;
	long long cf = check();
	ji[t] = true;
	long long ct = check();
	if(cf <= ct)
	{
		ji[t] = false;
	}
	dfs(t+1,min(cf,ct));
	ji[t] = !ji[t];
	dfs(t+1,max(cf,ct));
}

//#undef int
int main()
{
//#define int long long

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 1;i <= m;i++)
    {
    	int u,v,w;
    	scanf("%d %d %d",&u,&v,&w);
    	q.push({u,v,w});
	}
	minn = check();
	for(int i = 1;i <= k;i++)
	{
		scanf("%d",&c[i]);
		for(int j = 1;j <= n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		ji[i] = true;
		if(check() <= minn)
		{
			nd[i] = true;
		}
		ji[i] = false;
	}
	dfs(1,minn);
	printf("%lld\n",minn);
    return 0;
}
