#include <bits/stdc++.h>
using namespace std;
#define cst const
#define sttc static
#define  FOR(i, s, e) for (int i=int(s);i<=int(e);i++)
#define _FOR(i, s, e) for (int i=int(s);i>=int(e);i--)

int n;
struct node{
	array<int, 3> val;
	inline int get_max(){
		return max_element(val.begin(), val.end())-val.begin();
	}
	inline int get_v(cst int &u, cst int &v){
		return val[u]-val[v];
	}
};
array<vector<int>, 3> to;
array<set<int>, 3> q;
vector<node> s;
void get_ans(){
	int ans=0;
	FOR (i, 0, 2)
		for (cst auto &c:q[i])ans+=s[c].val[i];
	printf("%d\n", ans);
}
vector<int> to_vec(cst set<int> &s){
	sttc vector<int> res;res.clear(), res.reserve(s.size());
	for (cst auto &c:s)res.push_back(c);
	return res;
}
void solve(){
	cin>>n, s.resize(n+1);
	FOR (i, 0, q.size()-1)q[i].clear();
	FOR (i, 0, to.size()-1)to[i].clear();
	FOR (i, 1, n)cin>>s[i].val[0]>>s[i].val[1]>>s[i].val[2], q[s[i].get_max()].insert(i);
	int u=-1, v1=-1, v2=-1, dif=-1;
	if (q[0].size()>(n>>1))u=0, v1=1, v2=2, dif=q[0].size()-(n>>1);
	else if (q[1].size()>(n>>1))u=1, v1=0, v2=2, dif=q[1].size()-(n>>1);
	else if (q[2].size()>(n>>1))u=2, v1=0, v2=1, dif=q[2].size()-(n>>1);
	if (u==-1)return get_ans();
	to[v1]=to[v2]=to_vec(q[u]);
	sort(to[v1].begin(), to[v1].end(), [&](cst int &a, cst int &b){
		return s[a].get_v(u, v1)<s[b].get_v(u, v1);
	});
	sort(to[v2].begin(), to[v2].end(), [&](cst int &a, cst int &b){
		return s[a].get_v(u, v2)<s[b].get_v(u, v2);
	});
//	printf("debug:");
//	printf("\nv1:\n");
//	for (cst auto &c:to[v1])printf("%d ", c);
//	printf("\nv2:\n");
//	for (cst auto &c:to[v2])printf("%d ", c);
//	puts("");
	int p1=0, p2=0, cnt=0;
	set<int> have_erased;
	while (cnt<dif){
		while (have_erased.count(to[v1][p1]))
			have_erased.erase(to[v1][p1]), p1++;
		while (have_erased.count(to[v2][p2]))
			have_erased.erase(to[v2][p2]), p2++;
		if (s[to[v1][p1]].get_v(u, v1)>s[to[v2][p2]].get_v(u, v2))//去v2
			q[u].erase(to[v2][p2]), q[v2].insert(to[v2][p2]), have_erased.insert(to[v2][p2]), p2++, cnt++;
		else//去v1 
			q[u].erase(to[v1][p1]), q[v1].insert(to[v1][p1]), have_erased.insert(to[v1][p1]), p1++, cnt++;
	}
	get_ans();
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	int T;cin>>T;
	while (T--)solve();
}
/*
1
2
10 9 8
4 0 0

*/