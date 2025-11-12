#include<bits/stdc++.h>
typedef long long Int;
typedef unsigned long long uInt;
constexpr Int MAXN = 200000;
constexpr Int BASE = 131;
constexpr Int MOD = 19491001;
std:: set<uInt> un;
Int N, Q, bar[1 + MAXN], val[1 + MAXN];
uInt hash1[1 + MAXN], hash2[1 + MAXN], thash1[1 + MAXN], thash2[1 + MAXN];
bool islemp[1 + MAXN], isremp[1 + MAXN];
std:: unordered_map<uInt, std:: vector<Int>> prehs, sufhs, allp, ck;
inline void ins(std:: unordered_map<uInt, std:: vector<Int>> &con, uInt key, Int rap){
	if (con.find(key) == con.end()){
		std:: vector<Int> tv;
		tv.emplace_back(rap);
		con[key] = tv;
	} else {
		con[key].emplace_back(rap);
	}
}
void deal(std:: string &S1, std:: string &S2, Int pos){
	Int lpos = 0, rpos = 0;
	for (Int i = 0 ; i < (Int)S1.length() ; i++){
		if (S1[i] != S2[i]){
			lpos = i;
			break;
		}
	}
	for (Int i = (Int)S1.length() - 1 ; i >= 0 ; i--){
		if (S1[i] != S2[i]){
			rpos = i;
			break;
		}
	}
	for (Int i = lpos ; i <= rpos ; i++){
		hash1[pos] *= BASE, hash1[pos] += uInt(S1[i]);
		hash2[pos] *= BASE, hash2[pos] += uInt(S2[i]);
	}
	for (Int i = 0 ; i < S1.length() ; i++){
		thash1[pos] *= BASE, thash1[pos] += uInt(S1[i]);
		thash2[pos] *= BASE, thash2[pos] += uInt(S2[i]);
	}
	if (lpos == 0 && rpos == (Int)S1.length() - 1){
		ins(allp, hash1[pos], pos);
	}
	if (lpos != 0) {
		uInt hp = 0;
		for (Int i = lpos - 1 ; i >= 0 ; i--){
			hp *= BASE, hp += uInt(S1[i]);
		}
		ins(prehs, hp, pos);
//		prehs[hp] = pos;
	} else{
		islemp[pos] = true;
	}
	if (rpos != (Int)S1.length() - 1){
		uInt hs = 0;
		for (Int i = rpos + 1 ; i < (Int)S1.length() ; i++){
			hs *= BASE, hs += uInt(S1[i]);
		}
		ins(sufhs, hs, pos);
//		sufhs[hs] = pos;
	} else {
		isremp[pos] = true;
	}
}
Int getans(std:: string &S1, std:: string &S2){
	Int lpos = 0, rpos = 0;
	for (Int i = 0 ; i < (Int)S1.length() ; i++){
		if (S1[i] != S2[i]){
			lpos = i;
			break;
		}
	}
	for (Int i = (Int)S1.length() - 1 ; i >= 0 ; i--){
		if (S1[i] != S2[i]){
			rpos = i;
			break;
		}
	}
	uInt tmp1 = 0, tmp2 = 0;
	for (Int i = lpos ; i <= rpos ; i++){
		tmp1 *= BASE, tmp1 += uInt(S1[i]);
		tmp2 *= BASE, tmp2 += uInt(S2[i]);
	}
	Int res = 0;
	if (allp.find(tmp1) != allp.end()){
		for (Int rap: allp[tmp1]){
//			if (islemp[allp[tmp1]] && isremp[allp[tmp1]] && hash2[allp[tmp1]] == tmp2) {
			if (islemp[rap] && isremp[rap] && hash2[rap] == tmp2) {
				res += val[rap];
			}
		}
	}
	if (rpos != (Int)S1.length() - 1){
		uInt hs = 0;
		for (Int i = rpos + 1 ; i < (Int)S1.length() ; i++){
			hs *= BASE, hs += uInt(S1[i]);
			if (sufhs.find(hs) != sufhs.end()){
				for (Int rap: sufhs[hs]){
//					if (islemp[sufhs[hs]] && hash2[sufhs[hs]] == tmp2) res++;
					if (islemp[rap] && !isremp[rap] && hash2[rap] == tmp2) res += val[rap];
					
				}
			}
		}
	}
	if (lpos != 0){
		uInt hp = 0;
		for (Int i = lpos - 1 ; i >= 0 ; i--){
			hp *= BASE, hp += uInt(S1[i]);
			if (prehs.find(hp) != prehs.end()){
				for (Int rap: prehs[hp]){
//					if (isremp[prehs[hp]] && hash2[prehs[hp]] == tmp2) res++;
					if (!islemp[rap] && isremp[rap] && hash2[rap] == tmp2) res += val[rap];
					
				}
			}
		}
	}
	if (lpos != 0 && rpos != (Int)S1.length() - 1){
		uInt hs = 0, hp = 0;
		for (Int i = rpos + 1 ; i < (Int)S1.length() ; i++){
			hs *= BASE, hs += uInt(S1[i]);
			if (sufhs.find(hs) != sufhs.end()){
				for (Int rap: sufhs[hs]){
//					bar[sufhs[hs]]++;
					bar[rap]++;
				}
			}
		}
		for (Int i = lpos - 1 ; i >= 0 ; i--){
			hp *= BASE, hp += uInt(S1[i]);
			if (prehs.find(hp) != prehs.end()){
				for (Int rap: prehs[hp]){
//					if (bar[prehs[hp]] == 1 && hash2[prehs[hp]] == tmp2) res++;
					if (bar[rap] == 1 && hash2[rap] == tmp2) res += val[rap];
				}
			}
		}
		hs = 0;
		for (Int i = rpos + 1 ; i < (Int)S1.length() ; i++){
			hs *= BASE, hs += uInt(S1[i]);
			if (sufhs.find(hs) != sufhs.end()){
				for (Int rap: sufhs[hs]){
//					bar[sufhs[hs]]--;
					bar[rap]--;
				}
			}
		}
	}
	return res;
}
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std:: ios:: sync_with_stdio(false);
	std:: cin.tie(nullptr);
	std:: cin >> N >> Q;
	for (Int i = 1 ; i <= N ; i++){
		std:: string T1, T2;
		std:: cin >> T1 >> T2;
		deal(T1, T2, i);
		val[i] = 1;
	}
	for (Int i = 1 ; i <= Q ; i++){
		std:: string T1, T2;
		std:: cin >> T1 >> T2;
		std:: cout << getans(T1, T2) << '\n';
	}
	return 0;
}

