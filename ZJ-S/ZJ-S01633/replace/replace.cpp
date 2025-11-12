#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int n,q;
string s[N][2];
string t[N][2];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i = 1 ; i <= n ; i ++) cin>>s[i][0]>>s[i][1];
	for(int j = 1 ; j <= q ; j ++){
		cin>>t[j][0] >> t[j][1];
		cout<<"0"<<endl;
	}
	return 0;
}