#include <iostream>
using namespace std;
const int N=2e5+10;
struct node{
	string s1,s2;
}s[N];
int n,q;
string t1,t2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i].s1>>s[i].s2;
	while(q--){
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) cout<<0<<"\n";
		else cout<<n<<"\n";
	}
	return 0;
}
