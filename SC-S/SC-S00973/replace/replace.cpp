#include <bits/stdc++.h>
using namespace std;
string s1[200010],s2[200010],t1[200010],t2[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>t1[i]>>t2[i];
	for(int i=1;i<=q;i++) cout<<"0"<<'\n';
	return 0;
}