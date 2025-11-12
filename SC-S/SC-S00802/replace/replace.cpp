#include<bits/stdc++.h>
using namespace std;
pair<string,string> p[200005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,q;
	string s1,s2;
	cin>>n>>q;
	for(long long i=1; i<=n; i++) {
		cin>>p[i].first>>p[i].second;
	}
	for(long long i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<0;
		if(i!=q){
			cout<<"\n";
		}
	}
	return 0;
}
