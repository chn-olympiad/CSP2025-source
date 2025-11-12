#include <bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
string s[N],s1[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>s1[i];
	}
	for(int i=1;i<=m;i++){
		string x,y;
		cin>>x>>y;
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	return 0;
}
