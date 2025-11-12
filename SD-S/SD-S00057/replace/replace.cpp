#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
template<typename TY>
inline void read(TY &s){
	ll x = 0, f = 1;
	char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9'){
		x = (x<<1) + (x<<3) + (ch^48);
		ch = getchar();
	}
	s = x * f;
}
int n,q;
string s1[N],s2[N];
ll check(int l,int r,string &t1,string &t2){
	string t,p;
	ll res = 0;
	for(int i=l;i<=r;i++) t += t1[i];
	for(int i=l;i<=r;i++) p += t2[i];
	for(int i=1;i<=n;i++){
		if(t == s1[i] && s2[i] == p) res++; 
	}
	return res;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n); read(q);
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	string t1,t2;
	while(q--){
		ll res = 0;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()){
			cout << "0\n";
			continue;
		}
		int l1 = t1.size(),l2 = t2.size();
		string pre1,pre2;
		for(int i=0;i<l1;i++){
			string suf1,suf2;
			for(int j=l1-1;j>=i;j--){
				if(pre1 == pre2 && suf1 == suf2) 
					res += check(i,j,t1,t2);
				suf1 += t1[j]; suf2 += t2[j];
			}
			pre1 += t1[i]; pre2 += t2[i];
			if(pre1 != pre2) break;
		}
		cout << res << "\n";
	}
	return 0;
}
