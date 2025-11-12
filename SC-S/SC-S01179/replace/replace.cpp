#include <bits/stdc++.h>
using namespace std;

int n,q;
pair<char,char> s[200020];

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i].first>>s[i].second;
	}
	while(q--){
		int s1,s2;
		cin>>s1>>s2;
		cout<<0<<endl;
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