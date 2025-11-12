#include <bits/stdc++.h>
using namespace std;
int n,q,ans;
string x[200025],y[200025],px,py,sx,sy;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=0; i<n; i++) {
		cin>>x[i]>>y[i];
	}
	for(int r=0; r<q; r++) {
		ans=0;
		cin>>px>>py;
		if(px.size()!=py.size())cout<<0<<endl;
		else {
			sx=px,sy=py;
			for(int i=0; i<px.size(); i++) {
				for(int j=0; j<n; j++) {
					px=sx;
					for(int k=0; k<x[j].size(); k++) {
						if(i+k<px.size()&&px[i+k]==x[j][k])px[i+k]=y[j][k];
						else {
//						cout<<px<<endl;
							px=sx;
							break;
						}
					}
					if(px==py)ans++;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb*/
