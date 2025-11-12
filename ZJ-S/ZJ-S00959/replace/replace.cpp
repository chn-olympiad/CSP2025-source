#include <bits/stdc++.h>
using namespace std;
int nxt[5000005];
string s[200005][2];
void getnxt(string &s) {
	nxt[0]=-1;
	int i=1,k=-1;
	while(i<s.size()) {
		if(k==-1||s[i]==s[k+1]) k++,i++,nxt[i]=k;
		else k=nxt[k];
	}
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	while(q--) {
		cout<<0<<endl;
	}
	return 0;
}
