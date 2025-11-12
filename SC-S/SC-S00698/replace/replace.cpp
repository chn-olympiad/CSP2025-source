#include<bits/stdc++.h>
using namespace std;
#define maxn 5000006

ifstream is("replace.in", ios::in);
ofstream os("replace.out", ios::out);
#define cin is
#define cout os

struct node
{
    map<pair<char, char>, int> ch;
    int fail=0, dep=0;
    node(){}
}tr[maxn];

int tag[maxn];
int cnt=0;

void insert(const string &a, const string &b)
{
    int idx=0;
    int l=a.size();
    for(int i=0;i<l;i++)
    {
        if(!tr[idx].ch.count({a[i], b[i]}))
            tr[idx].ch[{a[i], b[i]}]=++cnt, tr[cnt].dep=tr[idx].dep+1;
        idx=tr[idx].ch[{a[i], b[i]}];
    }
    tag[idx]++;
}

queue<int> Q;
void build_fail()
{
	for(auto n:tr[0].ch)
	{
		auto id=n.second;
		Q.emplace(id);
	}
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(auto n:tr[u].ch)
        {
            auto chr=n.first;
            auto id=n.second;
			int p=tr[u].fail;
			while(p&&!tr[p].ch.count(chr)) p=tr[p].fail;
            if(!tr[p].ch.count(chr)) tr[id].fail=0;
            else tr[id].fail=tr[p].ch[chr];
            Q.emplace(id);
        }
    }
}

int64_t query(const string &a, const string &b, int ded, int dst)
{
	int idx=0;
	int64_t ret=0;
	int l=a.size();
	for(int i=0;i<l;i++)
	{
		while(idx&&!tr[idx].ch.count({a[i], b[i]}))
				idx=tr[idx].fail;
		if(tr[idx].ch.count({a[i], b[i]})) idx=tr[idx].ch[{a[i], b[i]}];
		int p=idx;
		if(i>=ded) while(p&&tr[p].dep>=i-dst+1) ret+=tag[p], p=tr[p].fail;
	}
	return ret;
}

signed main()
{
    int n, q;
    string a, b;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        insert(a, b);
    }
	build_fail();
	while(q--)
	{
		cin>>a>>b;
		int dst=1e7, ded=-1, l=a.size();
		for(int i=0;i<l;i++)
			if(a[i]!=b[i]) 
			{
				if(dst==1e7) dst=i;
				ded=max(ded, i);
			}
		cout<<query(a, b, ded, dst)<<'\n';
	}
}