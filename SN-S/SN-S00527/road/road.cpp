#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct bian{
	int last;
	int start;
	int w;
};
bian b[1000006];
bool cmp(bian a,bian b)
{
	if(a.w==b.w) return a.w>b.w;
	else return a.start>b.start;
}
int father[10005];
int find(int x)
{
	if(father[x]==x) return x;
	return father[x]=find(x);
}
int shubian;
int cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("read.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) father[i]=i;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].last>>b[i].start>>b[i].w;
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(shubian==n-1)
		{
			break;
		}
		if(find(b[i].last)!=find(b[i].start))
		{
			father[b[i].start]=b[i].last;
			shubian++;
			cnt+=b[i].w;
		}
	}
	cout<<cnt;
	return 0;
}
/*
4 5 0
1 2 1
2 4 2
1 4 2
1 3 4
3 4 3

*/
