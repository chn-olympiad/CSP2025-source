#include <bits/stdc++.h>
using namespace std;
int n,q;
string t[1145],ti[1145],s,si;
int check(string s,string t) {
	int szs=s.size(),szt=t.size();
	for(int i=0;i<szs;i++) {
		if(i+szt<=szs) {
			bool flag=1;
			for(int j=0;j<szt;j++)
				if(s[i+j]!=t[j]) {
					flag=0;
					break;
				}
			if(flag)
				return i;
		}
	}
}
void solve() {
	int ans=0;
	cin>>s>>si;
	for(int i=1;i<=n;i++) {
		if(check(s,t[i])==check(si,ti[i]))
			ans++;
	}
	cout<<ans<<"\n";
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>t[i]>>ti[i];
	}
	while(q--) solve();
	return 0;
}

//nmd last 20min look T3 it is a easy hash??? f

//no li back sky
//wu li hui tian

//wo de bei shang ~ shi shui zuo de ~