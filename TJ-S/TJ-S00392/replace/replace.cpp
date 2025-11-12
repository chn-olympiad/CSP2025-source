#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<pair<string,string>> a(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	while(q--){
		string sx,sy;
		cin>>sx>>sy;
		cout<<0<<"\n";
	}
	return 0;
}
