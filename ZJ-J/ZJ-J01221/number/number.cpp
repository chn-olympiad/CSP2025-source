#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int b[N],tot=0;
void solve(){
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			b[++tot]=s[i]-'0';
		}
	}
	sort(b+1,b+tot+1);
	for(int i=tot;i>=1;i--)cout<<b[i];
	return;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}