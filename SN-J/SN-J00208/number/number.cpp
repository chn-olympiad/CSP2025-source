#include<iostream>
#include<string.h>
using namespace std;
constexpr int N=1e6+5;
char s[N];
int cnt[15],n;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>(s+1); n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(isdigit(s[i]))cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=cnt[i];j++)cout<<i;
	cout<<'\n';
	return 0;
}
