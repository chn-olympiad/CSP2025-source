#include <bits/stdc++.h>
using namespace std;
const int maxn=200010;
int c[maxn],co[maxn];
void looktime() { cerr<<(double)clock()/CLOCKS_PER_SEC*1000.0<<"ms"<<endl; }
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		string s,s2;
		cin>>s>>s2;
		int pos=0;
		for(int j=0;j<s.size();j++) {
			if(s[j]=='b') {
				pos=j;
				break;
			}
		}
		c[i]=pos;
		for(int j=0;j<s2.size();j++) {
			if(s2[j]=='b') {
				pos=j;
				break;
			}
		}
		co[i]=pos;
	}
	for(int k=1;k<=q;k++) {
		int sum=0,pos=0;
		string s,s2;
		cin>>s>>s2; 
		for(int i=0;i<s.size();i++) {
			if(s[i]=='b') {
				pos=i;
				break;
			}
		}
		int l1=pos;
		for(int i=0;i<s2.size();i++) {
			if(s2[i]=='b') {
				pos=i;
				break;
			}
		}
		int l2=pos;
		for(int i=1;i<=n;i++)
			if(l1>=c[i]&&l1-c[i]+co[i]==l2) sum++;
		cout<<sum<<"\n";
	}
	return 0;
}
