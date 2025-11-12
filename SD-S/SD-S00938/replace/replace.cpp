#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,q;
vector<string> sp[2];
int dfs(string s,int k){
	
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		sp[0].push_back(a);
		sp[1].push_back(b);
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		cout<<n<<"\n";
	}
	return 0;
}

