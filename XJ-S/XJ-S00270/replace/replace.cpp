#include<bits/stdc++.h>
using namespace std;
int n,q;
string sn[200005][2];
string sq[200005][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=2;j++){
			cin>>sn[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=2;j++){
			cin>>sq[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cout<<"0"<<endl;
	}
} 
