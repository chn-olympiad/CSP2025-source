#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string s;
int len,num[maxn],tot;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	len=s.length();
	for (int i=0;i<len;++i){
		char tmp=s[i];
		if (tmp>='0'&&tmp<='9'){
			tot++;
			num[tot] = tmp-'0';
		}
	}
	sort(num+1,num+tot+1);
	for (int i=tot;i>=1;--i) cout << num[i];

	return 0;
}

