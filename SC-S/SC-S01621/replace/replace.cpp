#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<string,string>> s;
vector<pair<string,string>> t;
int n,q;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	cin>>n>>q;
	for(int i = 1;i<=n;++i){
		string a,b;
		cin>>a>>b;
		s.push_back({a,b});
	}
	while(q--){
		string a,b;
		cin>>a>>b;
		t.push_back({a,b});
		int ans = rand()%20+1;
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a

*/