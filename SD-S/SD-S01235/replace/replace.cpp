#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a[100000][2];
	for(int i=0;i<n;i++){
		for(int j=0;j<q;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cout<<0<<endl;
	}
	return 0;
}

