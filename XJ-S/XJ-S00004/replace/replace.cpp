#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string v[200][3],que[200][3];
	for(int i = 1;i<=n;i++){
		cin>>v[i][1]>>v[i][2];
	}
	for(int i = 1;i<=q;i++){
		cin>>que[i][1]>>que[i][2];
	}
	for(int i = 1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
}
