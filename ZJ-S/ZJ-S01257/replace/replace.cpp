#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct node{
	string sl, sr, sm1, sm2;
}num[N];
struct wow{
	string sm1, sm2;
	int l, r;
}cha[N];
int check(string& str1, string& str2){
	int zz = 0;
	while(zz < str1.size() && zz < str2.size()){
		if(str1[zz] < str2[zz]) return 1;
		if(str1[zz] > str2[zz]) return 0;
		zz++;
	}
	if(zz != str1.size()){
		return 0;
	}
	if(zz != str2.size()){
		return 1;
	}
	return 2;
}
bool check2(string& wow1, string& wow2){
	if(wow1.size() > wow2.size()) return 0;
	int zz = 0;
	while(zz < wow1.size() && zz < wow2.size()){
		if(wow1[zz] != wow2[zz]) return 0;
		zz++;
	}
	return 1;
}
int cnt = 0;
bool cmp(node a, node b){
	int ls;
	ls = check(a.sm1, b.sm1);
	if(ls != 2) return ls;
	ls = check(a.sm2, b.sm2);
	if(ls != 2) return ls;
	ls = check(a.sl, b.sl);
	if(ls != 2) return ls;
	ls = check(a.sr, b.sr);
	if(ls != 2) return ls;
	return 0;
}
int main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	string str1, str2;
	cin >> n >> q;
	for(int i = 1, l, r; i <= n; i++){
		cin >> str1 >> str2;
		num[i].sl = "";
		num[i].sr = "";
		num[i].sm1 = "";
		num[i].sm2 = "";
		bool flag = 1;
		l = -1, r = 0;
		for(int j = 0; j < str1.size(); j++){
			if(str1[j] != str2[j]){
				r = max(r, j);
				if(l == -1) l = j;
			}
		}
		for(int j = l - 1; j >= 0; j--){
			num[i].sl = num[i].sl + str1[j];
		}
		for(int j = l; j <= r; j++){
			num[i].sm1 = num[i].sm1 + str1[j];
			num[i].sm2 = num[i].sm2 + str2[j];
		}
		for(int j = r + 1; j < str1.size(); j++){
			num[i].sr = num[i].sr + str1[j];
		}
	}
	sort(num + 1, num + n + 1, cmp);
	for(int i = 1; i <= n; i++){
		if(cha[cnt].sm1 != num[i].sm1 || cha[cnt].sm2 != num[i].sm2){
			cha[cnt].r = i - 1;
			cnt++;
			cha[cnt].l = i;
			cha[cnt].sm1 = num[i].sm1;
			cha[cnt].sm2 = num[i].sm2;
		}
	}
	cha[cnt].r = n;
	/*for(int i = 1; i <= cnt; i++){
		cout << cha[i].l << " " << cha[i].r << " " << cha[i].sm1 << " " << cha[i].sm2 << "\n";
	}*/
	for(int i = 1, l, r, ansl, ansr; i <= q; i++){
		cin >> str1 >> str2;
		node str3;
		l = -1, r = 0;
		for(int j = 0; j < str1.size(); j++){
			if(str1[j] != str2[j]){
				r = max(r, j);
				if(l == -1) l = j;
			}
		}
		for(int j = l; j <= r; j++){
			str3.sm1 = str3.sm1 + str1[j];
			str3.sm2 = str3.sm2 + str2[j];
		}
		ansl = 1, ansr = cnt;
		while(ansl < ansr){
			int mid = (ansl + ansr) >> 1;
			int ls = check(str3.sm1, cha[mid].sm1);
			if(ls == 1){
				ansr = mid - 1;
			}
			else if(ls == 0){
				ansl = mid + 1;
			}
			else{
				ls = check(str3.sm2, cha[mid].sm2);
				if(ls == 1){
					ansr = mid - 1;
				}
				else if(ls == 0){
					ansl = mid + 1;
				}
				else{
					ansl = mid;
					ansr = mid;
				}
			}
		}
		if(check(cha[ansl].sm1, str3.sm1) != 2 || check(cha[ansl].sm2, str3.sm2) != 2){
			cout << 0 << "\n";
		}
		else{
			//cout << cha[ansl].r - cha[ansl].l + 1 << "\n"; pianfen
			int ans = 0;
			for(int j = l - 1; j >= 0; j--){
				str3.sl = str3.sl + str1[j];
			}
			for(int j = r + 1; j < str1.size(); j++){
				str3.sr = str3.sr + str1[j];
			}
			for(int j = cha[ansl].l; j <= cha[ansl].r; j++){
				if(check2(num[j].sl, str3.sl) && check2(num[j].sr, str3.sr)) ans++;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
//15:38 T3 < T2 ??;
//16:07 tired;
//16:15 finished eating, let's goooooooo!;
//16:34 wahahahaha;
//16.44 wahahahaha;
//17.08 yi hao wo guo la hahahaha;
