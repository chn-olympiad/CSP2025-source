// 题意：
// 首先找到第一个和最后一个不同的位置
// 你的字符串长度必须大于它们的距离
// 然后，枚举被替换的字符串的结尾位置
// 然后可以On地去问每一个字符串
// 
// 特殊性质B
// 考虑开n个vector
// 下标是两个b的距离
// 然后往里面扔串长，以s2中b出现的位置为关键字
// 最后问一个前缀当中有多少个点的后缀长度<=某个值
#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define fastio ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
constexpr int N = 2e5+5;
constexpr int L = 5e6+5;
constexpr ull B = 1e9+51;
int n,Q,maxsiz;
string s[N][2];
ull nhsh[N][2],mi[L];

namespace Hash{
	inline ull getHash(string &s){
		ull h=0; int siz = s.size();
		for(int i=1; i<=siz; i++) h=h*B+s[i-1];
		return h;
	}
	inline ull split(int l,int r,ull *hsh){
		if(!l||!r) return 0;
		return hsh[r] - hsh[l-1]*mi[r-l+1];
	}
}
using namespace Hash;
ull hval1[L],hval2[L];
namespace BF{
	
	inline void main(){
		string S,T;
		while(Q--){
			cin >> S >> T;
			if(S.size() != T.size()){
				puts("0");
				continue;
			}
			int siz = S.size();
			LL cnt=0;
			for(int i=1; i<=siz; i++){
				hval1[i]=hval1[i-1]*B+S[i-1];
				hval2[i]=hval2[i-1]*B+T[i-1];
			}
			int fir=0, lst=0;
			for(int i=1; i<=siz; i++){
				if(S[i-1]!=T[i-1]){
					fir=i;
					break;
				}
			}
			for(int i=siz;i>=1;i--){
				if(S[i-1]!=T[i-1]){
					lst=i;
					break;
				}
			}
			if(!fir){
				for(int i=1; i<=siz; i++){
					for(int j=1; j<=n; j++){
						if(i<s[j][0].size())continue;
						cnt += (split(i-s[j][0].size()+1, i, hval1) == nhsh[j][0]);
					}
				}
			}
			else{
				for(int i=lst; i<=siz; i++){
					for(int j=1; j<=n; j++){
						if(i-s[j][0].size()+1 > fir) continue;
						cnt += (split(i-s[j][0].size()+1, i, hval1) == nhsh[j][0]) && 
							(split(i-s[j][1].size()+1, i, hval2) == nhsh[j][1]);
					}
				}
			}
			printf("%lld\n", cnt);
		}
		return ;
	}
}

//namespace BF2{
//	int dis1[N],dis2[N];
//	unordered_map<int,int> cnt;
//	unordered_map<int,vector<int>> args;
//	unordered_map<int,int>L,R;
//	inline void main(){
//		for(int i=1; i<=n; i++){
//			dis1[i] = distance(s[i][0].begin(), find(s[i][0].begin(),s[i][0].end(),'b'));
//			dis2[i] = distance(s[i][1].begin(), find(s[i][1].begin(),s[i][1].end(),'b'));
//			int delta = dis1[i] - dis2[i];
//			cnt[delta]++;
//			args[delta].pb(i);
//		}
//		for(int delta=-maxsiz,pos=1; delta<=maxsiz; delta++){
//			if(!cnt[delta]) continue;
//			L[delta] = pos;
//			R[delta] = pos + cnt[delta] - 1;
//			for(int i=pos; i<=pos+cnt[delta]-1; i++){
//				a[i] = args[delta][i-pos];
//			}
//			pos += cnt[delta];
//		}
//		sgt.build(); 
//		return ;
//	}
//}

namespace BF3{
	int dis[N][2];
	unordered_map<int,vector<int>>cnt;
	inline void main(){
		string S,T;
		for(int i=1; i<=n; i++){
			dis[i][0] = distance(s[i][0].begin(),find(s[i][0].begin(), s[i][0].end(), 'b'));
			dis[i][1] = distance(s[i][1].begin(),find(s[i][1].begin(), s[i][1].end(), 'b'));
			cnt[dis[i][0]-dis[i][1]].pb(i);
		}
		while(Q--){
			cin >> S >> T;
			if(S.size() != T.size()){
				puts("0");
				continue;
			}
			LL ans=0;
			int siz = S.size();
			int dis1 = distance(S.begin(), find(S.begin(), S.end(), 'b'));
			int dis2 = distance(T.begin(), find(T.begin(), T.end(), 'b'));
			for(auto idx : cnt[dis1-dis2]){
				ans += (dis[idx][0]<=dis1&&s[idx][0].size()-dis[idx][0]-1 <= siz-dis1-1);
			}
			printf("%lld\n", ans);
		}
		return ;
	}
}


namespace PHI{
	
	struct Node{
		string s1,s2;
		int siz;
		ull s1hash, s2hash;
		inline bool operator<(const Node&o){
			return siz < o.siz;
		}
	}nd[N];
	
	vector<int> pos[26][26];
	
	inline void main(){
		string S,T;
		for(int i=1; i<=n; i++){
			nd[i].s1 = s[i][0];
			nd[i].s2 = s[i][1];
			nd[i].siz = s[i][0].size();
			nd[i].s1hash = nhsh[i][0];
			nd[i].s2hash = nhsh[i][1];
		}
		sort(nd+1, nd+n+1);
		
		while(Q--){
			LL ans=0;
			cin >> S >> T;
			int siz = S.size();
			
			if(S.size() != T.size()){
				puts("0");
				continue;
			}
			
			for(int i=0;i<26;i++)for(int j=0;j<26;j++)pos[i][j].clear();
			for(int i=1; i<=siz; i++){
				hval1[i]=hval1[i-1]*B+S[i-1];
				hval2[i]=hval2[i-1]*B+T[i-1];
				pos[S[i-1]-'a'][T[i-1]-'a'].pb(i);
			}
			
			int fir=siz, lst=siz;
			for(int i=1; i<=siz; i++){
				if(S[i-1]!=T[i-1]){
					fir=i;
					break;
				}
			}
			for(int i=siz;i>=1;i--){
				if(S[i-1]!=T[i-1]){
					lst=i;
					break;
				}
			}
			
			for(int i=n; i>=1; i--){
				if(nd[i].siz < lst-fir+1) break;
				if(nd[i].siz > siz) continue;
				for(int j : pos[nd[i].s1[0] - 'a'][nd[i].s2[0] - 'a']){
					if(j > fir) break;
					if(j + nd[i].siz-1 > siz) break;
					if(j + nd[i].siz-1 < lst) continue;
					ans += split(j,j+nd[i].siz-1,hval1) == nd[i].s1hash
						&& split(j,j+nd[i].siz-1,hval2) == nd[i].s2hash;
				}
			}
			printf("%lld\n", ans);
		}
		return ; 
	}
}

signed main(){
	fastio;
	bool isab = 1;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> Q;
	mi[0]=1;
	for(int i=1; i<L; i++) mi[i]=mi[i-1]*B;
	for(int i=1; i<=n; i++){
		cin >> s[i][0] >> s[i][1];
		maxsiz = max(maxsiz, (int)s[i][0].size());
		nhsh[i][0] = getHash(s[i][0]);
		nhsh[i][1] = getHash(s[i][1]);
		if(isab) for(char t : s[i][0]) if(t>'b'){ isab=0; break; }
		if(isab) for(char t : s[i][1]) if(t>'b'){ isab=0; break; }
	}
	if(isab) BF3::main();
	else if(n<=1000) BF::main();
	else PHI::main(); 
	return 0;
}