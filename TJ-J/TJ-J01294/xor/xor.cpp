#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
int a[1000010],n,k;
struct node
{
	int b,e;
};
node qv[10000010];
queue<node> q;
bool cmp(node x,node y)
{
	return x.e<y.e;
}
int cnt = 0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int l = 1;l<=n;l++)
	{
		for(int r = l;r<=n;r++)
		{
			int lr = 0;
			for(int i=l;i<=r;i++)
			{
				lr = lr^a[i];
			}
			if(lr==k) 
			{
				node ans;
				ans.b = l;
				ans.e = r;
				q.push(ans);
			}
		}
	}
	int cvr = 0;
	while(!q.empty())
	{
		qv[++cvr] = q.front();
		q.pop();
	}
	sort(qv+1,qv+cvr+1,cmp);
	int cnt = 1,last = qv[1].e;
	for(int i=2;i<=cvr;i++)
	{
		if(qv[i].b>last)
		{
			cnt++;
			last = qv[i].e;
		}
	}
	printf("%d",cnt);
	return 0;
}
