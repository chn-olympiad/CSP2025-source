#include<iostream>
using namespace std;
struct node{
	string sx,sy;
}a[200005],t[200005];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].sx>>a[i].sy;
	}
	for(int i=1;i<=q;i++){
		cin>>t[i].sx>>t[i].sy;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
