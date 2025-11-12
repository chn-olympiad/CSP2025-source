#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
char s[N];
bool isnum(char c){
	return (c>='0'&&c<='9');
}
int f[15];
string ans="";
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(isnum(s[i])){
			int x=s[i]-'0';
			f[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(f[i]){
			f[i]--;
			cout<<i;
		}
	}
	return 0;
}
