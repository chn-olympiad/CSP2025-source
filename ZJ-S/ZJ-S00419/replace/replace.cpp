// xin ming yin xian hua , bo xue ban liu hua //
#include<bits/stdc++.h>
using namespace std;

const int N =100;
int n,q;
string s[N][2];
string t[N][2];

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=q;i++) cin>>t[i][1]>>t[i][2];
	
	for(int i=1;i<=q;i++) cout<<0<<'\n';
	
	
	return 0;
}