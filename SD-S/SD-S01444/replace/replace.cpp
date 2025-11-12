#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map<string,string> M;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n,q,i;
	string a,b;
	cin>>n>>q;
	for(i = 1;i <= n;i++){
		cin>>a>>b;
		M[a] = b;
	}
	while(q--){
		cin>>a>>b;
		if(a.size() != b.size()) cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
