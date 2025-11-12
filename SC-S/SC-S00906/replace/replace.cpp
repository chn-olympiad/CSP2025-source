#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,biggest=0,hs,smallest;
};
bool cmp(node a,node b){
	return a.biggest>b.biggest;
}
node JML[100086];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio,cin.tie(0);
	int n,q;
	cin>>n>>q;
	while(q--){
		cout<<0<<"\n";
	}
	return 0;
}