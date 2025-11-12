#include <bits/stdc++.h>
using namespace std;
const int M=1e5+3;
string a[M],b[M];
string e;
string f;
int n,q,ans=0;
void sol() {
	int dex=-1,lon=0;
	int fs=f.size(),es=e.size();
	if(es!=fs)
	{
		ans=0;
		return;
	}
	string dif,diff;
	for(int i=0; i<es; i++) {
		if(e[i]!=f[i]) {
			lon++;
			if(dex==-1)dex=i;
		}
	}
	dif=e.substr(dex,lon);
	diff=f.substr(dex,lon);
	for(int i=0; i<n; i++) {
		if(a[i].find(dif)<=a[i].size()&&b[i].find(diff)<=b[i].size()) {
			if(f.find(b[i])<=fs&&e.find(a[i])<=es)
			ans++;
		}
	}
	return;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>a[i]>>b[i];
	}
	for(int i=0; i<q; i++) {
		cin>>e>>f;
		sol();
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
