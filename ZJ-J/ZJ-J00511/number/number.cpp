#include <bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int xb=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<(int)s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			xb++;
			a[xb]=s[i];
		}
	}
	sort(a+1,a+1+xb);
	for(int i=xb;i>=1;i--) cout << a[i];
	return 0;
}
