//SN-J00620 杨昕然 西安高新第一中学  
#include<bits/stdc++.h>
using namespace std;
string s;
vector<long long> v;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0; i<s.length(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}
	stable_sort(v.begin(),v.end());
	for(long long i=v.size()-1; i>=0; i--)cout<<v[i];
	return 0;
}

/*
1.
aa00aa1
ans:
100

longlong

1.tanxin
*/
