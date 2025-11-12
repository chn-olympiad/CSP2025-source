#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

const int MAXN = 2e5 + 5;
struct S{
	string s1, s2;
	bool operator<(const S &rhs) const{
		return s1 < rhs.s1;
	}
}ss[MAXN];
int n, m;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

inline int lowerbound(string x){
	int l = 1, r = n, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(ss[mid].s1 > x) r = mid - 1;
		if(ss[mid].s1 == x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		cin>> ss[i].s1>> ss[i].s2;
	sort(ss + 1, ss + 1 + n);
	while(m--){
		string t1, t2;
		cin>> t1>> t2;
		int len1 = t1.length(), len2 = t2.length();
		if(len1 != len2){cout<< 0<< "\n"; continue;}
		int ans = 0;
		for(int len = 1; len <= len1; len++)
			for(int l = 0, r; (r = l + len - 1) < len1; l++){
				string tmp = t1.substr(l, len);
				int idx = lowerbound(t1.substr(l, len));
				for(; ss[idx].s1 == tmp; idx++){
					for(int i = l; i <= r; i++) t1[i] = ss[idx].s2[i - l];
					if(t1 == t2) ans++;
					for(int i = l; i <= r; i++) t1[i] = tmp[i - l]; 
				}
			}
		cout<< ans<< "\n"; 
	}
	fclose(stdin); fclose(stdout);
	return 0;
} 
