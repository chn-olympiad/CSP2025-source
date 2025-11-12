#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
string cut(int p1,int p2,string s) {
	string ct;
	for(int i=p1; i<p2; i++)
		ct+=s[i];
	return ct;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s1[i]>>s2[i];
	while(q--) {
		int ans=0;
		string q1,q2;
		cin>>q1>>q2;
		for(long unsigned int i=0; i<=q1.size(); i++) {
			for(long unsigned int j=i; j<=q1.size(); j++) {
				for(int k=1; k<=n; k++) {
					if(s1[k].size()==j-i) {
						//cout<<"i/j/k:"<<i<<" "<<j<<" "<<k<<endl;
						string x,y,z,ne;
						y=cut(i,j,q1);
						if(y!=s1[k]) {
							//	cout<<"y!=s1"<<endl;
							continue;
						}
						x=cut(0,i,q1);
						z=cut(j,q1.size(),q1);
						ne=x+s2[k]+z;
						//cout<<"x/z/s1[k]/s2[k]:"<<x<<" / "<<z<<" / "<<s1[k]<<" / "<<s2[k]<<endl;
						//cout<<"q1/ne/q2:"<<q1<<" "<<ne<<" "<<q2<<endl;
						if(ne==q2) {
							//cout<<"			true"<<endl;
							ans++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
