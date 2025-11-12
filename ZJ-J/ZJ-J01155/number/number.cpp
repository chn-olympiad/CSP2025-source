#include<bits/stdc++.h>
using namespace std;
string s;
vector<long long>g;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;s[i];i++){
		if(isdigit(s[i])){
			long long x=s[i]-'0';
			g.push_back(x);
		}
	}
	sort(g.begin(),g.end(),greater<long long>());
	for(auto i:g)printf("%lld",i);
	return 0;
}
