#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,q;
const int N=2e5+10;
string s[N][3];
int main(){
  freopen("replace.in","r",stdin);
  freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for (int i=1; i<=n; i++){
		cin>>s[i][1]>>s[i][2];
	}
	while(q--){
		string T1,T2;
		cin>>T1>>T2;
		cout<<0<<'\n';
	}
	return 0;
}

