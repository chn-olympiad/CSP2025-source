#include <bits/stdc++.h>
using namespace std;
int c[20];
signed main () {
	freopen ("number.in", "r", stdin);
	freopen ("number.out", "w", stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(isdigit(s[i])) c[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=c[i];j++) printf("%d",i);
	}
	return 0;
}

