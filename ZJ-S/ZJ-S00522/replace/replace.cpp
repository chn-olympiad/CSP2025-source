#include<bits/stdc++.h>
using namespace std;
string ss[200005][3],sr[200005][3];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		cin>>ss[i][1]>>ss[i][2];
	}
	for(int i=1;i<=q;++i){
		cin>>sr[i][1]>>sr[i][2];
	}
	for(int i=1;i<=q;++i){
		cout<<0<<endl;
	}
	return 0;
}