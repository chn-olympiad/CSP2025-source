#include<bits/stdc++.h>
#define int long long
using namespace std;
#define filout(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
string str;
int len;
constexpr int N=12;
int app[N];
bool isnum(char c){
	return ((c>='0')&&(c<='9'));
}
signed main(){
	freopen("number.in", "r", stdin); freopen("number.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>str;
	len=str.size();
	str=" "+str;
	for(int i=1;i<=len;i++){
		if(!isnum(str[i])) continue;
		++app[str[i]-'0'];
	}
	for(int i=9;i>=0;i--){
		while(app[i]--) cout<<i;
	}
	return 0;
}
