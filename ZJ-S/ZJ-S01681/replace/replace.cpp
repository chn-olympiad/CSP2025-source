// 我就做个特殊性质 B 跑路
// ^_^ 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define big long long
using namespace std;
big n,q,ans;
string s1,s2;
struct Node{
	big l,r;
	friend bool operator < (const Node L,const Node R)
	{
		if(L.l != R.l) return L.l < R.l;
		return L.r < R.r;
	}
};
map <big,vector<Node>> mp;
vector <big> appr;
vector <Node> TT;
vector <big> ls;
map <big,vector<big>> cc;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(big i = 1;i <= n;i++)
	{
		cin >> s1 >> s2;
		big p1 = s1.find("b"), p2 = s2.find("b");
		big numl = p1, numr = s1.length()-p1-1;
		if(mp.find(p2-p1) == mp.end()) appr.push_back(p2-p1);
		mp[p2-p1].push_back({numl,numr});
	}
	for(auto del: appr) sort(mp[del].begin(),mp[del].end());
	while(q--)
	{
		ans = 0;
		cin >> s1 >> s2;
		big p1 = s1.find("b"), p2 = s2.find("b");
		big del = p2-p1;
		big numl = p1, numr = s1.length()-p1-1;
		TT = mp[del];
		if(TT.size() == 0)
		{
			cout << "0\n";
			continue;
		}
		big pp = -1;
		ls.clear(); cc.clear();
		for(auto tmp: TT)
		{
			big ll = tmp.l, rr = tmp.r;
			if(cc.find(ll) == cc.end()) ls.push_back(ll);
			cc[ll].push_back(rr);
		}
		big l = 0, r = ls.size()-1;
		while(l <= r)
		{
			big mid = (l+r)>>1;
			big flag = 0;
			flag = (ls[mid] <= numl);
			if(flag)
			{
				pp = mid;
				l = mid+1;
			}
			else r = mid-1;
		}
		for(big i = 0;i <= pp;i++)
		{
			big ppp = -1;
			l = 0, r = cc[ls[i]].size()-1;
			// cout << r+1 << ":::\n";
			while(l <= r)
			{
				big mid = (l+r)>>1;
				big flag = 0;
				flag = (cc[ls[i]][mid] <= numr);
				if(flag)
				{
					ppp = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			ans += (ppp+1);
		}
		cout << ans << "\n";
	}
	return 0;
}
