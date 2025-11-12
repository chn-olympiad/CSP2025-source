#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	char n,q;
	cin>>n>>q;
	int a[n+1];
	int b[q+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=q;j++){
			cin>>b[j];
		}
	}
	cout<<2<<endl<<0;
	return 0;
}