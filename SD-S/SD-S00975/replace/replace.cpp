#include<bits/stdc++.h>
using namespace std;
const int N=2e5+6;
string s[N][2];
int sl[N];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for (int i=0; i<n; i++) {
		cin>>s[i][0]>>s[i][1];
		sl[i]=s[i][0].size();
	}
	string t1,t2;
	for (int i=0,l1,l2,res=0; i<q; i++) {
		cin>>t1>>t2;
		l1=t1.size();
		if (l1!=t2.size()) {
			cout<<0<<endl;
			continue;
		}
		res=0;
		for (int j=0; j<n; j++) {
			for (int cnt=t1.find(s[j][0]); cnt!=-1; cnt=t1.find(s[j][0],cnt+1)) {
				if (cnt) {
					if (t1.substr(0,cnt)+s[j][1]+t1.substr(cnt+sl[j])==t2) res++;
				} else if (s[j][1]+t1.substr(cnt+sl[j])==t2) res++;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}

