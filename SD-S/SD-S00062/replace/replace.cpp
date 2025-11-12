#include <bits/stdc++.h>
#define int long long
using namespace std;

mt19937 rnd(time(0));

#define PII pair<int,int>
#define x first
#define y second

const int N=2e5+10, L=5e6+10, P=998244353, Ba=233;

bool fla;

int n, q, W;
int ha[300];
int pr[N], mi[N], ta[N];
//vector <int> pr2[L*2], ta2[L*2];
//int anss[N];
//vector <PII> qry[L*2];

int pr1, mi1, ta1, p1, p2, le;

void Calc(string s, string t)
{
	le = s.length()-1;
	p1=-1, p2=-1;
	for(int i=1; i<=le; i++)
		if(s[i] != t[i]) {
			p1 = i-1; break; }
	for(int i=le; i>=1; i--)
		if(s[i] != t[i]) {
			p2 = i+1; break; }
	int x = 0;
	for(int i=1; i<=p1; i++)
		x = (x*Ba+ha[s[i]]) % P;
	pr1 = x; x = 0;
	for(int i=p2; i<=le; i++)
		x = (x*Ba+ha[s[i]]) % P;
	ta1 = x; x = 0;
	for(int i=p1+1; i<=p2-1; i++)
		x = (x*Ba+ha[s[i]]) % P;
	int y = 0;
	for(int i=p1+1; i<=p2-1; i++)
		y = (y*Ba+ha[t[i]]) % P;
	mi1 = (x*W%P + y) % P;
}

unordered_map <int, bool> ump, umt;

void Solve1()
{
	while(q --)
	{
		string s, t; cin >> s >> t;
		s = ' ' + s; t = ' ' + t;
		Calc(s, t);
		ump.clear(); umt.clear();
		int x = 0;
		umt[0] = 1;
		for(int i=p2; i<=le; i++)
		{
			x = (x*Ba+ha[s[i]]) % P;
			umt[x] = 1; 
		}
		x = 0;
		ump[0] = 1;
		for(int i=p1,w=1; i>=1; i--)
		{
			x = (ha[s[i]]*w+x) % P;
			ump[x] = 1; (w *= Ba) %= P;
		}
		//cerr << mi1 << '\n';
		int ans = 0;
		for(int i=1; i<=n; i++)
			if(ump.find(pr[i])!=ump.end() && mi[i]==mi1 && umt.find(ta[i])!=umt.end())
				ans ++;
		cout << ans << '\n';
	}
}

//void Solveab()
//{
//	while(q --)
//	{
//		string s, t; cin >> s >> t;
//		s = ' ' + s; t = ' ' + t;
//		int le = s.length()-1, ps=-1, pt=-1;
//		for(int j=1; j<=le&&ps==-1; j++)
//			if(s[j]=='b') ps = j;
//		for(int j=1; j<=le&&pt==-1; j++)
//			if(t[j]=='b') pt = j;
//		int p = pt-ps+L;
//		qry[p].push_back({ps-1, le-ps});
//	}
//	for(int i=-L; i<L; i++)
//	{
//		
//	}
//}

signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    W = rnd();
    for(int i='a'; i<='z'; i++)
    	ha[i] = rnd();
	cin >> n >> q;
	fla = (q==1) || (n<=1000&&q<=1000);
	for(int i=1; i<=n; i++)
	{
		string s, t; cin >> s >> t;
		s = ' ' + s; t = ' ' + t;
		Calc(s, t);
		pr[i] = pr1; mi[i] = mi1; ta[i] = ta1;
//		if(fla) continue;
//		int le = s.length()-1, ps=-1, pt=-1;
//		for(int j=1; j<=le&&ps==-1; j++)
//			if(s[j]=='b') ps = j;
//		for(int j=1; j<=le&&pt==-1; j++)
//			if(t[j]=='b') pt = j;
//		int p = pt-ps+L;
//		pr2[p].push_back(ps-1);
//		ta2[p].push_back(le-ps);
	}
	if(1)
		return Solve1(), 0;
	//else
	//	return Solveab(), 0;
    return 0;
}

