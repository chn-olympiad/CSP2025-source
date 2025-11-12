#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;

int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<vector<int>> nex(n+1);
	vector<pair<string,string>> pp;
	
	for (int it=0;it<n;it++) {
		string p,q;
		cin>>p>>q;
		pp.push_back({p,q});
		
		int plen=p.length();
		nex[it].resize(plen+1,0);
		
		nex[it][0]=-1;
		int i=0,j=-1;
		while (i<plen) {
			if (j==-1 || p[i]==p[j]) {
				i++,j++;
				nex[it][i]=j;
			}else j=nex[it][j];
		}
	}
	for (int it=0;it<m;it++) {
		int ans=0;
		string a,b;
		cin>>a>>b;
		for (int idx=0;idx<n;idx++) {
			int plen=pp[idx].first.length();
			
			int slen=a.length();
			int i=0,j=0;
			
			while (i<slen && j<plen) {
				if (j==-1 || a[i]==pp[idx].first[j]) {
					i++,j++;
				}else j=nex[idx][j];
			}
			if (j==plen) {
				int pos=i-j;
				string prev=a.substr(0,pos);
				string suff=a.substr(pos+plen,n-(pos+plen)+1);
				if (prev+pp[idx].second+suff==b) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}