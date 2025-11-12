#include<bits/stdc++.h>
#define rep(i, l, r) for(int i(l);i<=(r);++i)
#define per(i, r, l) for(int i(r);i>=(l);--i)
using namespace std;

const int N = 2e5 + 10;
string s1[N];
string s2[N];
int n, qcnt;
namespace sub1{
	vector<int> nxt1[N],nxt2[N];
	bool vis[N];
	
	
	string t1, t2;
	void work(){
		int ans = 0;
		
		cin >> t1 >> t2;
		t1 = '#' + t1, t2 = '#' + t2;
		if(t1.size() != t2.size()){
			puts("0");
			return ;
		}
		int len = t1.size()-1;
		int L = 1, R = len;
		rep(i, 1, len)
			if(t1[i] != t2[i]){
				L = i; break;
			}
		per(i, len, 1)
			if(t1[i] != t2[i]){
				R = i; break;
			}
//		cerr << ">>>" << L << " " << R << endl;
		rep(id, 1, n){
			int lp = s1[id].size()-1;
//			cerr << id << ":\n";
			
			int j = 0;
			rep(i, 1, len){
				while(j != -1 && s1[id][j+1] != t1[i])j = nxt1[id][j];
				if(++j == lp)vis[i] = 1;
//				cerr << j << ",";
			}
//			cerr<<endl;
			
			j = 0;
			rep(i, 1, len){
				while(j != -1 && s2[id][j+1] != t2[i])j = nxt2[id][j];
				if(++j == lp && vis[i]){
					ans += (i >= R && i-lp+1 <= L);
				}
//				cerr<<j<<',';
			}
//			cerr<<endl;
			rep(i, 1, len)/*cerr << vis[i] << ' ', */vis[i] = 0;
//			cerr << endl;
		}
		printf("%d\n",ans);
	}
	
	
	void init(string &s, vector<int> &nxt){
		nxt[0] = -1;
		int len = s.size()-1;
		rep(i, 1, len){
			int j = nxt[i-1];
			while(j != -1 && s[j+1] != s[i])j = nxt[j];
			nxt[i] = ++j;
//			cerr << nxt[i] << ' ';
		}
//		cerr << endl;
	}
	
	void solve(){
		rep(i, 1, n){
			s1[i] = '#' + s1[i];
			s2[i] = '#' + s2[i];
			nxt1[i].resize(s1[i].size()+5, 0);
			nxt2[i].resize(s2[i].size()+5, 0);
//			cerr << "Case: " << i << endl;
//			cerr << "1:\n";
			init(s1[i], nxt1[i]);
//			cerr << "2:\n";
			init(s2[i], nxt2[i]);
		}
		while(qcnt--){
			work();
		}
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&qcnt);
	int L1 = 0;
	rep(i, 1, n)cin >> s1[i] >> s2[i], L1 += s1[i].size(), L1 += s2[i].size();
//	if(	L1 <= 2000)
		sub1::solve();
	return 0;
}