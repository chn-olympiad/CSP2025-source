#include<bits/stdc++.h>
using namespace std;
const int N = 200005,M = 5000006;
int n,q;
long long ans = 0;
string s1[N],s2[N],t1,t2,tt;
string repa(string x,int y){
	int pos = x.find(s1[y]),j = 0;
	string xx = "";
	for (int i = 0;i < x.length();i++){
		if (i < pos){
			xx += x[i];
		}else if (i > pos + s1[y].length()-1){
			xx += x[i];
		}else{
			xx += s2[y][j];j++;
		}
	}
	return xx;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (int i = 1;i <= n;i++){
		cin >> s1[i] >> s2[i];
	}
	while(q--){
		cin >> t1 >> t2;
		if (t1.length() != t2.length()){
			cout << 0 << endl;
			continue;
		}
		for (int i = 1;i <= n;i++){
			if (t1.find(s1[i]) <= M){
				tt = repa(t1,i);
			}
			if (tt == t2){
				ans++;
			}
			tt = "";
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}

