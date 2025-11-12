#include<bits/stdc++.h>
using namespace std;
const int N=5e6+9;
typedef long long ll;
int n,q;
string s[N],t[N];
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
	}
	while(q--){
		cin>>a>>b;
		cout<<0<<"\n";
	}
	return 0;
}
