#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define maxm int(2e6+5)
using namespace std;
int n, q, m, ans;
string s[maxn][2], t[2];
bool chksame[2][maxn];
struct node{int nxt[26]; vector<int> vec;} Trie[2][maxm];
int tail[2];
void Tinsert(int x, int y) {
	int now=1;
	for(auto ch:s[y][x]) {
		if(!Trie[x][now].nxt[ch-'a']) {
			tail[x]++;
			Trie[x][now].nxt[ch-'a']=tail[x];
			now=tail[x];
		}
		else now = Trie[x][now].nxt[ch-'a'];
	}
//	cout<<x<<":"<<y<<"inserted to"<<now<<endl;
	Trie[x][now].vec.push_back(y);
}
int fndsame(int x, int y) {
	int i=0, j=0, anscnt=0;
	while(i<Trie[0][x].vec.size() && j<Trie[1][y].vec.size()) {
		if(Trie[0][x].vec[i]==Trie[1][y].vec[j]) {
			anscnt++;
		}
		if(Trie[0][x].vec[i]>Trie[1][y].vec[j]) j++;
		else i++;
	}
	return anscnt;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	tail[0]=tail[1]=1;
	cin>>n>>q;
	for(int i = 1; i <= n; i++) {
		cin>>s[i][0]>>s[i][1];
		Tinsert(0, i);
		Tinsert(1, i);
	}
	
	while(q--) {
		ans=0;
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()) {
			cout<<"0\n";
			continue;
		}
		m=t[0].size();
		t[0]="#"+t[0];
		t[1]="#"+t[1];
		chksame[0][0]=chksame[1][m+1]=1;
		for(int j = 1; j <= m; j++) {
			chksame[0][j]=chksame[1][j]=0;
		}
		for(int j = 1; j <= m; j++) {
			if(t[0][j]==t[1][j]) {
				chksame[0][j]=1;
			} else break;
		}
		for(int j = 1; j <= m; j++) {
			if(t[0][m-j+1]==t[1][m-j+1]) {
				chksame[1][m-j+1]=1;
			} else break;
		}
		
//		for(int j = 1; j <= m; j++) cout<<chksame[0][j]<<' '; cout<<endl;
//		for(int j = 1; j <= m; j++) cout<<chksame[1][j]<<' '; cout<<endl;

		for(int i = 1; i <= m; i++) {
			if(!chksame[0][i-1]) break;
			int now[2];
			now[0]=now[1]=1;
			for(int j = i; j <= m; j++) {
//				cout<<"nowj:"<<j<<endl;
				bool flag=true;
				for(int k = 0; k <= 1; k++) {
					if(Trie[k][now[k]].nxt[t[k][j]-'a']) {
						now[k]=Trie[k][now[k]].nxt[t[k][j]-'a'];
					} else {
//						cout<<k<<"missing\n";
						flag=false;
						break;
					}
				}
				if(!flag) break;
				if(!chksame[1][j+1]) continue;
//				cout<<now[0]<<' '<<now[1]<<endl;
				ans+=fndsame(now[0], now[1]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
