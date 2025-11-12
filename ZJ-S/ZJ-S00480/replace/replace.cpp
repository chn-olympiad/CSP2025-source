#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n,q;
ll ans;
struct Node {
	string x,y;
}s[N],t;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>s[i].x>>s[i].y;
	for (int ii=1;ii<=q;ii++) {
		cin>>t.x>>t.y;
		ans=0LL;
		int len=t.x.size();
		for (int i=0;i<len;i++) {
			while (t.x[i]!=t.y[i]) {
				for (int j=1;j<=n;j++) {
					int f=1,lenb=s[j].x.size();
					for (int k=0;k<lenb;k++) {
						if (k>=len||s[j].x[k]!=t.x[i+k]) {
							f=0;
							break;
						}
					}
					if (f) {
						for (int k=0;k<lenb;k++)
							t.x[i+k]=s[j].y[k];
					}
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
