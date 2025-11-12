#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
int n,m;
int ans=0;
struct node {
	string s1;
	string s2;
}s[N];
string t1,t2;
string xg(string t0,string t,string tt) {
	bool f=true;
	int lent0=t0.size();
	int lent=t.size();
	for(int i=0;i<=lent0-lent;i++) {
		f=true;
		for(int j=i;j<=i+lent-1;j++) {
			if(t0[j]!=t[j-i]) {
				f=false;
				break;
			}
		}
		if(f==true) {
			for(int j=i;j<=i+lent-1;j++) {
				t0[j]=tt[j-i];
			}
			break;
		}
	}
	return t0;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>s[i].s1>>s[i].s2;
	}
	while(m--) {
		ans=0;
		cin>>t1>>t2;
		string t11=t1;
		for(int i=1;i<=n;i++) {
			t11=t1;
			if(xg(t11,s[i].s1,s[i].s2)==t2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
