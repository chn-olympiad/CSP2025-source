#include<bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
ULL n,m,k,cnt,minn=10000000000000;
struct edge{ULL u,v,w;}st;
bool cmp(edge a,edge b){return a.w<b.w;}
ULL uj[10002];
void init()
{
	for(int i = 0;i <= n;i++) uj[i]=i;
}
ULL find(ULL a)
{
	while(uj[a]!=a) a=uj[a];
	uj[a]=a;
	return a;
}
void hb(ULL a,ULL b)
{
	a=find(a);b=find(b);
	if(a!=b) uj[a]=b;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;st.u=n+1;
	vector<edge> ed(m),ed2(n);
	init();
	for(ULL i = 0;i < m;i++) cin >> ed[i].u >> ed[i].v >> ed[i].w;
	for(ULL i = 0;i < k;i++)
	{
		cin >> cnt;
		for(int j = 0;j < n;j++)
		{
			cin >> st.w;st.v=j+1;
			ed2.push_back(st);
		}
		ed2.insert(ed2.end(),ed.begin(),ed.end());
		sort(ed2.begin(),ed2.end(),cmp);
		for(ULL j = 0;j < ed2.size();j++)
		{
			cout << ed2[j].u << ' ' << ed2[j].v << ' ' << ed2[j].w << endl;
			if(find(ed2[j].u)!=find(ed2[j].v))
			{
				hb(ed2[j].u,ed2[j].v);
				cout << ed2[j].u << ' ' << ed2[j].v << ' ' << ed2[j].w << endl;
				cnt+=ed2[j].w;
			}
			cout << endl;
		}
		minn=min(minn,cnt);
		init();
	}
	cnt=0;
	for(ULL j = 0;j < m;j++)
	{
		if(find(ed[j].u)!=find(ed[j].v))
		{
			hb(ed[j].u,ed[j].v);
			cnt+=ed[j].w;
		}
	}
	minn=min(minn,cnt);
	cout << minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
