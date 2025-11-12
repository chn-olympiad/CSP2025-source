#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
	}
	for(int i=1;i<=q;i++){
		cin>>a>>b;
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
	return 0;
}
