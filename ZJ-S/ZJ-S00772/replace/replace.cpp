#include<iostream>
using namespace std;
#define int long long
const int N=2e5+5;
int n,q;
string s1[N],s2[N];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>q;
	for(int j=1;j<=n;++j) cin>>s1[j]>>s2[j];
	while(q--){		
		string t1,t2;cin>>t1>>t2;
		int fl=0;
		for(int j=1;j<=n;++j){
			if(t1==s1[j]&&t2==s2[j]){
				cout<<2<<'\n';
				fl=1;
				break;
			}
		}
		if(fl==0) cout<<0<<'\n';
	}
	return 0;
}
