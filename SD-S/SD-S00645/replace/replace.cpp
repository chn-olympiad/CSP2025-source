#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
string sa[maxn],sb[maxn];
string qa[maxn],qb[maxn];
int n,q;
//
//struct note{
//	int pr,ls,len,id;
//}ins[maxn],qus[maxn];
//
//void init(int id)
//{
//	string ta = sa[id];
//	int stb,edb;
//	for(int i = 0;i < ta.size();i++)
//		if(ta[i] == 'b') 
//		{
//			stb = i;
//			break;
//		}
//	int pr = stb;
//	ta = sb[id];
//	for(int i = 0;i < ta.size();i++)
//		if(ta[i] == 'b')
//		{
//			edb = i;
//			break;
//		}
//	int ls = ta.size() - edb - 1;
//	int len = edb - stb + 1;
//	if(len < 0) len = 5000000 - len;
//	ins[id] = {pr,ls,len,0};
//	return;
//}
//
//void preinit(int id)
//{
//	string ta = qa[id];
//	int stb,edb;
//	for(int i = 0;i < ta.size();i++)
//		if(ta[i] == 'b') 
//		{
//			stb = i;
//			break;
//		}
//	int pr = stb;
//	ta = qb[id];
//	for(int i = 0;i < ta.size();i++)
//		if(ta[i] == 'b')
//		{
//			edb = i;
//			break;
//		}
//	int ls = ta.size() - edb - 1;
//	int len = edb - stb + 1;
//	if(len < 0) len = 5000000 - len;
//	ins[id] = {pr,ls,len,id};
//	return;
//}
//int ans[maxn];
//bool cmp(note x,note y) {return x.pr < y.pr;}
//int st[10000050];
//int solveB()
//{
//	for(int i = 1;i <= n;i++) init(i);
//	for(int i = 1;i <= q;i++) preinit(i);
//	sort(ins + 1,ins + n + 1,cmp);
//	sort(qus + 1,qus + q + 1,cmp);
//	int nowx = 1;
//	for(int i = 1;i <= q;i++)
//	{
//		int mxpr = qus[i].pr;
//		while(nowx <= n && ins[nowx].pr <= mxpr) 
//		{
//			st[ins[nowx].len]++;
//			nowx++;
//		}
//		ans[qus[i].id] = st[qus[i].len];
//	}
//	for(int i = 1;i <= q;i++) cout << ans[i] << "\n";
//	return 0;
//}

signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> q;
//	bool flab = 1;
	for(int i = 1;i <= n;i++) 
	{
		cin >> sa[i] >> sb[i];
//		for(char ch : sa[i]) if(ch != 'a' && ch != 'b') flab = 0;
//		for(char ch : sb[i]) if(ch != 'a' && ch != 'b') flab = 0;
	}
	for(int i = 1;i <= q;i++) 
	{
		cin >> qa[i] >> qb[i];
		int pos = -1;
		for(int j = qa[i].size() - 1;j >= 0;j--) 
			if(qa[i][j] != qb[i][j]) 
			{
				pos = j;
				break;
			}
		int res = 0;
		int stt = qa[i].size();
		for(int j = 0;j < qa[i].size();j++) 
			if(qa[i][j] != qb[i][j])
			{
				stt = j;
				break;
			}
			
		for(int j = 0;j <= stt;j++)
			for(int id = 1;id <= n;id++)
			{
//				if(id == 3 && j == 2) cout << j << " " << "1" << "\n";
				bool flag = 1;
				int ed = j + sa[id].size();
				if(ed > qa[i].size()) continue;
				if(ed <= pos) continue;
				for(int k = j;k < ed;k++)
					if(sa[id][k - j] != qa[i][k] || sb[id][k - j] != qb[i][k]) 
					{
//						if(id == 3 && j == 2) cout << k << " " << sa[id][k - j] << " " <<  qa[i][j] << " " <<  sb[id][k - j]  << " " <<  qb[i][j] << "\n";
						flag = 0;
						break;
					}
				if(flag) 
				{
					res++;
//					cout << j << " " << id << " " << pos <<  "\n";
				}
			}
		cout << res << "\n";
	}
//	if(flab) 
//	{
//		solveB();
//		return 0;
//	}
	return 0;
}
