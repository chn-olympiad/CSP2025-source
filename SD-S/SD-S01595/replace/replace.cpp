#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 10, base1 = 141, base2 = 179, mod1 = 19491001, mod2 = 1e9 + 3;


int n, q;
ll a1[3000010], a2[3000010], sa1[3000010], sa2[3000010], b1[3000010], b2[3000010], prea1[3000010], prea2[3000010], preb2[3000010], preb1[3000010];
string s1[MAXN], s2[MAXN], t1, t2;

//bool check1(int i, int j){
//	int len = s1[i].length();
//	for(int id = 0; id < len; id++){
//		if(s1[i][id] != t1[j+id]) return false;
//	}
//	return true;
//}
//
//bool check2(int i, int j){
//	int len = s2[i].length();
//	for(int id = 0; id < len; id++){
//		if(s2[i][id] != t2[j+id]) return false;
//	}
//	return true;
//}

bool check1(int i, int j){
	int len = s1[i].length();
	ll h1 = 0, h2 = 0;
	if(j != 0)
		h1 = prea1[j+len-1] - prea1[j-1],
		h2 = prea2[j+len-1] - prea2[j-1];
	else h1 = prea1[j+len-1],
		 h2 = prea2[j+len-1];
	h1 = (h1 % mod1 + mod1) % mod1, h2 = (h2 % mod2 + mod2) % mod2;
	ll tmp1 = a1[i], tmp2 = a2[i];
	tmp1 *= b1[j], tmp1 %= mod1;
	tmp2 *= b2[j], tmp2 %= mod2;
	return h1 == tmp1 && h2 == tmp2;
}
bool check2(int i, int j){
	int len = s2[i].length();
	ll h1 = 0, h2 = 0;
	if(j != 0)
		h1 = preb1[j+len-1] - preb1[j-1],
		h2 = preb2[j+len-1] - preb2[j-1];
	else h1 = preb1[j+len-1],
		 h2 = preb2[j+len-1];
	h1 = (h1 % mod1 + mod1) % mod1, h2 = (h2 % mod2 + mod2) % mod2;
	ll tmp1 = sa1[i], tmp2 = sa2[i];
	tmp1 *= b1[j], tmp1 %= mod1;
	tmp2 *= b2[j], tmp2 %= mod2;
	return h1 == tmp1 && h2 == tmp2;
}

void init(){
	b1[0] = 1;
	for(int i = 1; i <= 3e6; i++)
		b1[i] = b1[i-1] * base1 % mod1;
	for(int i = 1; i <= 3e6; i++)
		b2[i] = b2[i-1] * base2 % mod2;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	init();
	ios :: sync_with_stdio(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> s1[i] >> s2[i];
		int len = s1[i].length();
		for(int j = 0; j < len; j++)
			a1[i] += b1[j] * (s1[i][j]-'a'), a1[i] %= mod1;
		for(int j = 0; j < len; j++)
			a2[i] += b2[j] * (s1[i][j]-'a'), a2[i] %= mod2;
		for(int j = 0; j < len; j++)
			sa1[i] += b1[j] * (s2[i][j]-'a'), sa1[i] %= mod1;
		for(int j = 0; j < len; j++)
			sa2[i] += b2[j] * (s2[i][j]-'a'), sa2[i] %= mod2;
	}
	while(q--){
		cin >> t1 >> t2;
		int p1, p2;
		int len = t1.length(), ans = 0;
		
		for(int i = 0; i < len; i++)
			prea1[i] = prea1[i-1] + b1[i] * (t1[i]-'a'), prea1[i] %= mod1;
		for(int i = 0; i < len; i++)
			prea2[i] = prea2[i-1] + b2[i] * (t1[i]-'a'), prea2[i] %= mod2;
		for(int i = 0; i < len; i++)
			preb1[i] = preb1[i-1] + b1[i] * (t2[i]-'a'), preb1[i] %= mod1;
		for(int i = 0; i < len; i++)
			preb2[i] = preb2[i-1] + b2[i] * (t2[i]-'a'), preb2[i] %= mod2;
		
		for(p1 = 0; p1 < len; p1++){
			if(t1[p1] != t2[p1]){
				p1--;
				break;
			} 
		}
		for(p2 = len-1; p2 >= 0; p2--){
			if(t1[p2] != t2[p2]){
				p2++;
				break;
			} 
		}
//		cout << "debug : " << p1 << ' ' << p2 << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 0; j + s1[i].length()-1 < len; j++){
				if(check1(i, j) && check2(i, j)){
//					cout << i << ' ' << j << endl;
					if(p1 >= j-1 && p2 <= j + s1[i].length()-1+1)
						ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
