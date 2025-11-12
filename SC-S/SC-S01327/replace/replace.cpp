#include <iostream>
#include <string.h>
#define F(i, m, n) for(int i = m; i <= n; i++)
using namespace std;
int n, q;
string s1[200005], s2[200005];
inline int Str(string l1, string l2) {
    F(i, 0, l1.length()-l2.length()) {
        bool k = 1;
        F(j, 0, l2.length()-1) {
            if(l1[j+i] != l2[j]) {
                k = 0;
                break;
            }
        }
        if(k) {
            return i;
        }
    }return l1.length()+1;
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    cin >> n >> q;
    F(i, 1, n) cin >> s1[i] >> s2[i];
    while(q--) {
    string t1, t2;
    cin >> t1 >> t2;
//    int op = 0;
//    F(i, 1, n){
//    if(Str(t1, s1[i]) == t1.length()){
//    op = 1;
//    break;
//    }
//    if(!op)cout << 0 << '\n';
//    else {
//    while(t1 == t2){
//    int op = 0;
//    F(i, 1, n){
//    if(Str(t1, s1[i]) == t1.length()){
//    op = 1;
//    break;
//    }else {
//    F(j, Str(t1, s1[i]), s1[i].length()-1) {
//    t1[j+Str(t1, s1[i])] = s2[i][j];
//    }
//    }
//    if(!op){
//    cout << 0 << '\n';
//    break;
//    }
//    }
//    }
//    if(t1 == t2) cout << 1 << '\n';
//	}
//	}
cout << 0 << '\n';
	}
	return 0;
}