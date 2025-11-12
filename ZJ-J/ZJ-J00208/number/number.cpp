#include<bits/stdc++.h>
#define endl '\n'
#define QwQ return 0;
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
vector<char> g;
int main(){
	IOSO
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			g.push_back(s[i]);
		}
	}
	sort(g.begin(),g.end(),greater<int>() );
	for(int i=0;i<(int)g.size();i++){
		cout<<g[i];
	}
	QwQ;
}
