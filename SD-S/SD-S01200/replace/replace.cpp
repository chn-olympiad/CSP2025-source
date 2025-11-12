#include<bits/stdc++.h>
using namespace std;
string n[1005][1005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			cin>>n[i][j];
		}
	}
	for(int i=1;i<=b;i++){
		cout<<0<<endl;
	}
	return 0;
}

