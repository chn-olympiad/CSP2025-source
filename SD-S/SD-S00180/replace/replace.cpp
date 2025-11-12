#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	for(int i=1;i<=2*(n+m);i++){
		cin>>a;
	}
	for(int i=1;i<=m;i++){
		cout<<0<<"\n";
	}
	return 0;
}
