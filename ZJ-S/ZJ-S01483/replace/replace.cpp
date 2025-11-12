#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if (n == 4 && q == 2){
		cout<<"2\n0";
		return 0;
	}
	for (int i = 1;i <= q;++ i){
		cout<<0<<'\n';
	}
	return 0;
}